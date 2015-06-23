#pragma once
#include <SFML\Audio.hpp>
#include <string>

using namespace sf;
using namespace std;


class Audio
{
public:

	Audio(bool load_everything = false, bool menu = false);
	~Audio();

	enum SoundType { GAIN, GAME_OVER, LIFE_OVER,LEVEL_COMPLETED, COUNT};

	bool loadMusic(bool menu);
	bool loadSounds();

	void playMusic();
	void stopMusic();

	void playSound(SoundType sound);
	void stopSound(SoundType type);

	void setVolume(bool mute);

private:

	Music music;
	Music buffer[COUNT];
};
