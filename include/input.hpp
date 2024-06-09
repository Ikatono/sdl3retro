#ifndef H_A1E40AB5368F491A81BE61189030FC74
#define H_A1E40AB5368F491A81BE61189030FC74

#include "libretro.h"

#include <variant>

namespace Input
{
    enum class InputType
    {
        Pressed,
        Released,

    };
    struct ButtonInput
    {
        InputType type;
        int button;
    };
    struct StickInput
    {

    };
    using InputEvent = std::variant<ButtonInput, StickInput>;
    int init();
}

#endif //H_A1E40AB5368F491A81BE61189030FC74
