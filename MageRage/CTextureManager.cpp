#include "CTextureManager.h"



CTextureManager::CTextureManager()
{
	next_id = 0;
}


CTextureManager::~CTextureManager()
{
}

void CTextureManager::load()
{
	std::string path = "sprite/bandit_0.png";
	loadTexture(path);

}


// loading of textures at the begininng. it setups ids for each texture ensuring that each sprite will refer to the right texture
// loading additional textures during run will mess up references and it will crash 
bool CTextureManager::loadTexture(std::string file_path)
{
	sf::Image img;
	CTexture texture(next_id);
	if (!img.loadFromFile(file_path))
	{
		std::cout << "There was error loading texture " + file_path << std::endl;
		return false;
	}
	img.createMaskFromColor(sf::Color(0, 0, 0));
	texture.loadFromImage(img);
	texture_list.push_back(texture);
	next_id++;
}

sf::Texture * CTextureManager::getTexture(int idd)
{
	for (int i = 0; i < texture_list.size(); i++)
	{
		if (texture_list.at(i).getID() == idd) return &texture_list.at(i);
	}
}
