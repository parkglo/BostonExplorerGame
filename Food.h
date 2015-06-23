#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class Food
{
public:

	Food(int whichFood);
	Food();
	~Food();

	Clock clock_food;
	Clock clock_points_food;
	Vector2f pos;
	Font font;
	Texture texture;
	Time foodTime;
	Sprite sprite;

	int whichfood;
	int pointsPerFood;

	void setFoodTime();
	void changeFood( int howmanyFood );

};
