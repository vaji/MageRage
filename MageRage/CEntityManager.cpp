#include "CEntityManager.h"



CEntityManager::CEntityManager()
{
}


CEntityManager::~CEntityManager()
{
}

void CEntityManager::updateEntities()
{
	for each (CEntity entity in entity_list)
	{
		entity.update();
	}
}

void CEntityManager::renderEntities(sf::RenderWindow * window)
{
	for each (CEntity entity in entity_list)
	{
		entity.render(window);
	}
}

