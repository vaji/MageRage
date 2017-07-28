#include "CPhysicsBody.h"



CPhysicsBody::CPhysicsBody()
{
}


CPhysicsBody::~CPhysicsBody()
{
}


void CPhysicsBody::setPosition(sf::Vector2f vec)
{
	position = vec;
}

sf::Vector2f CPhysicsBody::getPosition()
{
	return position;
}