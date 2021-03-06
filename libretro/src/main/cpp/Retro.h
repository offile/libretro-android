#ifndef LIBRETRO_ANDROID_RETRO_H
#define LIBRETRO_ANDROID_RETRO_H

#include "Core.h"
#include <string>

using namespace std;

namespace retro {

    class Retro {
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

        void callback_video_refresh(
                const void *data,
                unsigned width,
                unsigned height,
                size_t pitch);
    };

}

#endif //LIBRETRO_ANDROID_RETRO_H
