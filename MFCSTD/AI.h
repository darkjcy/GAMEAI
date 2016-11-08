#pragma once
#include "gameobj.h"

struct Result
{
	double force;
	double angle;
	
};

class AI
{
	int DISTANCE;

public:
	void SituationCheck(Player &P1, Player &P2, double wind);
	Result GetAIResult();
};