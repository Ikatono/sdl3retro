#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_assert.h>
#include "libretro.h"

#include "input.hpp"
#include "core.hpp"

#include <iostream>
#include <vector>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

std::vector<Input::InputEvent> inputs;

int SDL_AppInit(void **appstate, int argc, char **argv)
{
    // std::cout << "app init" << std::endl;
    SDL_assert(argc == 1 || argc == 2);
    const auto& coreName = argv[1];
    auto ret = Core::load(coreName);
    if (ret)
    {
        std::cout << "failed to load core: " << coreName << " code: " << ret << std::endl;
        return SDL_APP_FAILURE;
    }
    std::cout << "loaded core: " << coreName << std::endl;
    const auto core = Core::getCore();
    SDL_assert(core);
    SDL_assert(core->retro_api_version);
    std::cout << "looks good" << std::endl;
    std::cout << core->retro_api_version() << std::endl;
    return SDL_APP_SUCCESS;
    return SDL_APP_CONTINUE;
}

int SDL_AppIterate(void *appstate)
{
    for (const auto& input : inputs)
    {
        std::visit(overloaded{
            [](Input::ButtonInput inp) -> void
            {

            },
            [](Input::StickInput inp) -> void
            {

            }
    }, input);
    }
    inputs.clear();
    return SDL_APP_CONTINUE;
}

int SDL_AppEvent(void *appstate, const SDL_Event *event)
{

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate)
{
    // std::cout << "app quit" << std::endl;
}
