#pragma comment(lib, "user32.lib")

#include "Point.h"
#include <Windows.h>
#include <iostream>

Point::Point(string n_label, Vector2f n_pos)
:label("100"),
pos(Vector2f(700,400)),
label2("100",font)

{
	if (!font.loadFromFile("Data/GoodDog.otf"))
	{
		MessageBox(NULL, "Font not found !", "ERROR", NULL);
		return;
	}

	label = n_label;
	pos = n_pos;
}

Point::Point()
{
}

Point::~Point()
{
}
