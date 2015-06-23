#include "Level.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

Level::Level()
{
}

//loadFromFile(filename)
Level::Level(string filename)
{
	loadFromFile(filename);
}

Level::~Level()
{
}

//loadfromfile to loadLevel[x][y] - isWall & type
void Level::loadFromFile(string filename)
{
	fstream file;
	file.open(filename, ios::in);

	string str = "Not found level: " + filename;
	LPSTR error = const_cast<char *>(str.c_str());

	if (!file.is_open())
	{
		MessageBox(NULL, error, "ERROR", NULL);
		return;
	}
	else
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int tmp;
				file >> tmp;
				loadLevel[y][x].type = FieldType(tmp);

				if (tmp == 0)
				{
					loadLevel[y][x].isWall = false;
				}
				else
				{
					loadLevel[y][x].isWall = true;
				}

			}//forx
		}//fory
	}

	file.close();
}
	