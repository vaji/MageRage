#include "CEntityManager.h"
#include <iostream>

CEntityManager::CEntityManager()
{
	world_size = sf::Vector2f(640, 860);
	next_id = 0;
}

CEntityManager::CEntityManager(sf::Vector2f world)
{
	world_size = world;
	next_id = 0;
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
//	system("cls");
	for (int i = 0; i < entity_list.size();i++)
	{
		entity_list.at(i).setPosition(physicsManagerHandler->getBodyPosition(entity_list.at(i).getID()));
		entity_list.at(i).update();

		if (entity_list.at(i).getPosition().y > world_size.y) removeEntity(entity_list.at(i).getID());
	//	std::cout << "POZYCJA ENTITY NR " << i << " to [" << physicsManagerHandler->getBodyPosition(entity_list.at(i).getID()).x << " , " << physicsManagerHandler->getBodyPosition(entity_list.at(i).getID()).y << std::endl;
	//	std::cout << "ID ENTITY " << i << entity_list.at(i).getID() << " , PHYSICS ENTITY" << physicsManagerHandler->getBodyHandler(entity_list.at(i).getID())->getID() << std::endl;
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
	//system("cls");
	CEntity entity(next_id);
	entity_list.push_back(entity);

	entity_list.back().shape = sf::CircleShape(25);
	entity_list.back().setPosition(position);
	
	physicsManagerHandler->registerNewBody(next_id);
	physicsManagerHandler->getBodyHandler(next_id)->setPosition(position);
	physicsManagerHandler->addForce(entity_list.back(), sf::Vector2f(0, 3));

	next_id++;
	return &entity_list.back();
}

void CEntityManager::removeEntity(CEntity * entity)
{
	int idd = entity->getID();
	removeEntity(idd);
}

void CEntityManager::removeEntity(int idd)
{
	physicsManagerHandler->removeBody(idd);

	for (int i = 0; i < entity_list.size(); i++)
	{
		if (entity_list.at(i).getID() == idd)
		{
			entity_list.erase(entity_list.begin() + i);
		}
	}
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


