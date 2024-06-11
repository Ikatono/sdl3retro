#ifndef H_FAF4409B9CB64DB69008BFA25158639F
#define H_FAF4409B9CB64DB69008BFA25158639F

#include "input.hpp"
#include "libretro.h"

namespace Input
{
    class Gamepad
    {
        public:
            void poll();
        
        private:
            
    };
    int connectAllGamepads();
    void pollGamepads();
}

#endif //H_FAF4409B9CB64DB69008BFA25158639F