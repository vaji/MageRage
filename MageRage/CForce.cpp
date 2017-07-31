#include "CForce.h"
#include <cmath>
#include <iostream>
CForce::CForce()
{
	x = 0;
	y = 0;
}

CForce::CForce(sf::Vector2f vec)
{
	total_time = 0; // forever
	time_left = 0;
	impulse = false; // constant
	initial_x = x = vec.x;
	initial_y = y = vec.y;
	
	finished = false;
	muted = false;

}


CForce::CForce(sf::Vector2f vec, float time, bool is_impulse)
{
	initial_x = x = vec.x;
	initial_y = y = vec.y;
	total_time = time_left = time;
	impulse = is_impulse;
	
	finished = false;
	muted = false;
}

CForce::~CForce()
{
}

void CForce::update()
{

	if(!finished && !muted) {
		if(impulse)
		{
			x = initial_x * ((1 / (pow(time_left,2)) + 1.1));
			y = initial_y * ((1 / (pow(time_left,2)) + 1.1));
		}
		
		if(total_time != 0)
		{ 
			if(time_left < total_time) time_left--;
			else finished = true; //ready to be removed by manager
		}
	}
}

void CForce::mute()
{
	muted = true;
}

bool CForce::isImpulse()
{
	return impulse;
}

float CForce::getTime()
{
	return time_left;
}

bool CForce::isFinished()
{
	return finished;
}
