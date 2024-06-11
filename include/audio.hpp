#ifndef H_58C3332E624E4E94AEBF0D4F5A08CC0A
#define H_58C3332E624E4E94AEBF0D4F5A08CC0A

#include "libretro.h"
#include <SDL3/SDL_audio.h>

#include "core.hpp"

namespace Audio
{
    int init();
    int coreInit();
    int coreDeinit();
}


#endif //H_58C3332E624E4E94AEBF0D4F5A08CC0A