#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CEntity.h"
class CEntityManager
{
private:
	std::vector<CEntity> entity_list;

public:
	CEntityManager();
	~CEntityManager();

	void updateEntities();
	void renderEntities(sf::RenderWindow *window);

};

