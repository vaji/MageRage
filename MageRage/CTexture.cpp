#include "CTexture.h"



CTexture::CTexture(int idd)
{
	ID = idd;
}


CTexture::~CTexture()
{
}

int CTexture::getID()
{
	return ID;
}

std::string CTexture::getType()
{
	return std::string();
}
