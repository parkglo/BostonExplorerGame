#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Point
{
	public:
		Point();
		~Point();

		Clock clock_points_food;
		string label;
		Vector2f pos;
		Text label2;
		Font font;

		Point(string n_label, Vector2f n_pos);

};
