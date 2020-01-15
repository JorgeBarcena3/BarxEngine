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

typedef struct _Mix_Music Mix_Music;
struct Mix_Chunk;

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
    BAudio();

	/*
	* Destruye todos los archivos de musica que hemos cargado con anterioridad
	*/
    ~BAudio();

	/*
	* Carga una musica y devuelve su Id
	* Busca la ruta desde la carpeta de creacion del proyecto
	*/
    Id loadMusic(const char* path);

	/*
	* Carga una sonido y devuelve su Id
	* Busca la ruta desde la carpeta de creacion del proyecto
	*/
    int loadSound(const char* path);

	/*
	* Comienza una musica
	* Devuelve el canal donde se está ejecutando
	*/
    int startMusic(Id id);


	/*
	* Comienza un sonido
	* Devuelve el canal donde se está ejecutando
	*/
    int makeSound(Id id);

	/*
	* Para toda la musica
	*/
    void stopAllMusic();

	/*
	* Para una musica segun el id
	*/
    void stopMusicId(Id id);

	/*
	*  Para todos los sonidos
	*/
    void stopAllSounds();

	/*
	*  Para un sonido en concreto
	*/
    void stopChanelId(Id id);

	/*
	*  Para una musica en concreto
	*/
    void setMusicVolume(Id id, int volume);

	/*
	*  Para un sonido en concreto
	*/
    void setSoundVolume(Id id, int volume);

};


