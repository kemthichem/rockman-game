#include "RockmanGame.h"
#ifndef	_RESOURCE_MANAGER_H
#define _RESOURCE_MANAGER_H

#define  IMAGE_ROCKMAN "Resource/rockman.png"
using namespace std;
class CResourceManager
{
private:
	LPDIRECT3DDEVICE9 d3ddv;
	static CResourceManager* instance;
	map<string, LPDIRECT3DTEXTURE9> mapSprite;
	map<string, LPDIRECT3DSURFACE9> mapSurface;
	void LoadResource();
	CResourceManager(void);
public:
	static string bgFileFath;
	static string mapFilePath;
	static char* GetFilePathBG();
	static CResourceManager* GetInstance();
	LPDIRECT3DTEXTURE9 GetSprite(string spriteName);
	LPDIRECT3DSURFACE9 GetSurface(string surfaceName);
	~CResourceManager(void);
};
#endif
