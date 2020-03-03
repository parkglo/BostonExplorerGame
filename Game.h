#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include <iostream>


using namespace std;
using namespace sf;

class Game
{
	public:

		Game(void);
		~Game();
		Audio audio;

		void runGame();

	//protected:

		enum  GameState {MENU, GAME, GAME_OVER,ABOUT, END};
		GameState state;

	//private:

		Font font;
		bool fullScrean;

		void game_over(Staty::GameStatistics &gameStatistics);
		void menu();
		void about();
		void single(Staty::GameStatistics &gameStatistics);

};
