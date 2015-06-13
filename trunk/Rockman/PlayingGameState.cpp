﻿#include "PLayingGameState.h"
#include "MenuState.h"
#include "BigEye.h"
#include "Land.h"
#include "MoveMap.h"

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
}

void CPLayingGameState::Update(CInput* _input,float _time,CCamera* _camera)
{
	vector<CEntity*> listOb = quadTree->GetListObjectInRect(_camera->m_viewPort);
	quadTree->m_listObjectViewportToUpdate.push_back(rockman);

	if (!CMoveMap::g_IsMovingMap) {
		rockman->Update(_time, _camera, _input, listOb);
		quadTree->Update(_camera, _time);
	} else
		_camera->Move(CMoveMap::g_DistanceMoveCameraY);

	if (rockman->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CMenuState(m_StateManager));
		return;
	}
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
