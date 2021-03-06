#include "Core.h"
#include <dynamic/dylib.h>
#include <string>

using retro::Core;

function_t get_symbol(dylib_t handle, const char *symbol) {
    function_t result = dylib_proc(handle, symbol);
    if (!result) {
        std::string error("Missing libretro core symbol: ", symbol);
        throw std::runtime_error(error);
    }
    return result;
}

#define load_symbol(HANDLE,V, SYMBOL) do { \
    function_t func = get_symbol(HANDLE, SYMBOL);\
    memcpy(&V, &func, sizeof(func));\
  } while (0)

#define load_retro_symbol(S) load_symbol(coreHandle, S, #S)

void Core::open(const std::string &corePath) {
    coreHandle = dylib_load(corePath.c_str());
    if(!coreHandle) {
        throw std::runtime_error(dylib_error());
    }
    try {
        load_retro_symbol(retro_init);
        load_retro_symbol(retro_deinit);
        load_retro_symbol(retro_api_version);
        load_retro_symbol(retro_get_system_info);
        load_retro_symbol(retro_get_system_av_info);
        load_retro_symbol(retro_set_environment);
        load_retro_symbol(retro_set_video_refresh);
        load_retro_symbol(retro_set_audio_sample);
        load_retro_symbol(retro_set_audio_sample_batch);
        load_retro_symbol(retro_set_input_poll);
        load_retro_symbol(retro_set_input_state);
        load_retro_symbol(retro_set_controller_port_device);
        load_retro_symbol(retro_reset);
        load_retro_symbol(retro_run);
        load_retro_symbol(retro_serialize_size);
        load_retro_symbol(retro_serialize);
        load_retro_symbol(retro_unserialize);
        load_retro_symbol(retro_cheat_reset);
        load_retro_symbol(retro_cheat_set);
        load_retro_symbol(retro_load_game);
        load_retro_symbol(retro_load_game_special);
        load_retro_symbol(retro_unload_game);
        load_retro_symbol(retro_get_region);
        load_retro_symbol(retro_get_memory_data);
        load_retro_symbol(retro_get_memory_size);
    }catch (std::runtime_error &e){
        close();
        throw e;
    }
}

void Core::close() {
    if (coreHandle) {
        dylib_close(coreHandle);
        coreHandle = nullptr;
    }
}

Core::Core(const std::string &corePath) {
    open(corePath);
}

Core::~Core() {
    close();
}
