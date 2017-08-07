#include "CGame.h"

#include <iostream>
CGame::CGame()
{
	WINDOW_HEIGHT = 640;
	WINDOW_WIDTH = 860;
	FPS = 24;
	running = true;
	close = false;
	mouse = false;
	
};

int CGame::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MageRage2D");
	window->setVerticalSyncEnabled(true);
	
	physicsManager = new CPhysicsManager();
	entityManager = new CEntityManager(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	textureManager = new CTextureManager();

	entityManager->setPhysicsManagerHandler(physicsManager);
	entityManager->setTextureManagerHandler(textureManager);
	fps_clock.restart();
	Load();

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
			mouse = true;
			entityManager->addEntity("bandit", getMousePosition());
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
		mouse = false;
		OnEvent();
		OnLogic();
		OnRender();
		sf::sleep(sf::milliseconds(((1 / FPS) * 1000) - fps_clock.getElapsedTime().asMilliseconds()));
		if(mouse) entityManager->addEntity("bandit", getMousePosition());
		fps_clock.restart();
	}

	Close();
};

void CGame::OnLogic()
{
	physicsManager->update();
	entityManager->update();
};

int CGame::Load()
{
	textureManager->load();
	entityManager->load();

	return 1;
};

void CGame::Close()
{};


sf::Vector2f CGame::getMousePosition()
{
	sf::Vector2f vec = sf::Vector2f(sf::Mouse::getPosition().x - window->getPosition().x, sf::Mouse::getPosition().y - window->getPosition().y);
	return vec;


}