#include "ResourceManager.h"

CResourceManager* CResourceManager::instance = NULL;
string CResourceManager::mPathFileBg = "Resource/background1.png";
string CResourceManager::mPathFileMap = "Map/map1.txt";

CResourceManager::CResourceManager(void)
{

}

CResourceManager::~CResourceManager(void)
{
	mMapTexture.clear();
	mMapSurface.clear();
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

	mMapTexture[IMAGE_ROCKMAN] = CUtils::LoadTexture(mD3ddv,IMAGE_ROCKMAN);
	mMapSurface["Resource/background1.png"] = CUtils::LoadSurface(mD3ddv,"Resource/background1.png");
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

