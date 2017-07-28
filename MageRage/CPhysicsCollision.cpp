#include "CPhysicsCollision.h"


// collision = 0, no_collision = 1
bool CPhysicsCollision::leftCollision()
{
	if (x_negative == 0) return true;
	else return false;
}

bool CPhysicsCollision::rightCollision()
{
	if (x_positive == 0) return true;
	else return false;
}

bool CPhysicsCollision::upCollision()
{
	if (y_positive == 0) return true;
	else return false;
}

bool CPhysicsCollision::downCollsion()
{
	if (y_negative == 0) return true;
	else return false;
}

void CPhysicsCollision::setCollision(CPhysicsBody *body1, CPhysicsBody *body2, int x_pos, int x_neg, int y_pos, int y_neg)
{
	target_body = body2;
	bodies.push_back(body1);
	bodies.push_back(body2);
	
	x_positive = x_pos;
	x_negative = x_neg;
	y_positive = y_pos;
	y_negative = y_neg;
}

CPhysicsCollision::CPhysicsCollision()
{
	x_positive = x_negative = y_negative = y_positive = 1;
}

CPhysicsCollision::CPhysicsCollision(CPhysicsBody *body1, CPhysicsBody *body2, int x_pos, int x_neg, int y_pos, int y_neg)
{
	target_body = body2;
	bodies.push_back(body1);
	bodies.push_back(body2);
	
	x_positive = x_pos;
	x_negative = x_neg;
	y_positive = y_pos;
	y_negative = y_neg;
}


CPhysicsCollision::~CPhysicsCollision()
{
}

std::vector<CPhysicsBody> CPhysicsCollision::getBodies()
{
	return bodies;
}

CPhysicsBody* CPhysicsCollision::getTarget()
{
	return target_body;
}