#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

#include "CForce.h"

class CPhysicsBody
{
private:

	sf::Vector2f position;	
	sf::vector<CForce> force_list;
	
public:

	

	void update();
	void updatePosition();
	void updateForces();

	void setPosition(sf::Vector2f vec);
	sf::Vector2f getPosition();
	
	CPhysicsBody();
	~CPhysicsBody();
};

