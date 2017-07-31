#include "CAnimation.h"



CAnimation::CAnimation()
{
	started = false;
}

CAnimation::CAnimation(std::string n, sf::IntRect initial_rect, int frames)
{
	name = n;
	initial_frame = initial_rect;
	total_frames = frames;
}


CAnimation::~CAnimation()
{
}

void CAnimation::reset()
{
	current_frame = 0;
}

void CAnimation::update()
{
	if (started)
	{
		if (current_frame < total_frames) //  frame starts from 0
		{
			current_frame++;
		}
		else
		{
			current_frame = 0;
		}
	}
}

int CAnimation::stop()
{
	started = false;
	return current_frame;
}

void CAnimation::start()
{
	started = true;
}

sf::IntRect CAnimation::getFrame()
{
	sf::IntRect rect;

	rect = initial_frame;
	rect.left += rect.width * current_frame;
	rect.top += rect.height * current_frame;

	return rect;
}


