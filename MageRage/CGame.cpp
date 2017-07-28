#include "CGame.h"

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

	return 1;
};

void CGame::OnEvent()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			close = false;
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
	entityManager->updateEntities();
	physicsManager->updateBodies();

};

int CGame::Load()
{
	return 1;
};

void CGame::Close()
{};