#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

#include "CForce.h"

class CPhysicsBody
{
private:

public:

	sf::Vector2f position;

	void update();
	void updatePosition();
	void updateForces();


	CPhysicsBody();
	~CPhysicsBody();
};

