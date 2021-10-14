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

#ifndef LIBRETRO_CORE_H
#define LIBRETRO_CORE_H

#include <libretro.h>
#include <string>

namespace retro {
    using namespace std;

    class Core {
    public:
        void (*retro_init)(void);

        void (*retro_deinit)(void);

        unsigned (*retro_api_version)(void);

        void (*retro_get_system_info)(struct retro_system_info *);

        void (*retro_get_system_av_info)(struct retro_system_av_info *);

        void (*retro_set_environment)(retro_environment_t);

        void (*retro_set_video_refresh)(retro_video_refresh_t);

        void (*retro_set_audio_sample)(retro_audio_sample_t);

        void (*retro_set_audio_sample_batch)(retro_audio_sample_batch_t);

        void (*retro_set_input_poll)(retro_input_poll_t);

        void (*retro_set_input_state)(retro_input_state_t);

        void (*retro_set_controller_port_device)(unsigned, unsigned);

        void (*retro_reset)(void);

        void (*retro_run)(void);

        size_t (*retro_serialize_size)(void);

        bool (*retro_serialize)(void *, size_t);

        bool (*retro_unserialize)(const void *, size_t);

        void (*retro_cheat_reset)(void);

        void (*retro_cheat_set)(unsigned, bool, const char *);

        bool (*retro_load_game)(const struct retro_game_info *);

        bool (*retro_load_game_special)(unsigned,
                                        const struct retro_game_info *, size_t);

        void (*retro_unload_game)(void);

        unsigned (*retro_get_region)(void);

        void *(*retro_get_memory_data)(unsigned);

        size_t (*retro_get_memory_size)(unsigned);

        unsigned poll_type;
        bool inited;
        bool symbols_inited;
        bool game_loaded;
        bool input_polled;
        bool has_set_subsystems;
        bool has_set_input_descriptors;

        Core(const std::string &soCorePath);

        ~Core();

    private:
        void *coreHandle = nullptr;

        void open(const std::string &corePath);
        void close();
    };

}

#endif //LIBRETRO_CORE_H
