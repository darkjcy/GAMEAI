#include "stdafx.h"
#include "gameobj.h"


Player::Player()
{

	sp = 300;
	sizeX = 20;
	sizeY = 20;
	pointx = 0;
	pointy = 650;
	life = 100;
	gravity = 0;
	fire = false;
	isRight = true;
	onland = false;
	die = false;
}
Player::Player(int sizex, int sizey, double x, double y)
{

	sp = 300;
	sizeX = sizex;
	sizeY = sizey;
	pointx = x;
	pointy = y;
	life = 100;
	gravity = 0;
	fire = false;
	isRight = true;
	onland = false;
	die = false;
	Twall = false;
}
void Player::playermove()
{
	if (sp > 0)
	{
		pointx += xspeed;
	}

	sp -= movesp;
	if (onland == false)
	{
		pointy += yspeed + gravity;
	}

	else
	{
		pointy += yspeed;
	}


	if (gravity < 3)
	{
		gravity += 0.1;
	}


}

void Player::playermaxpoint()
{
	if (pointx > 1400 - sizeX || pointx < sizeX)
	{
		xspeed = 0;
		if (pointx < sizeX)
		{
			pointx = sizeX;
		}
		if (pointx > 1400 - sizeX)
		{
			pointx = 1400 - sizeX;
		}

	}
	if (pointy > 900 - sizeY || pointy < sizeY)
	{
		if (pointy < sizeY)
		{
			pointy = sizeY;
		}
		if (pointy > 900 - sizeY)
		{
			pointy = 900 - sizeY;
		}
		yspeed = 0;
	}
	if (pointy >= 900 - sizeY)
	{
		gravity = 0;
		die = true;
	}

	if (pointy < 900 - sizeY && onland == false)
	{
		gravity = 3;
	}
}



//발사체 클래스========================================================================


Ball::Ball()
{
	x = 0;
	y = 650;
	sx = 0;
	sy = 0;
	Ggravity = 0;
	AirRig = 0.001;

}

Ball::Ball(double px, double py, double Sx, double Sy)
{
	x = px;
	y = py;
	sx = Sx;
	sy = Sy;
	Ggravity = 0;
	AirRig = 0.001;

}

void Ball::ballmove(int airR)
{
	if (y <= 900)
	{
		Ggravity += 0.01;
		AirRig += (double)airR / 1000;
		x += sx + AirRig;
		y += sy + Ggravity;
	}
	else if (y > 900)
	{
		AirRig = 0;
		sx = 0;
		y = 900;
		sy = 0;
	}
}
