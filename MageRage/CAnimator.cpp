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
	if (anim != NULL)  anim->stop();


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
	if (anim != NULL) anim->reset();
}

void CAnimator::update()
{
	if(anim != NULL) anim->update();
}

sf::IntRect CAnimator::getAnimationFrame()
{
	if (anim != NULL)
		return anim->getFrame();
	else return sf::IntRect(0, 0, 0, 0);
}

std::string CAnimator::getCurrentAnimation()
{
	if (anim != NULL)
		return anim->name;
	else return "";
}
