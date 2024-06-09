#include "input.hpp"

#include <SDL3/SDL_init.h>

namespace Input
{
    int init()
    {
        return SDL_InitSubSystem(SDL_INIT_GAMEPAD);
    }
}
