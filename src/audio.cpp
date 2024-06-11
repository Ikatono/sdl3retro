#include "audio.hpp"
#include <cmath>

namespace Audio
{
    static SDL_AudioStream* stream;
    static SDL_AudioSpec putSpec
    {
        .format = SDL_AUDIO_S16,
        .channels = 2,
    };
    int init()
    {
        return 0;
    }
    long unsigned int put_data(const int16_t* samples, size_t numFrames)
    {
        return SDL_PutAudioStreamData(stream, samples, numFrames * 4);
    }
    //call after loading a core
    //must have a valid core
    int coreInit()
    {
        const auto* core = Core::getCore();
        retro_system_av_info avinfo;
        core->retro_get_system_av_info(&avinfo);
        putSpec.freq = std::lround(avinfo.timing.sample_rate);
        stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_OUTPUT, &putSpec, nullptr, nullptr);
        core->retro_set_audio_sample_batch(&put_data);
        return 0;
    }
    int coreDeinit()
    {
        if (stream)
            SDL_DestroyAudioStream(stream);
        stream = nullptr;
        return 0;
    }
}
