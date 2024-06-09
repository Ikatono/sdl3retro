#include "core.hpp"

#if defined(__linux__)
#include <dlfcn.h>
#endif //defined(__linux__)

#include <iostream>

namespace Core
{
    static CoreLinks core;
    const CoreLinks* getCore()
    {
        return &core;
    }
    int load(const char* name)
    {
        #if defined(__linux__)
        static decltype(dlopen(nullptr, RTLD_LAZY)) dll;
        if (dll)
            dlclose(dll);
        dll = dlopen(name, RTLD_LAZY);
        if (!dll)
        {
            std::cerr << dlerror() << std::endl;
            return -2;
        }
        core.retro_api_version = reinterpret_cast<decltype(&retro_api_version)>(dlsym(dll, "retro_api_version"));
        const auto error = dlerror();
        if (error)
        {
            std::cout << error << std::endl;
            return -3;
        }
        // dlclose(dll);
        #endif //defined(__linux__)
        if (!core.retro_api_version)
            return -1;
        return 0;
    }
}
