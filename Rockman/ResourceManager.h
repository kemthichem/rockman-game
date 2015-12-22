
#ifndef	_RESOURCE_MANAGER_H
#define _RESOURCE_MANAGER_H
#include <d3d9.h>
#include <d3dx9.h>
#include <list>
#include <string>
#include <map>

#include "utils.h"

//resource object
#define  IMAGE_ROCKMAN			"Resources/rockman.png"
#define  IMAGE_TILES			"Resources/tiles.png"
#define  IMAGE_ENEMIES			"Resources/enemies.png"
#define  IMAGE_EXPLOSIVE		"Resources/explosive.png"
#define  IMAGE_MASTER			"Resources/master.png"
#define  IMAGE_BG_MENU			"Resources/State/bg_menu.jpg"
#define  IMAGE_BG_CHANGE_STATE	"Resources/State/start.png"
#define  IMAGE_BG_ABOUT			"Resources/State/bg_about.jpg"
#define  IMAGE_BG_GAMEOVER		"Resources/State/bg_gameover.jpg"
#define  IMAGE_BG_HELP			"Resources/State/bg_help.jpg"
#define  IMAGE_BG_WIN			"Resources/State/bg_win.jpg"

//background
#define  IMAGE_BG "Resources/bg.jpg"

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
	static CResourceManager* GetInstance();
	static void Release();	
	
	void LoadResource(LPDIRECT3DDEVICE9);
	LPDIRECT3DTEXTURE9 GetSprite(string);
	LPDIRECT3DTEXTURE9 GetTileMap(string);
	LPDIRECT3DSURFACE9 GetSurface(string);
	~CResourceManager(void);
};
#endif
