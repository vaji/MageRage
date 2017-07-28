#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CEntity.h"
#include <string>

class CEntityManager
{
private:

	std::vector<CEntity> entity_list;
	std::vector<CEntity> entity_types;

	CEntity createEntityByType(std::string type);
	
	void loadEntityTypes();
public:
	CEntityManager();
	~CEntityManager();
	
	CEntity* addEntity(std::string name, sf::Vector2f position);
	void removeEntity(CEntity* entity);

	void update(); // 1 - update entities by themselves
	 
	void updateEntities(); // 1st step 
	void load();
	void renderEntities(sf::RenderWindow *window);

};

