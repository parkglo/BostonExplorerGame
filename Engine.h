#pragma once
#include "Player.h"
#include "Level.h"
#include "Food.h"
#include "Records.h"
#include "PointAnimation.h"
#include "Point.h"
#include "Audio.h"


using namespace std;
using namespace sf;

//game statistics
class Staty
{
public:

	struct GameStatistics
	{
		int points = 0;
		int lives = 3;
		int nrLevel = 1;
		int maxLevel = 15;
		int toNewLive = 50000;

		static const int howmanylevels = 30;
		Records tabWithRecords[howmanylevels];

		bool ifRecord[howmanylevels];
		bool ifGameRecord[3];
		bool flagsoundingame = false;

		Audio audio2;
	};

};

class Engine
{
	public:

		Engine(RenderWindow &win, Staty::GameStatistics &gameStatistics);
		~Engine( );

		void runEngine(RenderWindow &window,Staty::GameStatistics &gameStatistics);

		enum state2 { MENU_AGAIN, NEXT_LEVEL, LEVEL_AGAIN, NEXT, GAME_OVER, END };
		state2 GameState2;

	private:

		RectangleShape
			barsBackground,
			powerbar,
			underGameOver,
			underNewGameRecord;
		Text
			pointsString,
			livesString,
			levelString,
			tonextlevelString,	
			powerString,
			keycodeString,
			endlifeString,
			gameover1String,
			pauseString,
			pictureNextLevel,
			fullscreanString,
			newRecordString,
			newGameRecordString,
			newLife;
		Font font;

		static const int howmanyFood = 5;
		int to_new_level;
		int how_to_next_level;
		int maxLevel;
		float powerCapacity;
		float state2;
		float speed_powerbar;
		bool isPause;
		bool isEndLife;
		bool flagtogameover;
		bool flagtogameover2;
		bool flagtonextlevel;
		int tonextLevelpicture;
		int toCountdownPoints;
		int levelpoints;
		bool isNextLevel;
		bool fullScrean;
		bool flagtosaverecords;
		bool flagrecordpoints;
		bool ifgamerecord;
		bool flagtoanimationNewLife;
		bool flagtocompletelevel;

	
		Player player;
		Level level;
		Food tabFood[howmanyFood];
		PointAnimation pointAnimation;

		Texture texture[Level::COUNT];
		Sprite sprite[Level::height][Level::width];
		Clock clock;
		Clock pauseClock;
		Clock newLifeClock;
		Time pauseElapsedTime;
		Time pauseElapsedTimeInAllLevel;
		Shader blurEffect;


		void check_collision();
		void check_collision_withFood(Staty::GameStatistics &gameStatistics);
		void update_GUI(Staty::GameStatistics &gameStatistics);
		void processEvents(RenderWindow &window, Staty::GameStatistics &gameStatistics);
		void render(RenderWindow &window, Staty::GameStatistics &gameStatistics);
		float getPowerState(RenderWindow &window, Staty::GameStatistics &gameStatistics);
		void writing(int n_levelPoints, int n_setline);
		void update_records_file(const string path, string newLine, size_t werse);
		string getDate();
};
