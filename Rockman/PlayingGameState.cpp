﻿#include "PLayingGameState.h"
#include "MenuState.h"
#include "BigEye.h"
#include "Land.h"
#include "MoveMap.h"
#include "ChangeState.h"
#include "GameOverState.h"
#include "WinState.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

ChangeState CPLayingGameState::g_ChangeState = CHANGE_NONE;

int CPLayingGameState::g_LifeOfRockman = 2;

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

	if (m_ScereryTile) {
		delete m_ScereryTile;
	}
}

void CPLayingGameState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	rockman->Render(_spriteHandle, _camera);
	quadTree->Render(_spriteHandle, _camera);

	m_ScereryTile->Render(_spriteHandle, _camera);
}

void CPLayingGameState::Update(CInput* _input,float _time,CCamera* _camera)
{
	vector<CEntity*> listOb = quadTree->GetListObjectInRect(_camera->m_viewPort);
	quadTree->m_listObjectViewportToUpdate.push_back(rockman);
	m_ScereryTile->Update(_camera->m_viewPort);

	switch (CMoveMap::g_TypeMove)
	{
	case TypeMove::MOVEX:
		_camera->MoveX(CMoveMap::g_DistanceMoveCameraX);
		break;
	case TypeMove::MOVEY:
		_camera->MoveY(CMoveMap::g_DistanceMoveCameraY);
		break;
	case TypeMove::MOVENONE:
	default:
		rockman->Update(_time, _camera, _input, listOb);
		quadTree->Update(_camera, _time);
		break;
	}

	if (rockman->GetKeyDown()==DIK_ESCAPE)
	{
		m_StateManager->ChangeState(new CChangeState(m_StateManager));
		return;
	}
	if (rockman->GetKeyDown()==DIK_L)
	{
		m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(4798,2084));//-600y
		rockman->SetPos(D3DXVECTOR3(5471, 2350, 0));
	}

	UpdateState();
}

void CPLayingGameState::Init()
{
	char* pathMap = "Resource//map//cut_man_stage.txt";

	//#pragma region fuck 
	//char* pathTree = ""; 

	////fixed stage
	//g_Stage = 1;

	//switch (g_Stage)
	//{
	//case 1:
	//	pathMap = "Resource//map//Map1Old.txt";
	//	pathTree = "Resource//map//Map1OldTree.txt";
	//	break;
	//case 2:
	//	pathMap = "Resource//map//Map2.txt";
	//	pathTree = "Resource//map//Map2Tree.txt";
	//	break;
	//case 3:
	//	pathMap = "Resource//map//Map3.txt";
	//	pathTree = "Resource//map//Map3Tree.txt";
	//	break;
	//default:
	//	break;
	//}
	//Reset camera
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(0,0));	
	//rockman = new CRockman(D3DXVECTOR3(100, 500,0));

	//Go boss map 1
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(4798,2084));//-600y
	//rockman = new CRockman(D3DXVECTOR3(5471, 2350, 0));

	//Go boss map 2
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(3552,2344));
	//rockman = new CRockman(D3DXVECTOR3(3580,1000,0));

	//Go boss map 3
	//m_StateManager->GetCamera()->SetPosCamera(D3DXVECTOR2(3552,2344));
	//rockman = new CRockman(D3DXVECTOR3(3580,1000,0));

	//m_Map.LoadObjectFromFile(pathMap);	
	//#pragma endregion fuck 

	//hard code to demo

	//int countTile = 6;

	// define mapFile
	ifstream mapFile;

	// line of mapFile
	string line;

	// data from mapFile read into vector
	vector<string> listMap;

	// read file map and push data into a vecto
	mapFile.open(pathMap);
	if (mapFile.is_open())
	{
		while (getline(mapFile,line))
		{
			listMap.push_back(line);
		}
	}

	istringstream istringstreamSize(listMap[2]);
	istream_iterator<std::string> istream_iteratorSize(istringstreamSize), end;
	// vector save row, column
	vector<string> sizeMap (istream_iteratorSize, end);

	// get row
	const int row = atoi(sizeMap.at(0).c_str());

	// get column
	int column = atoi(sizeMap.at(1).c_str());

	// declare a 2 demen array to save tile 
	//int **arrayTile = new int *[row];

	//FIXME - help me define a array
	int arrayTile[80][130];

	for (int i = 0; i < row; i++)
	{
		//arrayTile[i] = new int[column];
		istringstream istringstreamTile(listMap[i + 4]);
		istream_iterator<std::string> istream_iteratorTile(istringstreamTile), endTile;
		// vector save data of a row
		vector<string> rowTitle (istream_iteratorTile, endTile);

		for (int j = 0; j < column; j++)
		{
			arrayTile[i][j] = atoi(rowTitle.at(j).c_str());
		}

	}

	int k = 10;


	/*0	1	0	2	
	3	-1	3	4	
	5	5	5	5*/
	//arrayTile[0][0] = 0;
	//arrayTile[0][1] = 1;
	//arrayTile[0][2] = 0;
	//arrayTile[0][3] = 2;

	//arrayTile[1][0] = 3;
	//arrayTile[1][1] = -1;
	//arrayTile[1][2] = 3;
	//arrayTile[1][3] = 4;

	//arrayTile[2][0] = 5;
	//arrayTile[2][1] = 5;
	//arrayTile[2][2] = 5;
	//arrayTile[2][3] = 5;

	//create scenery tile
	//	m_ScereryTile = new CSceneryTile(CResourceManager::GetInstance()->GetSprite(IMAGE_MAP_CUTMAN), arrayTile, row, col, countTile);


	//Load tree
	//	quadTree = new CQuadTree();
	//quadTree->LoadNodeInFile(pathTree);

	//	quadTree->MapIdToObjectInTree(quadTree->m_nodeRoot, m_Map.m_ListObjects);

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
