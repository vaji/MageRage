#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include "CForce.h"

class CPhysicsBody
{
private:

	sf::Vector2f position;	
	
	
public:
	std::string name;
	std::vector<CForce> force_list;
	
	// LOOP
	void update();
	void updatePosition();
	void updateForces();

	// methods
	void addForce(sf::Vector2f vec);

	// SET
	void setPosition(sf::Vector2f vec);

	// GET
	CForce getResultantForce();
	sf::Vector2f getPosition();
	
	
	
	CPhysicsBody();
	~CPhysicsBody();
};

