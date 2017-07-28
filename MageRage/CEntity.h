#pragma once
#include "CAnimator.h"
#include "CPhysicsBody.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>


class CEntity
{
private:
	
	sf::Texture *texture;
	sf::Sprite sprite;
	CPhysicsBody body;

	void updateAnimation();
	void updateLogic();
	

public:
	CAnimator animator;

	CEntity(sf::Texture *txt);
	~CEntity();

	void render(sf::RenderWindow *window);
	void updatePhysics();
	void update();
	void setPosition(sf::Vector2f vec);
};

