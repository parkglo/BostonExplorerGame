#include "Food.h"
#include <Windows.h>

using namespace std;

Food::Food()
{
};

Food::Food(int whichfood)
:whichfood(whichfood),
pointsPerFood(100),
pos(Vector2f(100.f,100.f))

{

	if (texture.getSize().x == 0)
	{
		std::string _str = std::to_string(whichfood);
		if (!texture.loadFromFile("Data/food_" + _str + ".png"))
		{
			MessageBox(NULL, "Food texture not found !", "ERROR", NULL);
			return;
		}
	}

	pointsPerFood = whichfood * 100;
	pos.x = rand() % 1200 + 40;
	pos.y = rand() % 660 + 40;
	sprite.setPosition( pos);
	sprite.setTexture(texture);
	sprite.scale(0.5f, 0.5f);
	Vector2u textureSize = texture.getSize();
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	
}


Food::~Food()
{
}

void Food::changeFood( int howmanyFood){

	whichfood = (rand() % howmanyFood + 1);

	std::string _str = std::to_string(whichfood);
		if (!texture.loadFromFile("Data/food_" + _str + ".png"))
		{
			MessageBox(NULL, "Food texture not found !", "ERROR", NULL);
			return;
		}

	pointsPerFood = whichfood * 100;
	clock_food.restart();
	pos.x = rand() % 1200 + 40;
	pos.y = rand() % 660 + 40;
	sprite.setPosition( pos );
	sprite.setTexture(texture);
	Vector2u textureSize = texture.getSize();
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
}

void Food::setFoodTime()
{
	foodTime = this->clock_food.getElapsedTime();
}
