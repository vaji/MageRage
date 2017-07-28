#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Globals.h"

void init();

CGame gameObject;

int main()
{
	init();

	gameObject.Init();
	gameObject.Run();

	return 0;
}


void init()
{
	gameObject = CGame();
	textureManager = CTextureManager();
}

