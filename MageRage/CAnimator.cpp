#include "CAnimator.h"


CAnimator::CAnimator()
{
}


CAnimator::~CAnimator()
{

}

int CAnimator::addAnimation(std::string name, int x, int y, int w, int h, int frames, bool rev)
{
	sf::IntRect rect;
	rect.top = y;
	rect.left = x;
	rect.height = h;
	rect.width = w;

	anim_list.push_back(CAnimation(name, rect, frames,rev));

	return 1;
}

void CAnimator::setAnimation(std::string name, bool reset)
{
	anim_list[current_animation_index].stop();

	for (int i = 0; i < anim_list.size(); i++)
	{
		if (anim_list[i].name == name)
		{
			current_animation_index = i;
			break;
		}
	}
	anim_list[current_animation_index];
	if (reset) anim_list[current_animation_index].reset();
	anim_list[current_animation_index].start();
}

void CAnimator::resetAnimation()
{
	anim_list[current_animation_index].reset();
}

void CAnimator::update()
{
	anim_list[current_animation_index].update();
}

sf::IntRect CAnimator::getAnimationFrame()
{
	return anim_list[current_animation_index].getFrame();
}

std::string CAnimator::getCurrentAnimation()
{
	return anim_list[current_animation_index].name;
}
