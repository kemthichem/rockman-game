#include "MarioGame.h"
#ifndef _RESOURCE_H
#define _RESOURCE_H
#pragma region define image
#define IMAGE_BG1			"Resource/background1.png"
#define IMAGE_BG2			"Resource/background2.png"
#define  IMAGE_MARIOSMALL "Resource/marioImage/mario_small.png"
#define  IMAGE_MARIOLARGE  "Resource/marioImage/mario_large.png"
#define  IMAGE_MARIOGUN "Resource/marioImage/mario_gun.png"
#define  IMAGE_MARIOCONVERT "Resource/marioImage/mario_convert.png"
#define  IMAGE_BULLET "Resource/bullet.png"
#define  IMAGE_TURTLE "Resource/turtle.png"
#define  IMAGE_BLOCKS "Resource/blocks.png"
#define  IMAGE_ITEM "Resource/item.png"
#define  IMAGE_ENEMY "Resource/enemy.png"
#define  IMAGE_EATO1 "Resource/eato.png"
#define  IMAGE_EATOEX "Resource/eatoex.png"
#define  IMAGE_EATO "Resource/eato1.png"
#define  IMAGE_PIPE "Resource/pipe.png"
#define  IMAGE_SCENERY "Resource/Scenery.png"
#define  IMAGE_BGSCREEN "Resource/Menu/background.png"
#define  IMAGE_BGGAMEOVER "Resource/Menu/gameover.png"
#define  IMAGE_BGGAMEWIN "Resource/Menu/gamewin.png"
#define  IMAGE_BGHELP "Resource/Menu/help.png"
#define  IMAGE_BLANK	"Resource/Menu/blank.png"
#define  IMAGE_BUTTON "Resource/Menu/button.png"
#define  IMAGE_LOADING "Resource/Menu/loading.png"
#define  IMAGE_LOADINGBG "Resource/Menu/loading_bg.png"
#define  IMAGE_LOADINGFR "Resource/Menu/loading_fr.png"
#define  IMAGE_LIFE "Resource/life.png"
#pragma endregion define image

class CRescource
{
private:
	LPDIRECT3DDEVICE9 d3ddv;
	static CRescource* instance;
	map<string, LPDIRECT3DTEXTURE9> mapSprite;
	map<string, LPDIRECT3DSURFACE9> mapSurface;
	void LoadResource();
	CRescource(void);

public:
	static string bgFileFath;
	static string mapFilePath;
	static char* GetFilePathBG();
	static CRescource* GetInstance();
	LPDIRECT3DTEXTURE9 GetSprite(string spriteName);
	LPDIRECT3DSURFACE9 GetSurface(string surfaceName);
		~CRescource(void);
};

#endif // _RESOURCE_H
