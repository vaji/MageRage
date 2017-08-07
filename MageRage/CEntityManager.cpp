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

void CEntityManager::setTextureManagerHandler(CTextureManager * manager)
{
	textureManagerHandler = manager;
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
		entity_list.at(i).setPosition(physicsManagerHandler->getBodyPosition(entity_list.at(i).getID()));
		entity_list.at(i).update();

		if (entity_list.at(i).getPosition().y > world_size.y) removeEntity(entity_list.at(i).getID());
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

	// by type
	createEntityByType(type);
	entity_list.back().setID(next_id);
	entity_list.back().setPosition(position);

	// physics part of entity creation
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

// CREATES ENTITY FROM TEMPLATE AND REGISTERS IT IN LIST
void CEntityManager::createEntityByType(std::string type)
{
	CEntity entity;
	for (int i = 0; i< entity_types.size(); i++)
	{
		if (entity_types[i].getType() == type)
		{
			entity = entity_types[i];
		}
	}
	if (type == "bandit") {
		entity.animator.addAnimation("run", 0, 160, 80, 80, 3);
			entity.animator.setAnimation("run", true);
	}
	entity_list.push_back(entity); // register

}



// ***************************************************************************************
// LOADING
void CEntityManager::loadEntityTypes()
{
	// read xml to load templates
	

	CEntity ent(-1, textureManagerHandler->getTexture(0));
	ent.setType("bandit");
	
	//ent.animator.setAnimation("run",false);
	entity_types.push_back(ent);


	CEntity ent2 = CEntity(-1);
	ent2.setType("circle");
	entity_types.push_back(ent2);

}

void CEntityManager::load()
{
	loadEntityTypes();
}



