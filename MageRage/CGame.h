#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CPhysicsManager.h"
#include "CEntityManager.h"
#include "CTextureManager.h"
#include <SFML/System.hpp>
class CGame
{
private:
	CPhysicsManager *physicsManager;
	CEntityManager *entityManager;
	CTextureManager *textureManager;

	float FPS;
	
	sf::Clock fps_clock;

	int Load(); // called by init
	bool mouse;
	void OnEvent(); // 3 main funcs in da loop
	void OnLogic();
	void OnRender();
	void Close(); // called by exit

	sf::Vector2f getMousePosition();


	bool running;
	bool close;

public:

	int WINDOW_HEIGHT;
	int WINDOW_WIDTH;
	sf::RenderWindow* window;

	CGame();

	int Init();
	void Run(); // main loop function called by main

};

