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

CEntity* CEntityManager::addEntity(std::string type, sf::Vector2f position)
{
	CEntity* entity = new CEntity();
	for(int i = 0;i< entity_types.size;i++)
	{
		if(entity_types[i].type == type)
		{
			 entity = entity_types[i];
		}
	}
	entity.setPosition(position);
	return entity_list.push_back(entity);
}

void CEntityManager::loadEntityTypes()
{
	// read xml to load templates
	
}

void CEntityManager::load()
{
	loadEntityTypes();
}