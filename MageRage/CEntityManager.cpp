#include "CEntityManager.h"
#include <iostream>


CEntityManager::CEntityManager()
{
}


CEntityManager::~CEntityManager()
{
}

void CEntityManager::setPhysicsManagerHandler(CPhysicsManager * manager)
{
	physicsManagerHandler = manager;
}

// ***************************************************************************************
// LOOP

void CEntityManager::update()
{
	updateEntities();
}


void CEntityManager::updateEntities()
{
	for (int i = 0; i < entity_list.size();i++)
	{
		
		entity_list.at(i).update();
	}
}

void CEntityManager::renderEntities(sf::RenderWindow * window)
{
	for (int i = 0; i < entity_list.size(); i++)
	{
		entity_list.at(i).render(window);
	}
}


// ***************************************************************************************
// HANDLING ENTITIES
CEntity* CEntityManager::addEntity(std::string type, sf::Vector2f position, bool gravity)
{
	system("cls");
	CEntity entity;
	entity_list.push_back(entity);
	entity_list.back().setBody(physicsManagerHandler->registerNewBody());

	entity_list.back().shape = sf::CircleShape(50);
	entity_list.back().setPosition(position);
	
	
	std::cout << "na liscie ENTITY mam teraz " << entity_list.size() << std::endl;

	physicsManagerHandler->addForce(entity_list.back(), sf::Vector2f(0, 3));


	return &entity_list.back();
}

void CEntityManager::removeEntity(CEntity * entity)
{
}


CEntity* CEntityManager::createEntityByType(std::string type, sf::Vector2f position)
{
	CEntity entity;
	for (int i = 0; i< entity_types.size(); i++)
	{
		if (entity_types[i].getType() == type)
		{
			entity = entity_types[i];
		}
	}
	entity.setPosition(position);
	entity_list.push_back(entity);
	return &entity_list.back();
}



// ***************************************************************************************
// LOADING
void CEntityManager::loadEntityTypes()
{
	// read xml to load templates
	
}

void CEntityManager::load()
{
	loadEntityTypes();
}

