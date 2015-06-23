#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include <vector>

using namespace sf;

class PointAnimation
{

	public:

		PointAnimation();
		~PointAnimation();
	
		void add(string n_label, Vector2f n_pos);
		void update();
		void drawPoint(RenderWindow &window);

	private:

		const float lifetime; //sec
		mutable std::vector<Point*> data;

};
