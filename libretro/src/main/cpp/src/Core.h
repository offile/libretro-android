//
// Created by bird on 17/8/21.
//

#ifndef LIBRETRO_ANDROID_CORE_H
#define LIBRETRO_ANDROID_CORE_H

namespace Retro {

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
    };

}

#endif //LIBRETRO_ANDROID_CORE_H
