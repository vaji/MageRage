#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
class CAnimation
{
private:
	
	bool started;
	int current_frame;
	int total_frames;
	sf::IntRect initial_frame;

public:
	std::string name;
	CAnimation();
	CAnimation(std::string n, sf::IntRect initial_rect, int frames);
	~CAnimation();

	void reset();
	void update();
	int stop(); // return current frame
	void start();
	sf::IntRect getFrame();

};

