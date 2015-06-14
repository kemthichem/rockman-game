#include "PLayingGameState.h"
#include "MenuState.h"
#include "BigEye.h"
#include "Land.h"
#include "MoveMap.h"
#include "ChangeState.h"
#include "GameOverState.h"

int CPLayingGameState::g_LifeOfRockman = 3;

int CPLayingGameState::g_Stage = 1;

int CPLayingGameState::g_Score = 0;

CPLayingGameState::CPLayingGameState(CGameStateManager *_gameState)
{
	m_StateManager = _gameState;

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
}

void CPLayingGameState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	rockman->Render(_spriteHandle, _camera);
	quadTree->Render(_spriteHandle, _camera);

	DrawText();
}

void CPLayingGameState::Update(CInput* _input,float _time,CCamera* _camera)
{
	vector<CEntity*> listOb = quadTree->GetListObjectInRect(_camera->m_viewPort);
	quadTree->m_listObjectViewportToUpdate.push_back(rockman);

	if (!CMoveMap::g_IsMovingMap) {
		rockman->Update(_time, _camera, _input, listOb);
		quadTree->Update(_camera, _time);
	}
	else {
		_camera->MoveX(CMoveMap::g_DistanceMoveCameraY);
	}
	
	if (rockman->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}
	UpdateState();
}

void CPLayingGameState::Init()
{
	m_Map.LoadObjectFromFile("Resource//map//Map1.txt");	
	//Load tree
	quadTree = new CQuadTree();
	quadTree->LoadNodeInFile("Resource//map//Map1Tree.txt");

	quadTree->MapIdToObjectInTree(quadTree->m_nodeRoot, m_Map.m_ListObjects);
	//
	rockman = new CRockman(D3DXVECTOR3(200,1000,0));
}

void CPLayingGameState::DrawText()
{
	RECT r = {10, 0, 800, 100};

	/*Life*/
	string textToDraw = "Life: ";
	textToDraw.append(std::to_string(CPLayingGameState::g_LifeOfRockman));
	m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));


	/*Stage*/
	r.left = 375;
	textToDraw = "Stage: ";
	textToDraw.append(std::to_string(CPLayingGameState::g_Stage));
	m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));

	/*Score*/
	r.left = 650;
	textToDraw = "Score: ";
	textToDraw.append(std::to_string(CPLayingGameState::g_Score));
	m_StateManager->m_GraphicText->DrawText(NULL, textToDraw.c_str(), -1, &r, NULL, D3DCOLOR_XRGB(255,255,255));
}

void CPLayingGameState::UpdateState()
{
	if (rockman->IsDie()) {
		g_LifeOfRockman--;

		if (g_LifeOfRockman >= 0) {
			m_StateManager->ChangeState(new CChangeState(m_StateManager));
		} else
		{
			CPLayingGameState::g_LifeOfRockman = 3;
			CPLayingGameState::g_Score = 0;
			CPLayingGameState::g_Stage = 1;
			m_StateManager->ChangeState(new CGameOverState(m_StateManager));
		}
	}
}

