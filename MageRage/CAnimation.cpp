#include "CAnimation.h"
#include <iostream>


CAnimation::CAnimation()
{
	started = false;
	dir = 1;

}

CAnimation::CAnimation(std::string n, sf::IntRect initial_rect, int frames, bool rev)
{
	reverse = rev;
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
		if(!reverse) 
		{
			if (current_frame < total_frames - 1) //  frame starts from 0
			{
				current_frame++;
			}
			else
			{
				current_frame = 0;
			}
		}
		else
		{
			if (current_frame < total_frames - 1 && current_frame >= 0) //  frame starts from 0
			{
				current_frame += dir;
			}
			else
			{
				if(dir == 1) dir = -1;
				else dir = 1;
				current_frame += dir;
			}
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
//	std::cout << "frame: " << rect.left << " " << rect.top << " " << rect.width << " " << rect.height << std::endl;
	return rect;
}


