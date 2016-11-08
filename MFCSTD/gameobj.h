#pragma once
#include "stdafx.h"
class Player
{
public:
	int sizeX;
	int sizeY;
	double pointx;
	double pointy;
	double xspeed;
	double yspeed;
	bool iscollision;
	int life;
	double gravity;
	double jforce;
	double fire;
	bool isRight;
	bool onland;
	int movesp;

	int sp;
	bool die;

	Player();
	Player(int sizex, int sizey, double pointx, double porinty);

	void playermove();
	void playermaxpoint();
	void collision();
	void dameged(bool col);
};

class Ball
{
public:
	double x;
	double y;
	double sx;
	double sy;
	double Ggravity;
	double AirRig;
	double yforce;


	Ball();
	Ball(double px, double py, double Sx, double Sy);
	void ballmove(int airR);
};

class Land
{
public:
	double pointx;
	double pointy;
	double sizex;
	double sizey;

	Land()
	{
		pointx = 0;
		pointy = 0;
		sizex = 40;
		sizey = 50;
	}

	Land(double a, double b, double c, double d)
	{
		pointx = a;
		pointy = b;
		sizex = c;
		sizey = d;
	}

	void del()
	{
		pointx = -100;
		pointy = -100;
	}

};