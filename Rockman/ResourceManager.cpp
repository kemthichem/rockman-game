#include "ResourceManager.h"

CResourceManager* CResourceManager::instance = NULL;
string CResourceManager::mPathFileBg = "Resource/background1.png";
string CResourceManager::mPathFileMap = "Map/map1.txt";

CResourceManager::CResourceManager(void)
{

}

CResourceManager::~CResourceManager(void)
{	
	for (map<string, LPDIRECT3DTEXTURE9>::iterator it = mMapTexture.begin(); it != mMapTexture.end(); ++it)
	{
			it->second->Release();
	}
	for (map<string, LPDIRECT3DSURFACE9>::iterator it = mMapSurface.begin(); it != mMapSurface.end(); ++it)
	{
			it->second->Release();
	}

	mMapSurface.clear();
	mMapTexture.clear();
}

CResourceManager* CResourceManager::GetInstance()
{
	if(CResourceManager::instance==NULL)
		instance = new CResourceManager();
	return instance;
}

void CResourceManager::LoadResource(LPDIRECT3DDEVICE9 _d3ddv)
{	
	mD3ddv = _d3ddv;

	mMapTexture[IMAGE_ROCKMAN] = CUtils::LoadTexture(mD3ddv, IMAGE_ROCKMAN);
	mMapTexture[IMAGE_TILES] = CUtils::LoadTexture(mD3ddv, IMAGE_TILES);
	mMapTexture[IMAGE_ENEMIES] = CUtils::LoadTexture(mD3ddv, IMAGE_ENEMIES);
	mMapTexture[IMAGE_EXPLOSIVE] = CUtils::LoadTexture(mD3ddv, IMAGE_EXPLOSIVE);	
	mMapTexture[IMAGE_MASTER] = CUtils::LoadTexture(mD3ddv, IMAGE_MASTER);
	mMapTexture[IMAGE_BG_MENU] = CUtils::LoadTexture(mD3ddv, IMAGE_BG_MENU);
	mMapTexture[IMAGE_BG_CHANGE_STATE] = CUtils::LoadTexture(mD3ddv, IMAGE_BG_CHANGE_STATE);
	mMapTexture[IMAGE_BG_ABOUT] = CUtils::LoadTexture(mD3ddv, IMAGE_BG_ABOUT);
	mMapTexture[IMAGE_BG_GAMEOVER] = CUtils::LoadTexture(mD3ddv, IMAGE_BG_GAMEOVER);
	mMapTexture[IMAGE_BG_HELP] = CUtils::LoadTexture(mD3ddv, IMAGE_BG_HELP);
	mMapTexture[IMAGE_BG_WIN] = CUtils::LoadTexture(mD3ddv, IMAGE_BG_WIN);


	//hard code resoure map
	mMapTexture[IMAGE_MAP_CUTMAN] = CUtils::LoadTexture(mD3ddv, IMAGE_MAP_CUTMAN);

	//load background
	mMapSurface[IMAGE_BG] = CUtils::LoadSurface(mD3ddv,IMAGE_BG);
}

LPDIRECT3DTEXTURE9 CResourceManager::GetSprite( string spriteName )
{
	return mMapTexture.at(spriteName);
}

LPDIRECT3DSURFACE9 CResourceManager::GetSurface( string surfaceName )
{
	return mMapSurface.at(surfaceName);
}

char* CResourceManager::GetFilePathBG()
{
	char *cstr = new char[mPathFileBg.length() + 1];
	strcpy_s(cstr, mPathFileBg.size(), mPathFileBg.c_str());
	cstr[mPathFileBg.size()] = '\0';
	return cstr;
}

void CResourceManager::Release()
{
	if(CResourceManager::instance!=NULL)
		delete instance;
}

