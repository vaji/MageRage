#include "CEntity.h"

#include <iostream>

CEntity::CEntity()
{

}

CEntity::CEntity(int idd)
{
	ID = idd;
}

CEntity::CEntity(sf::Texture *txt)
{
	*texture = *txt;
	sprite.setTexture(*texture);
}


CEntity::~CEntity()
{
}
void CEntity::updateAnimation()
{
	animator.update();
	sprite.setTextureRect(animator.getAnimationFrame());
}

void CEntity::render(sf::RenderWindow *window)
{
	 window->draw(sprite);

	window->draw(shape);

}

void CEntity::update()
{
	//updateAnimation();
	//updateLogic();
}

void CEntity::setPosition(sf::Vector2f vec)
{
	shape.setPosition(vec);
}

sf::Vector2f CEntity::getPosition()
{
	return shape.getPosition();
}

void CEntity::updateLogic()
{
	
	
}

std::string CEntity::getType()
{
	return type;
}

int CEntity::getID()
{
	return ID;
}
