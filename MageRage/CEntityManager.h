#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CEntity.h"
#include <string>
#include "CPhysicsManager.h"

class CEntityManager
{
private:

	
	std::vector<CEntity> entity_types;

	CPhysicsManager *physicsManagerHandler;
	sf::Vector2f world_size;

	CEntity* createEntityByType(std::string type, sf::Vector2f position);
	
	void loadEntityTypes();
	int next_id;
public:
	std::vector<CEntity> entity_list;

	CEntityManager();
	CEntityManager(sf::Vector2f world);
	~CEntityManager();

	void setPhysicsManagerHandler(CPhysicsManager *manager);
	
	CEntity* addEntity(std::string name, sf::Vector2f position, bool gravity = true);

	void removeEntity(CEntity* entity);
	void removeEntity(int idd);

	void update(); // 1 - update entities by themselves
	 
	void updateEntities(); // 1st step 
	void load();
	void renderEntities(sf::RenderWindow *window);

};

