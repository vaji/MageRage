#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>


class CTexture :
	public sf::Texture
{
private:

	int ID;
	std::string type;

public:

	CTexture(int idd);
	~CTexture();

	int getID();
	std::string getType();

};

