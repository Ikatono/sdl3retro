#include "core.hpp"

#include <SDL3/SDL_loadso.h>


#include <iostream>

//try to load libretro api function from core
#define LOAD(api) core. api = reinterpret_cast<decltype(CoreLinks:: api)>(SDL_LoadFunction(coreObj, #api))
//fail with message if api function not found
#define MUST(api) do { if (!(LOAD(api))) { std::cerr << "Error loading " << #api << std::endl; return -1; } } while (false)

namespace Core
{
    static CoreLinks core;
    const CoreLinks* getCore()
    {
        return &core;
    }
    void CoreLinks::clear()
    {
        *this = {};
    }
    int load(const char* name)
    {
        static decltype(SDL_LoadObject(nullptr)) coreObj;
        core.clear();
        if (coreObj)
            SDL_UnloadObject(coreObj);
        coreObj = SDL_LoadObject(name);
        MUST(retro_api_version);
        MUST(retro_get_system_info);
        MUST(retro_get_system_av_info);
        MUST(retro_load_game);
        MUST(retro_unload_game);
        MUST(retro_set_audio_sample_batch);
        MUST(retro_set_input_poll);
        MUST(retro_set_input_state);
        MUST(retro_set_environment);
        MUST(retro_init);
        MUST(retro_run);
        return 0;
    }
}

#ifdef LOAD
#undef LOAD
#endif //LOAD
#ifdef MUST
#undef MUST
#endif //MUST
