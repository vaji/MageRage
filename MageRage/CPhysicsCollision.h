#pragma once
#include "CPhysicsBody.h"
#include <vector>
class CPhysicsCollision
{
private:

	std::vector<CPhysicsBody*> bodies;
	CPhysicsBody *target_body;
	
	int x_positive, x_negative, y_positive, y_negative; // collision = 0, no_collision = 1
public:

	bool leftCollision();
	bool rightCollision();
	bool upCollision();
	bool downCollsion();

	std::vector<CPhysicsBody*> getBodies();
	CPhysicsBody* getTarget();
	
	// body1 is "origin" colliding body, body2 is target 
	void setCollision(CPhysicsBody *body1, CPhysicsBody *body2, int x_pos, int x_neg, int y_pos, int y_neg);

	CPhysicsCollision();
	CPhysicsCollision(CPhysicsBody *body1, CPhysicsBody *body2, int x_pos, int x_neg, int y_pos, int y_neg);
	~CPhysicsCollision();
};

