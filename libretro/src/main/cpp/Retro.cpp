#include "Retro.h"

using retro::Retro;

Retro::Retro() {

}

Retro::~Retro() {

}

void Retro::loadCore(string &corePath) {
    core = make_unique<Core>(corePath);
}

void Retro::unLoadCore() {

}
