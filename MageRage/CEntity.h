#pragma once
#include "CAnimator.h"
#include "CPhysicsBody.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>


class CEntity // parent for Spell, Enemy, Hero
{
private:
	
	std::string type;
	sf::Texture *texture;
	sf::Sprite sprite;

	int ID;

	void updateAnimation();
	void updateLogic();


public:
	sf::CircleShape shape;
	
	CAnimator animator;

	CEntity();
	CEntity(int idd);
	CEntity(sf::Texture *txt);
	~CEntity();

	void render(sf::RenderWindow *window);
	
	void update();
	
	void setPosition(sf::Vector2f vec);

	sf::Vector2f getPosition();
	std::string getType();
	int getID();

};

