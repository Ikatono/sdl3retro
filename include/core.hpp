#ifndef H_69E14F9F85D74F1FB3C3F5FD42C4BCFA
#define H_69E14F9F85D74F1FB3C3F5FD42C4BCFA

#include "libretro.h"
#include <type_traits>

//adds a function pointer member matching the api function
#define MEMBER(api) decltype(&:: api) api;

namespace Core
{
    struct CoreLinks
    {
        // using UnsignedVoid = std::add_pointer_t<unsigned()>;
        public:
            MEMBER(retro_api_version);
            MEMBER(retro_get_system_info);
            MEMBER(retro_get_system_av_info);
            MEMBER(retro_load_game);
            MEMBER(retro_unload_game);
            MEMBER(retro_set_audio_sample_batch);
            MEMBER(retro_set_input_poll);
            MEMBER(retro_set_input_state);
            MEMBER(retro_set_environment);
            MEMBER(retro_init);
            MEMBER(retro_run);
            void clear();
    };
    const CoreLinks* getCore();
    int load(const char* name);
}

#ifdef MEMBER
#undef MEMBER
#endif //MEMBER

#endif //H_69E14F9F85D74F1FB3C3F5FD42C4BCFA