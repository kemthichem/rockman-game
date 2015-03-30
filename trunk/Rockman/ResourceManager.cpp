#include "ResourceManager.h"

CResourceManager* CResourceManager::instance = NULL;
string CResourceManager::bgFileFath = "Resource/background1.png";
string CResourceManager::mapFilePath = "Map/map1.txt";
CResourceManager::CResourceManager(void)
{
	d3ddv = rockmanGame->GetDevice3d();
	LoadResource();
}

CResourceManager::~CResourceManager(void)
{
	mapSprite.clear();
	mapSurface.clear();
}

CResourceManager* CResourceManager::GetInstance()
{
	if(CResourceManager::instance==NULL)
		instance = new CResourceManager();
	return instance;
}

void CResourceManager::LoadResource()
{	
	mapSprite[IMAGE_ROCKMAN] = LoadTexture(d3ddv,IMAGE_ROCKMAN);
	mapSurface["Resource/background1.png"] = LoadSurface(d3ddv,"Resource/background1.png");
}

LPDIRECT3DTEXTURE9 CResourceManager::GetSprite( string spriteName )
{
	return mapSprite.at(spriteName);
}

LPDIRECT3DSURFACE9 CResourceManager::GetSurface( string surfaceName )
{
	return mapSurface.at(surfaceName);
}

char* CResourceManager::GetFilePathBG()
{
	char *cstr = new char[bgFileFath.length() + 1];
	strcpy_s(cstr, bgFileFath.size(), bgFileFath.c_str());
	cstr[bgFileFath.size()] = '\0';
	return cstr;
}
