#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

#include "CForce.h"
#include "CPhysicsBody.h"
#include "CPhysicsCollision.h"
#include "CEntity.h"

class CPhysicsManager
{
private:
	std::vector<CPhysicsBody> body_list;

public:

	
	
	// loop
	void update();// 1 - update collision, 2 - update each body (position, forces)
	void updateCollisions(); // algorithm for finding collisions (1st step)
	void updateBodies();  // (2nd step)
	
	// methods
	void addForce(CPhysicsBody *& body, CForce force);
	void addForce(CPhysicsBody *& body, sf::Vector2f vec);
	void addForce(CEntity &entity, sf::Vector2f vec);
	void registerNewBody(int idd); // this is called by entity manager when entity is created (with body)
	void removeBody(int idd);
	CPhysicsBody * getBodyHandler(int idd);
	sf::Vector2f getBodyPosition(int idd);
										// entity has only pointer to its body which is set on object created by physics manager 
										// body is stored in 'vector' in physics manager and pointer is returned for entity 

	
	// collision
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

