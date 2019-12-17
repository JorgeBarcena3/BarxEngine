#pragma once

#include "BtypeDef.hpp"
#include <SDL.h>
#include <ciso646>
#include <SDL_mixer.h>
#include <fstream>      // std::fstream


/*
 * Maneja el audio del motor
 */
class BAudio
{

private:

    map<Id, Mix_Music* > music;
    map<Id, Mix_Chunk* > sounds;

public:

    /*
    * Contructor del audio
    */
    BAudio()
    {
        int flags = MIX_INIT_OGG | MIX_INIT_MOD;

        // start SDL with audio support
        if (SDL_Init(flags) == -1) {
            printf("SDL_Init: %s\n", SDL_GetError());
            exit(1);
        }
        // open 44.1KHz, signed 16bit, system byte order,
        //      stereo audio, using 1024 byte chunks
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
            printf("Mix_OpenAudio: %s\n", Mix_GetError());
            exit(2);
        }

    };

    /*
    * Destruye todos los archivos de musica que hemos cargado con anterioridad
    */
    ~BAudio() {

        for (auto outer = music.begin(); outer != music.end(); ++outer)
        {
            Mix_FreeMusic(outer->second);
        }

        for (auto outer = sounds.begin(); outer != sounds.end(); ++outer)
        {
            Mix_FreeChunk(outer->second);
        }

        Mix_CloseAudio();
    };

    /*
    * Carga una musica y devuelve su Id
    */
    Id loadMusic(const char* path) {

      

        Mix_Music* _music;
        auto aa = Mix_LoadWAV(path);
        auto error = Mix_GetError();

        if (_music = Mix_LoadMUS(path))
        {
            Id id = music.end()->first + 1;
            music[id] = (_music);
            return id;
        }

        return -1;
    }

    /*
    * Carga una sonido y devuelve su Id
    */
    int loadSound(const char* path) {

        Mix_Chunk* _sound;

        if (_sound = Mix_LoadWAV(path))
        {
            Id id = sounds.end()->first + 1;
            sounds[sounds.end()->first + 1] = (_sound);
            return id;
        }

        return -1;
    }

    /*
    * Comienza una musica
    */
    void startMusic(Id id)
    {

        Mix_FadeInMusic(music[id], -1, 1000);

    }


    /*
    * Comienza un sonido
    */
    void makeSound(Id id)
    {
        Mix_PlayChannel(-1, sounds[id], 0);
    }

    /*
    * Para toda la musica
    */
    void stopAllMusic()
    {
        Mix_HaltMusic();
    }

    /*
    *  Para todos los sonidos
    */
    void stopAllSounds() {
        Mix_HaltChannel(-1);
    }

};


