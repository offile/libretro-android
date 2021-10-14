#include "Retro.h"

using retro::Retro;

Retro::Retro() = default;

Retro::~Retro() = default;

void Retro::loadCore(string &corePath) {
    core = make_unique<Core>(corePath);
}

void Retro::unLoadCore() {
    core = nullptr;
}

void Retro::loadRom(string &romPath) {
    retro_game_info info = {};
    info.path = romPath.c_str();
    core->retro_load_game(&info);
}

void Retro::unLoadRom() {

}

void Retro::start() {

}
