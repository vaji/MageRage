#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CTexture.h"
#include <string>
#include <vector>
#include <iostream>


class CTextureManager
{
private:

	std::vector<CTexture> texture_list;
	int next_id;

public:

	CTextureManager();
	~CTextureManager();

	void load();

	bool loadTexture(std::string file_path);
	sf::Texture* getTexture(int idd);

};

