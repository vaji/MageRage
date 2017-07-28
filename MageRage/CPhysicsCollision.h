#pragma once
class CPhysicsCollision
{
private:
	int x_positive, x_negative, y_positive, y_negative; // collision = 0, no_collision = 1
public:

	bool leftCollision();
	bool rightCollision();
	bool upCollision();
	bool downCollsion();

	void setCollision(int x_pos, int x_neg, int y_pos, int y_neg);

	CPhysicsCollision();
	CPhysicsCollision(int x_pos, int x_neg, int y_pos, int y_neg);
	~CPhysicsCollision();
};

