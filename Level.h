#pragma once
#include <string>

using namespace std;

class Level
{
public:
	Level();
	Level(string filename);
	~Level();

	enum FieldType{NONE, STONE, WATER, DIRT, GRASS, COUNT};

	struct Tile{ FieldType type; bool isWall; };

	//map size
	const static int width = 32;
	const static int height = 18;

	//each cell size
	const static int tile_width = 40;
	const static int tile_height = 40;

	Tile loadLevel[height][width];

	void loadFromFile(string filename);

};
