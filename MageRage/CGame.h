#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CPhysicsManager.h"
#include "CEntityManager.h"
#include "CTextureManager.h"

class CGame
{
private:
	CPhysicsManager *physicsManager;
	CEntityManager *entityManager;
	CTextureManager *textureManager;

	int Load(); // called by init

	void OnEvent(); // 3 main funcs in da loop
	void OnLogic();
	void OnRender();
	void Close(); // called by exit


	bool running;
	bool close;

public:
	sf::RenderWindow* window;

	CGame();

	int Init();
	void Run(); // main loop function called by main

};

