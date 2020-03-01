#include "Game.h"

using namespace std;
using namespace sf;

RenderWindow window; 

Game::Game(void)
:fullScrean(false)

{
	srand(time(0));

	window.create(VideoMode(1280, 720), "Boston Explorer", Style::Fullscreen);

	state = END;

	if (!font.loadFromFile("Data/GoodDog.otf"))
	{
		MessageBox(NULL, "Font not found !", "ERROR", NULL);
		return;
	}

	audio.loadMusic(true);
	audio.loadSounds();
	audio.playMusic();

	state = MENU;
}

Game::~Game()
{
	audio.stopMusic();
}

//load appropriate state (MENU, GAME, GAME_OVER, END...)
void Game::runGame(){

	Staty::GameStatistics gameStatistics;

	for (size_t i = 0; i < gameStatistics.howmanylevels; i++)
	{
		gameStatistics.tabWithRecords[i].SetLinie(i);
		gameStatistics.tabWithRecords[i].loading();
	}

	for (size_t i = 0; i < gameStatistics.howmanylevels; i++)
	{
		gameStatistics.ifRecord[i] = false;
	}

	for (size_t i = 0; i < 3; i++)
	{
		gameStatistics.ifGameRecord[0] = false;
	}

	window.setFramerateLimit(65);

	while (state != END)
	{
		switch (state)
		{
		case Game::MENU:
			if (!gameStatistics.flagsoundingame)
			{
				audio.playMusic();
			}
			gameStatistics.audio2.stopMusic();
			menu();
			break;
		case Game::GAME:
			audio.stopMusic();
			single(gameStatistics);
			break;
		case Game::GAME_OVER:
			game_over(gameStatistics);
			break;
		case Game::ABOUT:
			about();
			break;
		case Game::END:
			break;
		default:
			break;
		}
	}

}

//handling state - MENU
void Game::menu(){

	Text title("Boston Explorer", font, 122);
	title.setStyle(Text::Bold);
	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 20);

	const int how = 4;
	Text textMenu[how];

	string str[] = { "Play", "Exit" , "Records", "About" };

	for (size_t i = 0; i < how; i++)
	{
		if (i < 2)
		{
			textMenu[i].setFont(font);
			textMenu[i].setCharacterSize(65);
			if (i == 0) 			textMenu[i].setCharacterSize(85);
			textMenu[i].setString(str[i]);
			textMenu[i].setPosition(1280 / 2 - textMenu[i].getGlobalBounds().width / 2, 250 + i * 320);
		}
		else{
			textMenu[i].setFont(font);
			textMenu[i].setCharacterSize(33);
			textMenu[i].setString(str[i]);
			textMenu[i].setPosition(1280 / 2 - textMenu[i].getGlobalBounds().width / 2, 300 + i * 55);
		}

	}

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition());
		Event event;

		while (window.pollEvent(event))
		{
			// ESC 
			if (event.type == Event::Closed || event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			{
				state = END;
			}
			//Exit
			else if (textMenu[1].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = END;
			}
			//Game
			else if (textMenu[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left || event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				state = GAME;
			}
			//Records
			else if (textMenu[2].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left || event.type == Event::KeyPressed && event.key.code == Keyboard::X)
			{
				state = GAME_OVER;
			}
			//About
			else if (textMenu[3].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = ABOUT;
			}
		}
		//color after you hover over the button
		for (size_t i = 0; i < how; i++)
		{
			if (textMenu[i].getGlobalBounds().contains(mouse))
			{
				textMenu[i].setFillColor(Color::Cyan);
			}
			else
			{
				textMenu[i].setFillColor(Color::White);
			}
		}

		window.clear();

		window.draw(title);
		for (size_t i = 0; i < how; i++)
		{
			window.draw(textMenu[i]);
		}

		window.display();

	}
}

//handling state - GAME (run engine)
void Game::single(Staty::GameStatistics &gameStatistics){

	Engine engine(window, gameStatistics);


	if (engine.GameState2 == Engine::MENU_AGAIN )
	{
		state = MENU;
	}


	if (engine.GameState2 == Engine::NEXT_LEVEL)
	{
		state = GAME;
		gameStatistics.nrLevel++;
		if (gameStatistics.nrLevel >= 29) gameStatistics.nrLevel = 15;
	}


	if (engine.GameState2 == Engine::LEVEL_AGAIN)
	{
		state = GAME;
	}


	if (engine.GameState2 == Engine::END)
	{
		state = END;
	}

	if (engine.GameState2 == Engine::GAME_OVER)
	{
		state = GAME_OVER;
	}
}

