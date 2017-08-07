#include "CPhysicsBody.h"
#include <iostream>


CPhysicsBody::CPhysicsBody()
{
	
}

CPhysicsBody::CPhysicsBody(int idd)
{
	ID = idd;
}


CPhysicsBody::~CPhysicsBody()
{
}


void CPhysicsBody::setPosition(sf::Vector2f vec)
{
	position = vec;
}

CForce CPhysicsBody::getResultantForce()
{
	CForce temp(sf::Vector2f(0, 0));
	for (int i = 0; i < force_list.size(); i++)
	{
		temp += force_list.at(i);
	}

	return temp;
}

sf::Vector2f CPhysicsBody::getPosition()
{
	return position;
}

int CPhysicsBody::getID()
{
	return ID;
}

void CPhysicsBody::updatePosition()
{
	// change position

	sf::Vector2f temp_vector(0, 0);
	temp_vector = getResultantForce();
	setPosition(getPosition() + temp_vector);
}

void CPhysicsBody::updateForces()
{
		
	if (!force_list.empty()) {
		for (int i = 0; i < force_list.size();i++)
		{
			//std::cout << "CHCE AKTUALIZOWAC FORCE   ";
			force_list.at(i).update();
			if (force_list.at(i).isFinished())
			{
				force_list.erase(force_list.begin() + i);
			}
	
		}
	}
}

void CPhysicsBody::addForce(sf::Vector2f vec)
{
	CForce elo(vec);
	force_list.push_back(elo);
}

