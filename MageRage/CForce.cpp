#include "CForce.h"

CForce::CForce()
{
	x = 0;
	y = 0;
}

CForce::CForce(sf::Vector2f vec)
{

}


CForce::CForce(sf::Vector2f vec, float time, bool impulse)
{
	x = vec.x;
	y = vec.y;

}

CForce::~CForce()
{
}
