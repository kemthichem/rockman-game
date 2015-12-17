#include "PLayingGameState.h"
#include "MenuState.h"
#include "BigEye.h"
#include "Block.h"
#include "ChangeState.h"
#include "GameOverState.h"
#include "WinState.h"

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
	quadTree->m_listObjectViewportToUpdate.push_back(rockman);
	m_ScereryTile->Update(m_Camera->m_viewPort);

	if (CCamera::g_IsMoving) {
		m_Camera->MoveMap();

	} else {
		quadTree->Update(m_Camera, _time);
		rockman->Update(_time, m_Camera, _input, listOb);
	}

	if (rockman->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CChangeState(m_StateManager));
		return;
	}
	if (rockman->GetKeyDown()==DIK_L)
	{
		m_Camera->SetPosCamera(D3DXVECTOR2(4798,2084));//-600y
		rockman->SetPos(D3DXVECTOR3(5471, 2350, 0));
	}

	UpdateState();
}

void CPLayingGameState::Init()
{
	char* pathMap = NULL;

#pragma region
	//fixed stage
	g_Stage = 1;

	switch (g_Stage)
	{
	case 1:
		pathMap = "Resource//map//cut_man_stage.txt";
		break;
	case 2:
		//pathMap = "Resource//map//Map2.txt";
		break;
	case 3:
		//pathMap = "Resource//map//Map3.txt";
		break;
	default:
		break;
	}
	////Reset camera
	m_Camera->SetPosCamera(D3DXVECTOR2(0,0));	
	rockman = new CRockman(D3DXVECTOR3(100, 500,0));
	////Go boss map 1
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(4798,2084));//-600y
	//rockman = new CRockman(D3DXVECTOR3(5471, 2350, 0));
	////Go boss map 2
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(3552,2344));
	//rockman = new CRockman(D3DXVECTOR3(3580,1000,0));
	////Go boss map 3
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(3552,2344));
	//rockman = new CRockman(D3DXVECTOR3(3580,1000,0));
#pragma endregion

	quadTree = new CQuadTree();

	//Load to quadTree and camera path point from map.
	m_Map.LoadMap(pathMap, quadTree, m_Camera);
	//create scenery tile
	m_ScereryTile = new CSceneryTile(CResourceManager::GetInstance()->GetSprite(IMAGE_MAP_CUTMAN),
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
	DrawText();
}
