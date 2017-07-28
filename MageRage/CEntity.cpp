#include "CEntity.h"



CEntity::CEntity(sf::Texture *txt)
{
	*texture = *txt;
	sprite.setTexture(*texture);
}


CEntity::~CEntity()
{
}

void CEntity::render(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void CEntity::update()
{
	animator.update();
	sprite.setTextureRect(animator.getAnimationFrame());
}

void CEntity::setPosition(sf::Vector2f vec)
{
}
