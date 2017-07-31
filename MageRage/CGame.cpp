#include "CGame.h"

#include <iostream>
CGame::CGame()
{
	running = true;
	close = false;

};

int CGame::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
	window->setVerticalSyncEnabled(true);
	
	physicsManager = new CPhysicsManager();
	entityManager = new CEntityManager();
	textureManager = new CTextureManager();

	entityManager->setPhysicsManagerHandler(physicsManager);


	return 1;
};

void CGame::OnEvent()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			close = false;

		if (event.type == sf::Event::MouseButtonPressed)
		{
			std::cout << "nowy obiekt";
			entityManager->addEntity("elo", getMousePosition());
			std::cout << " PO DODANIU FORCE W CGAME: " << entityManager->entity_list.back().getBody()->force_list.size() << std::endl;
		}
			
	}
};

void CGame::OnRender()
{
	window->clear(sf::Color::Black);

	// draw background
	entityManager->renderEntities(window);

	window->display();


};

void CGame::Run()
{
	while(!close)
	{
		OnEvent();
		OnLogic();
		OnRender();
	}

	Close();
};

void CGame::OnLogic()
{
	entityManager->update();
	physicsManager->update();
};

int CGame::Load()
{
	return 1;
};

void CGame::Close()
{};


sf::Vector2f CGame::getMousePosition()
{
	sf::Vector2f vec = sf::Vector2f(sf::Mouse::getPosition().x - window->getPosition().x, sf::Mouse::getPosition().y - window->getPosition().y);
	return vec;


}