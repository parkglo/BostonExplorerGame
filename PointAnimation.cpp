#include "PointAnimation.h"
#include <Windows.h>

using namespace std;
using namespace sf;

PointAnimation::PointAnimation()
:lifetime(5)

{
}

PointAnimation::~PointAnimation()
{
}

void PointAnimation::add(string n_label, Vector2f n_pos)
{
	data.push_back(new Point(n_label, n_pos));

	data.back() -> clock_points_food.restart();
}

void PointAnimation::update()
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i]->clock_points_food.getElapsedTime().asSeconds() > lifetime)
		{
			delete data[i];
			data.erase(data.begin() + i);
			i--;
			continue;
		}
	}
}

void PointAnimation::drawPoint(RenderWindow &window)
{

	for (unsigned int i = 0; i < data.size(); i++)
	{
		Vector2f labelPos;
		float time = data[i]->clock_points_food.getElapsedTime().asSeconds();
		labelPos.x = data[i]->pos.x + sin(time * 3)*(10 - time / 2) * 5;
		labelPos.y = data[i]->pos.y - time * 15;
		float scaleFactor = 1.f;

		if (time > 0.5f * lifetime) scaleFactor = (lifetime - time) / (lifetime * 0.5f );
		data[i]->label2.setString(data[i]->label);
		data[i]->label2.setPosition(labelPos);
		data[i]->label2.setColor(Color(255, 0, 0, static_cast<Uint8>(255.f * scaleFactor)));

		data[i] -> label2.setScale(scaleFactor, scaleFactor);

		window.draw(data[i]->label2);
	}

}