//handling  state - GAME_OVER (Records)
void Game::game_over(Staty::GameStatistics &gameStatistics)
{

	Text keyCode("Esc - Menu  	Space - New Game	  F4 - End", font, 26);
	Text f1("F1  -  Fullscreen / Window Mode", font, 26);
	keyCode.setPosition(888, 680);
	f1.setPosition(37, 680);


	//Game Records
	Text game_records("Game Records", font, 67);
	game_records.setStyle(Text::Bold);
	game_records.setPosition(1280 / 2 - game_records.getGlobalBounds().width / 2, 0);

	Text level_records("Levels Records", font, 55);
	level_records.setStyle(Text::Bold);
	level_records.setPosition(1280 / 2 - level_records.getGlobalBounds().width / 2, 170);

	const int how_gr = 3;
	Text tab_rec[how_gr];
	string str[] = { to_string(gameStatistics.tabWithRecords[0].firstplace), to_string(gameStatistics.tabWithRecords[0].secondplace), to_string(gameStatistics.tabWithRecords[0].thirdplace) };
	string addNewRecord = "New Record !";

	while (state == GAME_OVER)
	{
		window.clear();

		Vector2f mouse(Mouse::getPosition());
		Event event;

		for (size_t i = 0; i < how_gr; i++)
		{
			tab_rec[i].setFont(font);
			tab_rec[i].setCharacterSize(40);
			tab_rec[i].setString(to_string(i + 1) + " )\t\t" + str[i]);
			tab_rec[i].setPosition(1280 / 2 - tab_rec[i].getGlobalBounds().width / 2, 60 + i * 25);


			if (gameStatistics.ifGameRecord[i] == true)
			{
				Text addNewGameRecord;
				addNewGameRecord.setFont(font);
				addNewGameRecord.setCharacterSize(40);
				addNewGameRecord.setString(addNewRecord);
				addNewGameRecord.setFillColor(Color::Red);
				addNewGameRecord.setPosition(1280 / 2 + tab_rec[i].getGlobalBounds().width / 2 + 50, 60 + i * 25);
				window.draw(addNewGameRecord);
			}

			if (tab_rec[i].getGlobalBounds().contains(mouse)) tab_rec[i].setFillColor(Color::Green);
			else{ tab_rec[i].setFillColor(Color::White); };
		}

		//Levels Records
		int to_setPos = 0;

		for (size_t i = 0; i < gameStatistics.howmanylevels; i++)
		{
			Text str;
			str.setFont(font);
			str.setCharacterSize(23);

			if (gameStatistics.ifRecord[i] == true)
			{
				str.setString(to_string(gameStatistics.tabWithRecords[i].nr_level) + " )\t\t" + gameStatistics.tabWithRecords[i].date
					+ "\t\t" + to_string(gameStatistics.tabWithRecords[i].nr_points) + "\t\t\t\t" + addNewRecord);
			}
			else
			{
				str.setString(to_string(gameStatistics.tabWithRecords[i].nr_level) + " )\t\t" + gameStatistics.tabWithRecords[i].date
					+ "\t\t" + to_string(gameStatistics.tabWithRecords[i].nr_points));
			}

			str.setPosition(1280 / 2 - 280 / 2, 250 + i * 13 + to_setPos);

			if (!((i + 1) % 5)) to_setPos += 10;
			if (str.getGlobalBounds().contains(mouse)) str.setFillColor(Color::Red);

			window.draw(str);
		}

		//handling keys
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
			{
				for (size_t i = 0; i < gameStatistics.howmanylevels; i++)
				{
					gameStatistics.ifRecord[i] = false;
					if (i < 3) gameStatistics.ifGameRecord[i] = false;
				}

				state = MENU;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::F4)
			{
				state = END;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::F1)
			{
				window.close();
				if (fullScrean)
					window.create(VideoMode(1280, 720), "Boston Explorer", Style::Fullscreen);
				if (!fullScrean)
					window.create(VideoMode(1280, 720), "Boston Explorer", Style::Close);

				window.setFramerateLimit(65);
				fullScrean = !fullScrean;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				for (size_t i = 0; i < gameStatistics.howmanylevels; i++)
				{
					gameStatistics.ifRecord[i] = false;
					if (i < 3) gameStatistics.ifGameRecord[i] = false;
				}

				state = GAME;
			}

		}//pollEvent

		window.draw(game_records);
		window.draw(level_records);

		for (size_t i = 0; i < how_gr; i++)
		{
			window.draw(tab_rec[i]);
		}

		window.draw(keyCode);
		window.draw(f1);

		window.display();

	}//while
}

//handling state - ABOUT
void Game::about(){

	window.clear();

	Text keyCode("Esc - Menu  	Space - New Game	  F4 - End", font, 26);
	Text f1("F1  -  Fullscreen / Window Mode", font, 26);
	keyCode.setPosition(888, 680);
	f1.setPosition(37, 680);


	Text back_button("BACK", font, 77);
	back_button.setPosition(1280/2 - back_button.getGlobalBounds().width/2, 620);

	const int how = 12;
	Text aboutText[how];

	string str[] = { "Boston Explorer - Simple SFML Game",
		"Copyright (C) 2015 Dominik \"b00sti\" Pawlik <pawlik.dominik@gmail.com>",
		"",
		"\t\tRules of the game:",
		"1.\t W - move towards mouse.",
		"2. \tYou have to collect items.",
		"3. \tIf your power bar will be empty you will lose one life.",
		"4. \tTo go to the next level you need to collect the right amount of items with the highest value.",
		"5. \tTo new life you need to collect 50 000 points.",
		"6. \tBreak the records !",
		"",
		"\t \tGood Luck !"
	};

	for (size_t i = 0; i < how; i++)
	{
		aboutText[i].setFont(font);
		aboutText[i].setCharacterSize(33);
		aboutText[i].setString(str[i]);
		aboutText[i].setPosition(200, 100 + i * 40);
	}

	while (state == ABOUT)
	{
		window.clear();

		Vector2f mouse(Mouse::getPosition());
		Event event;

		if (back_button.getGlobalBounds().contains(mouse)) back_button.setFillColor(Color::Cyan);

		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
			{
				state = MENU;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::F4)
			{
				state = END;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::F1)
			{
				window.close();
				if (fullScrean)
					window.create(VideoMode(1280, 720), "Boston Explorer", Style::Fullscreen);
				if (!fullScrean)
					window.create(VideoMode(1280, 720), "Boston Explorer", Style::Close);

				window.setFramerateLimit(65);
				fullScrean = !fullScrean;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				state = GAME;
			}

			if (back_button.getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = MENU;
			}
		}//pollEvent

		for (size_t i = 0; i < how; i++)
		{
			window.draw(aboutText[i]);
		}
		window.draw(keyCode);
		window.draw(f1);
		window.draw(back_button);

		window.display();
	}
}
