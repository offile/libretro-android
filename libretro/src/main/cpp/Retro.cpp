#include "Retro.h"

using retro::Retro;
using namespace std::placeholders

Retro::Retro() = default;

Retro::~Retro() = default;

void Retro::loadCore(string &corePath) {
    if(core){
        unLoadCore();
    }
    core = make_unique<Core>(corePath);

    auto ff = &Retro::callback_video_refresh;

    retro_video_refresh_t tt = [](const void *data, unsigned width,unsigned height, size_t pitch) mutable {
        ff;
    }
    retro_video_refresh_t gg = std::mem_fn(&Retro::callback_video_refresh);
    auto func = std::bind(ff, this, _1, _2, _3, _4);
    core->retro_set_video_refresh(tt);
}

void Retro::unLoadCore() {
    if(core){
        core->retro_deinit();
        core = nullptr;
    }
}

void Retro::loadRom(string &romPath) {
    retro_game_info info = {};
    info.path = romPath.c_str();
    core->retro_load_game(&info);
}

void Retro::unLoadRom() {
    core->retro_unload_game();
}

void Retro::start() {

}
