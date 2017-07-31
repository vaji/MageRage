#include "CEntity.h"

#include <iostream>

CEntity::CEntity()
{
	if(body != NULL) body->name = "eloBODY";
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
	// window->draw(sprite);
	//shape.setPosition(body.getPosition());

	window->draw(shape);

}

void CEntity::update()
{
	//updateAnimation();
	//updateLogic();
	shape.setPosition(body->getPosition());

}

void CEntity::setPosition(sf::Vector2f vec)
{
	body->setPosition(vec);
	shape.setPosition(vec);
}

sf::Vector2f CEntity::getPosition()
{
	return body->getPosition();
}

void CEntity::updateLogic()
{
	
	
}

std::string CEntity::getType()
{
	return type;
}


void CEntity::setBody(CPhysicsBody * bd)
{
	body = bd;
}


CPhysicsBody* CEntity::getBody()
{
	return body;
}