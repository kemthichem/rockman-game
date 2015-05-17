
#ifndef	_RESOURCE_MANAGER_H
#define _RESOURCE_MANAGER_H
#include <d3d9.h>
#include <d3dx9.h>
#include <list>
#include <string>
#include <map>

#include "utils.h"

#define  IMAGE_ROCKMAN "Resource/rockman.png"
#define  IMAGE_TILES "Resource/tiles.png"
#define  IMAGE_ENEMIES "Resource/enemies.png"
#define  IMAGE_ITEMS "Resource/items.png"


using namespace std;
class CResourceManager
{
private:
	LPDIRECT3DDEVICE9 mD3ddv;
	static CResourceManager* instance;
	map<string, LPDIRECT3DTEXTURE9> mMapTexture;
	map<string, LPDIRECT3DSURFACE9> mMapSurface;
	CResourceManager(void);
public:
	static string mPathFileBg;
	static string mPathFileMap;
	static char* GetFilePathBG();
	static CResourceManager* GetInstance();
	static void Release();
	void LoadResource(LPDIRECT3DDEVICE9);
	LPDIRECT3DTEXTURE9 GetSprite(string);
	LPDIRECT3DSURFACE9 GetSurface(string);
	~CResourceManager(void);
};
#endif
