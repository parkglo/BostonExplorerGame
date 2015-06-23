#include "Game.h"

//Simple SFML Game
//Copyright Dominik "b00sti" Pawlik

int WINAPI WinMain(HINSTANCE   hInstance,    
	HINSTANCE    hPrevInstance,     
	LPSTR        lpCmdLine,          
	int          nCmdShow)
{
	Game game;
	game.runGame();

	return EXIT_SUCCESS;
}
