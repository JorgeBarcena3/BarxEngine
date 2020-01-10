// File: BAudio.hpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include "BtypeDef.hpp"
#include <SDL_mixer.h>


/*
 * Maneja el audio del motor
 */
class BAudio
{

public:

	struct BAudioInfo
	{
		Mix_Music* music = nullptr;
		Mix_Chunk* sound = nullptr;
		int channel = -1;

		BAudioInfo(Mix_Music* _music)
		{
			music = _music;
		};

		BAudioInfo(Mix_Chunk* _sound)
		{
			sound = _sound;
		};
	};

private:

	map<Id, BAudioInfo* > music;
	map<Id, BAudioInfo* > sounds;

public:

	/*
	* Adapta un path en funcion de la version que ejecutamos
	*/
	string setRelativePath(const char* _path) {

#if _DEBUG 
		string relativePath = "..\\..\\";
#else
		string relativePath = "..\\..\\";
#endif
		string path = _path;

		relativePath.append(path);

		return relativePath;
	}

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
			Mix_FreeMusic(outer->second->music);
		}

		for (auto outer = sounds.begin(); outer != sounds.end(); ++outer)
		{
			Mix_FreeChunk(outer->second->sound);
		}

		Mix_CloseAudio();
	};

	/*
	* Carga una musica y devuelve su Id
	* Busca la ruta desde la carpeta de creacion del proyecto
	*/
	Id loadMusic(const char* path) {

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

	/*
	* Carga una sonido y devuelve su Id
	* Busca la ruta desde la carpeta de creacion del proyecto
	*/
	int loadSound(const char* path) {

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

	/*
	* Comienza una musica
	* Devuelve el canal donde se está ejecutando
	*/
	int startMusic(Id id)
	{
		return  music[id]->channel = Mix_FadeInMusic(music[id]->music, -1, 1000);
	}


	/*
	* Comienza un sonido
	* Devuelve el canal donde se está ejecutando
	*/
	int makeSound(Id id)
	{
		return sounds[id]->channel = Mix_PlayChannel(-1, sounds[id]->sound, 0);
	}

	/*
	* Para toda la musica
	*/
	void stopAllMusic()
	{
		Mix_HaltMusic();
	}

	/*
	* Para una musica segun el id
	*/
	void stopMusicId(Id id)
	{
		Mix_HaltChannel(music[id]->channel);
	}

	/*
	*  Para todos los sonidos
	*/
	void stopAllSounds() {

		Mix_HaltChannel(-1);
	}

	/*
	*  Para un sonido en concreto
	*/
	void stopChanelId(Id id) {

		Mix_HaltChannel(music[id]->channel);
	}

	/*
	*  Para una musica en concreto
	*/
	void setMusicVolume(Id id, int volume) {

		int finalVolume = volume > 128 ? 128 : volume < 0 ? 0 : volume;
		Mix_Volume(music[id] ->channel, finalVolume);
	}

	/*
	*  Para un sonido en concreto
	*/
	void setSoundVolume(Id id, int volume) {

		int finalVolume = volume > 128 ? 128 : volume < 0 ? 0 : volume;
		Mix_Volume(sounds[id]->channel, finalVolume);
	}

};


