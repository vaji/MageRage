#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>


class CForce :
	public sf::Vector2f
{
private:

	float total_time;
	float time_left;
	bool impulse;

public:

	CForce();
	CForce(sf::Vector2f vec);
	CForce(sf::Vector2f vec, float time, bool is_impulse);
	~CForce();
};

