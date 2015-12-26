#include "PLayingGameState.h"
#include "MenuState.h"
#include "Block.h"
#include "ChangeState.h"
#include "GameOverState.h"
#include "WinState.h"
#include "Config.h"
#include "Define.h"
#include "ResourceManager.h"

using namespace std;

ChangeState CPLayingGameState::g_ChangeState = CHANGE_NONE;

int CPLayingGameState::g_LifeOfRockman = 2;

int CPLayingGameState::g_Stage = 1;

int CPLayingGameState::g_Score = 0;

CPLayingGameState::CPLayingGameState(CGameStateManager *_gameState)
{
	m_StateManager = _gameState;

	m_Camera = new CCamera();

	rockman = NULL;
	quadTree = NULL;
}

CPLayingGameState::CPLayingGameState(void)
{

}

CPLayingGameState::~CPLayingGameState(void)
{
	if (rockman) {
		delete rockman;
		rockman = NULL;
	}

	if (quadTree) {
		delete quadTree;
		quadTree = NULL;
	}

	if (m_ScereryTile) {
		delete m_ScereryTile;
	}

	if (m_Camera)
		delete m_Camera;

	CConfig::ReleaseConfig();
}

void CPLayingGameState::Render(LPD3DXSPRITE _spriteHandle)
{
	rockman->Render(_spriteHandle, m_Camera);
	quadTree->Render(_spriteHandle, m_Camera);

	m_ScereryTile->Render(_spriteHandle, m_Camera);
}

void CPLayingGameState::Update(CInput* _input,float _time)
{
	vector<CEntity*> listOb = quadTree->GetListObjectInRect(m_Camera->m_viewPort);
	quadTree->AddObjectToList(quadTree->m_listObjectViewportCheckCollision, rockman);
	m_ScereryTile->Update(m_Camera->m_viewPort);

	if (CCamera::g_IsMoving) {
		m_Camera->MoveMap();

	} else {
		quadTree->Update(m_Camera, _time);
		rockman->Update(_time, m_Camera, _input, listOb);
	}

	if (rockman->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}

	//if (rockman->GetKeyDown()==DIK_L)
	//{
	//	m_Camera->SetPosCamera(D3DXVECTOR2(4798,2084));//-600y
	//	rockman->SetPos(D3DXVECTOR3(5471, 2350, 0));
	//}

	UpdateState();
}

void CPLayingGameState::Init()
{
	char* pathStageMap = PATH_STAGE_MAP;
	m_Map.LoadMapStages(pathStageMap);
	string pathMap = "";
	string pathMapTile = "";
	bool rVal = m_Map.GetMap(g_Stage, pathMap, pathMapTile);
	if (!rVal) {
		m_StateManager->ChangeState(new CChangeState(m_StateManager));
	}
	////Reset camera
	m_Camera->SetPosCamera(D3DXVECTOR2(0,0));	
	quadTree = new CQuadTree();

	//Load to quadTree and camera path point from map.
	m_Map.LoadMap(pathMap.c_str(), quadTree, m_Camera);

	//rockman = new CRockman(D3DXVECTOR3(CConfig::ValueOf(KEY_RM_POS_INIT_X), CConfig::ValueOf(KEY_RM_POS_INIT_Y),0));
	rockman = new CRockman(D3DXVECTOR3(CCamera::g_PosCamera.x + WIDTH_SCREEN / 2, CCamera::g_PosCamera.y,0));
	//create scenery tile
	m_ScereryTile = new CSceneryTile(CResourceManager::GetInstance()->GetTileMap(pathMapTile),
		m_Map.m_ArrayMapTile, m_Map.rowTitle, m_Map.colTitle, m_Map.countTile);
}

void CPLayingGameState::DrawText()
{
	RECT r = {10, 30, 800, 100};

	///*Life*/
	string textToDraw = "Life: ";
	//textToDraw.append(std::to_string(CPLayingGameState::g_LifeOfRockman));
	//m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));


	/*Stage*/
	r.left = 375;
	textToDraw = "00000";
	textToDraw.append(std::to_string(CPLayingGameState::g_Score));
	m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));

	///*Score*/
	//r.left = 650;
	//textToDraw = "Score: ";
	//textToDraw.append(std::to_string(CPLayingGameState::g_Score));
	//m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));
}

void CPLayingGameState::UpdateState()
{
	switch (g_ChangeState)
	{
	case CHANGE_NONE:
		break;
	case CHANGE_NEXT:
		g_Stage++;
		if (g_Stage > 3) {
			m_StateManager->ChangeState(new CWinState(m_StateManager));
		} else {
			m_StateManager->ChangeState(new CChangeState(m_StateManager));
		}
		break;
	case CHANGE_FAIL:
		g_LifeOfRockman--;
		if (g_LifeOfRockman >= 0) {
			m_StateManager->ChangeState(new CChangeState(m_StateManager));
		} else
		{
			CPLayingGameState::g_LifeOfRockman = 2;
			CPLayingGameState::g_Score = 0;
			CPLayingGameState::g_Stage = 1;
			m_StateManager->ChangeState(new CGameOverState(m_StateManager));
		}
		break;
	default:
		break;
	}
	g_ChangeState = CHANGE_NONE;
}

void CPLayingGameState::RenderTextAndSurface()
{
	//DrawText();
}
