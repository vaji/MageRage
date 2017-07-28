#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>


class CForce :
	public sf::Vector2f
{
private:
	float initial_x;
	float initial_y;
	
	float total_time;
	float time_left;
	
	bool impulse; // IMPULSE calculate its magnitude by "y = 1/t^3 + 1.1" equation
	
	bool finished;
	bool muted;

public:

	CForce();
	CForce(sf::Vector2f vec);
	CForce(sf::Vector2f vec, float time, bool is_impulse);
	~CForce();
	
	void mute();
	bool isImpulse();
	float getTime();
	
	void update(); // updates time and magnitude (vector)
	
	
};

