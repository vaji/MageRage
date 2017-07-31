#include "CPhysicsManager.h"
#include <iostream>


CPhysicsManager::CPhysicsManager()
{
}


CPhysicsManager::~CPhysicsManager()
{
}



// *****************************************************************************************************************
// LOOP
void CPhysicsManager::update()
{
	// first check for any present collisions, if there are any, they will influence next step of update
	// which is updating position and forces on bodies
	// e.g. body cannot move left if there is collision and it's forces are zeroed in "left" direction
	//updateCollisions();
	updateBodies();

	
}


void CPhysicsManager::updateCollisions()
{
}


void CPhysicsManager::updateBodies()
{

	// move bodies, remove forces
	for (int i = 0; i < body_list.size();i++)
	{
		body_list.at(i).updatePosition();
		body_list.at(i).updateForces();
		
	}
}


// *****************************************************************************************************************
// HANDLING
CPhysicsBody* CPhysicsManager::registerNewBody()
{
	

	CPhysicsBody body;
	body_list.push_back(body);
	std::cout << "na liscie PHYSICS mam teraz " << body_list.size() << std::endl;
	return &body_list.back();
	//body_list.back()->name = "ELO POWINNO BYC TO SAMO";
}


// *****************************************************************************************************************
// COLLISIONS
void CPhysicsManager::Collide(CPhysicsBody * body)
{

}

std::vector<CPhysicsBody> CPhysicsManager::getNarrowCollisionGroup(CPhysicsBody * body)
{
	return std::vector<CPhysicsBody>();
}


CPhysicsCollision CPhysicsManager::getCollision(CPhysicsBody * body)
{
	return CPhysicsCollision();
}


// *****************************************************************************************************************
// FORCES
void CPhysicsManager::addForce(CPhysicsBody *& body, CForce force)
{
	body->addForce(force);
}

void CPhysicsManager::addForce(CPhysicsBody *& body, sf::Vector2f vec)
{
	
	body->addForce(CForce(vec));
}

void CPhysicsManager::addForce(CEntity &entity, sf::Vector2f vec)
{
	entity.getBody()->addForce(vec);
}
