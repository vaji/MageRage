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

	bool is_animated;


public:
	sf::CircleShape shape;
	
	CAnimator animator;

	CEntity();
	CEntity(int idd, bool animated = false);
	CEntity(int idd, sf::Texture *txt, bool animated = true);
	~CEntity();

	void render(sf::RenderWindow *window);
	
	void update();
	
	void setPosition(sf::Vector2f vec);

	sf::Vector2f getPosition();
	void setType(std::string new_type);
	std::string getType();
	void setID(int idd);
	int getID();

};

