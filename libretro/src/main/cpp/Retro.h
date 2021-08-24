#ifndef LIBRETRO_ANDROID_RETRO_H
#define LIBRETRO_ANDROID_RETRO_H

#include "Core.h"
#include <string>

using namespace std;
using namespace retro;

namespace retro {

class Retro{
    public:
        Retro();
        ~Retro();

        void loadCore(string &corePath);
        void unLoadCore();
        void loadRom(string &romPath);
        void unLoadRom();
        void start();

    private:
        unique_ptr<Core> core;
};

}

#endif //LIBRETRO_ANDROID_RETRO_H
