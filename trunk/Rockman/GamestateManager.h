#ifndef GAMESTATEMANAGER_H_
#define GAMESTATEMANAGER_H_

//#include "DxGraphic.h"
#include "Input.h"
#include "Camera.h"
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>
//#include"LoadingState.h"
//#include"MenuState.h"
using namespace std;
class CGameState;
class CGameStateManager
{
private:
	//CResourceManager *m_resource;
	LPD3DXSPRITE m_spriteHandle;
	vector<CGameState*> m_ListState;
public:
	HWND m_wndHandle;
	LPD3DXFONT m_GraphicText;
	CGameState* m_nextState;
	CGameStateManager(void);
	~CGameStateManager(void);
	void Init(HWND, LPD3DXSPRITE, LPD3DXFONT); 
	void CleanUp();
	void InitFirstState(CGameState*);
	void ChangeState(CGameState*);
	void Update(float,CCamera*, CInput*);
	void Draw(LPD3DXSPRITE,CCamera*);
};
#endif


