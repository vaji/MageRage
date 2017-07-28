#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

#include "CForce.h"
#include "CPhysicsBody.h"
#include "CPhysicsCollision.h"

class CPhysicsManager
{
private:

public:

	void AddForce(CPhysicsBody *body, CForce force);
	void updateBodies(); // 1 - update collision, 2 - update each body (position, forces)

	void updateCollisions(); // algorithm for finding collisions
	void getNarrowCollisionGroup(CPhysicsBody *body); // find nearest bodies, basing on distance
	CPhysicsCollision getCollisionVector(CPhysicsBody *body); // check if body can move in directions
	void Collide(CPhysicsBody *body); // handle collision - alter forces on body

	CPhysicsManager();
	~CPhysicsManager();
};

