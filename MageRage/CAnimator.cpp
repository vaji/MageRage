#include "CAnimator.h"


CAnimator::CAnimator()
{
}


CAnimator::~CAnimator()
{

}

int CAnimator::addAnimation(std::string name, int x, int y, int w, int h, int frames)
{
	sf::IntRect rect;
	rect.top = y;
	rect.left = x;
	rect.height = h;
	rect.width = w;

	anim_list.push_back(CAnimation(name, rect, frames));

	return 1;
}

void CAnimator::setAnimation(std::string name, bool reset)
{
	anim->stop();


	for (int i = 0; i < anim_list.size(); i++)
	{
		if (anim_list[i].name == name)
		{
			current_animation_index = i;
			break;
		}
	}
	anim = &anim_list[current_animation_index];
	if (reset) anim->reset();
	anim->start();
}

void CAnimator::resetAnimation()
{
	anim->reset();
}

void CAnimator::update()
{
	anim->update();
}

sf::IntRect CAnimator::getAnimationFrame()
{
	return anim->getFrame();
}

std::string CAnimator::getCurrentAnimation()
{
	return anim->name;
}
