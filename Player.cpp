#include "Player.h"
#include <Windows.h>
#include <math.h>
#include <iostream>

#define M_PI 3.14159265358979323846

using namespace std;
using namespace sf;

Player::Player()
:status(STOP),
frame(0),
speed(10)

{
	if (!texture.loadFromFile("Data/player-move.png"))
	{
		MessageBox(NULL, "Textures not found!", "ERROR", NULL);
		return;
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));
	sprite.setOrigin(32, 32);
	sprite.setPosition(1280 / 2, 720 / 2);

	anim_clock.restart();
}

Player::~Player()
{
}

void Player::draw(RenderTarget &target, RenderStates states) const
{
	states.transform *= getTransform();;

	target.draw(sprite);
}

void Player::update(Vector2f mousePos)
{
	//hero always directed towards the mouse position
	Vector2f norm = mousePos - sprite.getPosition();
	float rot = atan2(norm.y, norm.x);
	rot = rot * 180.f / M_PI;

	rot += 90;
	sprite.setRotation(rot);

	//hero animation
	if (anim_clock.getElapsedTime() > seconds(0.02f))
	{
		if (status == STOP) return;

#if FRAME_ANIMATION == 0
		//move with frames
				if (frame < 7)
				{
					frame++;
				}
				else
				{
					frame = 0;
				}
#endif

		sprite.setTextureRect(IntRect(frame * 64, 0, 64, 64));
		sprite.move(getSpeed());

		anim_clock.restart();
	}
}

//stop flag -- > animation in update - return 
void Player::stop()
{
	status = STOP;
	frame = 0;
}

void Player::go()
{
	status = GO;
}

Vector2f Player::getSpeed(){

	float rotacja = sprite.getRotation();
	float vx = sin((rotacja * M_PI)/180.0f);
	float vy = -cos((rotacja*M_PI/180.0f));

	return Vector2f(vx*speed, vy*speed);
}
