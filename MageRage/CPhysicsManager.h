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
	
	void updatePhysics();// 1 - update collision, 2 - update each body (position, forces)
	
	void updateCollisions(); // algorithm for finding collisions (1st step)
	void updateBodies();  // (2nd step)
	
	
	
	std::vector<CPhysicsBody>  getNarrowCollisionGroup(CPhysicsBody *body); // find nearest bodies, basing on distance
	CPhysicsCollision getCollision(CPhysicsBody *body); // check if body can move in directions
	void Collide(CPhysicsBody *body); // handle collision - alter forces on body

	CPhysicsManager();
	~CPhysicsManager();
};


//***************
// updateCollision -> kolizja zapisywana jest w kazdym body (w liscie)
// przy updateEntity, entity sam sprawdza (jezeli potrzebuje) czy ma jakas kolizje
// jezeli ma jakis efekt przy kolizji to sygnalizuje to flagą typu takeEffect=true
// entity (spell) ma "zarejestrowany" effect w postaci np. struktury
// entityManager przy updatacie sprawdza flagi i wykonuje konkretny effect.

