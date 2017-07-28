#include "CPhysicsManager.h"



void CPhysicsManager::AddForce(CPhysicsBody * body, CForce force)
{
	body->force_list.push_back(force);
}

void CPhysicsManager::updatePhysics()
{
	// first check for any present collisions, if there are any, they will influence next step of update
	// which is updating position and forces on bodies
	// e.g. body cannot move left if there is collision and it's forces are zeroed in "left" direction
	updateCollisions();
	updateBodies();
}

std::vector<CPhysicsBody> CPhysicsManager::getNarrowCollisionGroup(CPhysicsBody * body)
{
	return 0;
}

CPhysicsCollision CPhysicsManager::getCollision(CPhysicsBody * body)
{
	return CPhysicsCollision();
}

CPhysicsManager::CPhysicsManager()
{
}


CPhysicsManager::~CPhysicsManager()
{
}
