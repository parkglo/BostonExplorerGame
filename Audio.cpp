#include "Audio.h"
#include <SFML\Audio.hpp>



Audio::Audio(bool load_everything, bool menu)
{
	if (load_everything)
	{
		loadMusic(menu);
		loadSounds();
	}
}

Audio::~Audio()
{
	this->music.stop();
	for (size_t i = 0; i < COUNT; i++)
	{
		buffer[i].stop();
	}
}

bool Audio::loadMusic(bool menu)
{
	string path;
	if (menu)
		path = "Data/menu.ogg";
	else
		path = "Data/game.ogg";

	if(!music.openFromFile(path))
		return false;
	music.setLoop(true);
	music.setVolume(50);
	return true;
}

bool Audio::loadSounds()
{
	string name[COUNT] = {"pickup.wav", "game_over.wav", "level_over.wav", "level_completed.ogg"};
	for (size_t i = 0; i < COUNT; i++)
	{
		if (!buffer[i].openFromFile("Data/" + name[i]))
		{
			buffer[i].setLoop(false);
			return false;
		}
	}
	return true;
}

void Audio::playMusic()
{
	music.play();
}

void Audio::stopMusic()
{
	music.stop();
}

void Audio::playSound(SoundType type)
{
	buffer[type].play();
}

void Audio::stopSound(SoundType type)
{
	buffer[type].stop();
}

void Audio::setVolume(bool mute)
{
	if (mute)
	{
		music.stop();
		for (size_t i = 0; i < COUNT; i++)
		{
			buffer[i].setVolume(0);
		}
	}
	else
	{
		music.play();
		for (size_t i = 0; i < COUNT; i++)
		{
			buffer[i].setVolume(100);
		}
	}
}
