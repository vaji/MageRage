#include "CEntity.h"



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
}

void CEntity::update()
{
	updateAnimation();
	updateLogic();
}

void CEntity::setPosition(sf::Vector2f vec)
{
	body.setPosition(vec);
}

sf::Vector2f CEntity::getPosition()
{
	return body.getPosition();
}

void CEntity::updateLogic()
{
	
	
}
