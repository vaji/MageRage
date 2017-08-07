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
		body_list.at(i).setPosition(body_list.at(i).getPosition() + sf::Vector2f(0, 3));
		//body_list.at(i).updatePosition();
		//body_list.at(i).updateForces();
		
	}
}


// *****************************************************************************************************************
// HANDLING
void CPhysicsManager::registerNewBody(int idd)
{
	CPhysicsBody body(idd);
	body_list.push_back(body);
}

void CPhysicsManager::removeBody(int idd)
{
	for (int i = 0; i < body_list.size(); i++)
	{
		if (body_list.at(i).getID() == idd)
		{
			body_list.erase(body_list.begin() + i);
		}
	}
}

CPhysicsBody * CPhysicsManager::getBodyHandler(int idd)
{
	for (int i = 0; i < body_list.size(); i++)
	{
		if (body_list.at(i).getID() == idd)
		{
			return &body_list.at(i);
		}
	}
}

sf::Vector2f CPhysicsManager::getBodyPosition(int idd)
{
	for (int i = 0; i < body_list.size(); i++)
	{
		if (body_list.at(i).getID() == idd)
		{
			return body_list.at(i).getPosition();
		}
	}
	return sf::Vector2f(0, 0);
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
	int idd = entity.getID();
	for (int i = 0; i < body_list.size(); i++)
	{
		if (body_list.at(i).getID() == idd)
		{
			return body_list.at(i).addForce(vec);
		}
	}
}
