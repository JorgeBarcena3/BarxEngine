#include "..\headers\BAudio.hpp"
#include <SDL.h>
#include <SDL_mixer.h>

BAudio::BAudio()
{

    int flags = MIX_INIT_OGG | MIX_INIT_MOD;

    // start SDL with audio support
    if (SDL_Init(flags) == -1) {
        printf("SDL_Init: %s\n", SDL_GetError());
        exit(1);
    }

    // open 44.1KHz, signed 16bit, renderTask byte order,
    //      stereo audio, using 1024 byte chunks
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(2);
    }

}
BAudio::~BAudio()
{

    for (auto outer = music.begin(); outer != music.end(); ++outer)
    {
        Mix_FreeMusic(outer->second->music);
    }

    for (auto outer = sounds.begin(); outer != sounds.end(); ++outer)
    {
        Mix_FreeChunk(outer->second->sound);
    }

    Mix_CloseAudio();
}
Id BAudio::loadMusic(const char* path)
{

    Mix_Music* _music;

    if (_music = Mix_LoadMUS(setRelativePath(path).c_str()))
    {
        Id id;

        if (music.empty())
        {
            id = 0;
        }
        else
            id = (--music.end())->first + 1;

        music[id] = new BAudioInfo(_music);
        return id;
    }

    auto error = Mix_GetError();
    return -1;
}
int BAudio::loadSound(const char* path)
{

    Mix_Chunk* _sound;

    if (_sound = Mix_LoadWAV(setRelativePath(path).c_str()))
    {
        Id id;

        if (sounds.empty())
        {
            id = 0;
        }
        else
            id = (--sounds.end())->first + 1;

        sounds[id] = new BAudioInfo(_sound);
        return id;
    }

    auto error = Mix_GetError();
    return -1;

}

int BAudio::startMusic(Id id)
{
    return  music[id]->channel = Mix_FadeInMusic(music[id]->music, -1, 1000);
}

int BAudio::makeSound(Id id)

{
    return sounds[id]->channel = Mix_PlayChannel(-1, sounds[id]->sound, 0);
}

void BAudio::stopAllMusic()

{
    Mix_HaltMusic();
}

void BAudio::stopMusicId(Id id)
{
    Mix_HaltChannel(music[id]->channel);
}

void BAudio::stopAllSounds()
{

    Mix_HaltChannel(-1);
}

void BAudio::stopChanelId(Id id)
{

    Mix_HaltChannel(music[id]->channel);
}


void BAudio::setMusicVolume(Id id, int volume)
{

    int finalVolume = volume > 128 ? 128 : volume < 0 ? 0 : volume;
    Mix_Volume(music[id]->channel, finalVolume);
}

void BAudio::setSoundVolume(Id id, int volume)
{

    int finalVolume = volume > 128 ? 128 : volume < 0 ? 0 : volume;
    Mix_Volume(sounds[id]->channel, finalVolume);
}