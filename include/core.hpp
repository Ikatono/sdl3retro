#ifndef H_69E14F9F85D74F1FB3C3F5FD42C4BCFA
#define H_69E14F9F85D74F1FB3C3F5FD42C4BCFA

#include "libretro.h"
#include <type_traits>

namespace Core
{
    struct CoreLinks
    {
        // using UnsignedVoid = std::add_pointer_t<unsigned()>;
        public:
            decltype(&::retro_api_version) retro_api_version;
    };
    const CoreLinks* getCore();
    int load(const char* name);
}

#endif //H_69E14F9F85D74F1FB3C3F5FD42C4BCFA