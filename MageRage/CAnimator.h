#pragma once
#include "CAnimation.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
class CAnimator
{
private:

	std::vector<CAnimation> anim_list;

	CAnimation *anim;
	int current_animation_index;


public:
	CAnimator();
	~CAnimator();

	int addAnimation(std::string name, int x, int y, int w, int h, int frames);
	void setAnimation(std::string name, bool reset);
	void resetAnimation();
	void update();

	sf::IntRect getAnimationFrame();
	std::string getCurrentAnimation();

};

