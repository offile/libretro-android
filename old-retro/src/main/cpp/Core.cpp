/**
 *     Copyright (C) 2021  clovero
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Core.h"
#include <dlfcn.h>

#include <cstdlib>

using namespace std;
using retro::Core;

void* get_symbol(void* handle, const char* symbol) {
    void* result = dlsym(handle, symbol);
    if (!result) {
        string error("Missing libretro core symbol: ", symbol);
        throw std::runtime_error(error);
    }
    return result;
}

#define load_symbol(HANDLE,V, SYMBOL) do {\
    *(void**)&V = get_symbol(HANDLE, SYMBOL); \
  } while (0)

#define load_retro_symbol(S) load_symbol(coreHandle, S, #S)

Core::Core(const std::string &corePath) {
    open(corePath);
}

Core::~Core() {
    close();
}

void Core::open(const string &corePath) {
    coreHandle = dlopen(corePath.c_str(), RTLD_LOCAL | RTLD_LAZY);
    if(!coreHandle) {
        throw std::runtime_error(dlerror());
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
        dlclose(coreHandle);
        coreHandle = nullptr;
    }
}