#include "CEntity.h"

#include <iostream>

CEntity::CEntity()
{

}

CEntity::CEntity(int idd, bool animated)
{
	ID = idd;
	is_animated = animated;
	shape = sf::CircleShape(25);
}

CEntity::CEntity(int idd, sf::Texture *txt, bool animated)
{
	ID = idd;
	is_animated = animated;
	sprite.setTexture(*txt);

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
	if(is_animated) updateAnimation();
	//updateLogic();
}

void CEntity::setPosition(sf::Vector2f vec)
{
	shape.setPosition(vec);
	sprite.setPosition(vec);
}

sf::Vector2f CEntity::getPosition()
{
	return shape.getPosition();
}

void CEntity::updateLogic()
{
	
	
}

void CEntity::setType(std::string new_type)
{
	type = new_type;
}
std::string CEntity::getType()
{
	return type;
}

void CEntity::setID(int idd)
{
	ID = idd;
}

int CEntity::getID()
{
	return ID;
}
