#include "Rescource.h"

CRescource* CRescource::instance = NULL;
string CRescource::bgFileFath = "Resource/background1.png";
string CRescource::mapFilePath = "Map/map1.txt";
CRescource::CRescource(void)
{
	d3ddv = marioGame->GetDevice3d();
	LoadResource();
}

CRescource::~CRescource(void)
{
	mapSprite.clear();
	mapSurface.clear();
}

CRescource* CRescource::GetInstance()
{
	if(CRescource::instance==NULL)
		instance = new CRescource();
	return instance;
}

void CRescource::LoadResource()
{	
	mapSprite[IMAGE_MARIOSMALL] = LoadTexture(d3ddv,IMAGE_MARIOSMALL);
	mapSprite[IMAGE_MARIOLARGE] = LoadTexture(d3ddv,IMAGE_MARIOLARGE);
	mapSprite[IMAGE_MARIOGUN] = LoadTexture(d3ddv,IMAGE_MARIOGUN);
	mapSprite[IMAGE_MARIOCONVERT] = LoadTexture(d3ddv,IMAGE_MARIOCONVERT);
	mapSprite[IMAGE_EATO1] = LoadTexture(d3ddv,IMAGE_EATO1);
	mapSprite[IMAGE_EATO] = LoadTexture(d3ddv,IMAGE_EATO);
	mapSprite[IMAGE_EATOEX] = LoadTexture(d3ddv,IMAGE_EATOEX);
	mapSprite[IMAGE_ENEMY] = LoadTexture(d3ddv,IMAGE_ENEMY);
	mapSprite[IMAGE_BLOCKS] = LoadTexture(d3ddv,IMAGE_BLOCKS);
	mapSprite[IMAGE_ITEM] = LoadTexture(d3ddv,IMAGE_ITEM);
	mapSprite[IMAGE_PIPE] = LoadTexture(d3ddv,IMAGE_PIPE);
	mapSprite[IMAGE_SCENERY] = LoadTexture(d3ddv,IMAGE_SCENERY);
	mapSprite[IMAGE_TURTLE] = LoadTexture(d3ddv,IMAGE_TURTLE);
	mapSprite[IMAGE_BULLET] = LoadTexture(d3ddv,IMAGE_BULLET);
	mapSprite[IMAGE_BLANK] = LoadTexture(d3ddv,IMAGE_BLANK);
	mapSprite[IMAGE_LOADING] = LoadTexture(d3ddv,IMAGE_LOADING);
	mapSprite[IMAGE_LOADINGBG] = LoadTexture(d3ddv,IMAGE_LOADINGBG);
	mapSprite[IMAGE_BGSCREEN] = LoadTexture(d3ddv,IMAGE_BGSCREEN);
	mapSprite[IMAGE_BGGAMEOVER] = LoadTexture(d3ddv,IMAGE_BGGAMEOVER);
	mapSprite[IMAGE_BGGAMEWIN] = LoadTexture(d3ddv,IMAGE_BGGAMEWIN);
	mapSprite[IMAGE_BGHELP] = LoadTexture(d3ddv,IMAGE_BGHELP);
	mapSprite[IMAGE_BUTTON] = LoadTexture(d3ddv,IMAGE_BUTTON);
	mapSprite[IMAGE_LIFE] = LoadTexture(d3ddv,IMAGE_LIFE);
	
	//------------
	mapSurface[IMAGE_BLANK] = LoadSurface(d3ddv,IMAGE_BLANK);
	mapSurface[IMAGE_BG1] = LoadSurface(d3ddv,IMAGE_BG1);
	mapSurface[IMAGE_BG2] = LoadSurface(d3ddv,IMAGE_BG2);
	mapSurface[IMAGE_LOADINGFR] = LoadSurface(d3ddv,IMAGE_LOADINGFR);
}

LPDIRECT3DTEXTURE9 CRescource::GetSprite( string spriteName )
{
	return mapSprite.at(spriteName);
}

LPDIRECT3DSURFACE9 CRescource::GetSurface( string surfaceName )
{
	return mapSurface.at(surfaceName);
}

char* CRescource::GetFilePathBG()
{
	char *cstr = new char[bgFileFath.length() + 1];
	strcpy(cstr, bgFileFath.c_str());
	cstr[bgFileFath.size()] = '\0';
	return cstr;
}
