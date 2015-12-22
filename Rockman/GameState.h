#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include <d3d9.h>
#include <d3dx9.h>
#include "Input.h"
#include "Sprite.h"
enum GameStateId
{
	GAME_LOADING,GAME_MENU,GAME_PLAY,GAME_CONTINUE,GAME_OPTIONS,GAME_EXIT,GAME_ABOUT
};

class CGameStateManager;
class CGameState
{
protected:
	GameStateId m_id;
	CGameStateManager* m_StateManager;
	CSprite* m_background;
	float m_time;
public:
	CGameState(void);
	virtual ~CGameState(void);
	CGameState(CGameStateManager*);
	virtual void Init();
	virtual void Update(CInput* ,float);
	virtual void Render(LPD3DXSPRITE);
	void StopSoundBackGound();
	virtual void RenderTextAndSurface(){};
};
#endif
