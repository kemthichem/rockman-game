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

char* pathMap = "Resource//map//cut_man_stage.txt";

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
POINT array[20] = { {129, 111}, {897, 111}, {897, 232}, {897, 472}, {897		,712 },{897		,952 },{897		,1071},{1409	,1071}    ,{1409	,1192}    ,{1409	,1432}    ,{1409	,1672}    ,{1409	,1914}    ,{1409	,2031}    ,{1921	,2031}    ,{1921	,1914}    ,{1921	,1672}    ,{1921	,1432}    ,{1921	,1311}    ,{2304	,1311}    ,{3216	,1311}};
void CPLayingGameState::Init()
{
	//char* pathMap = "Resource//map//cut_man_stage.txt";

#pragma region  
	char* pathTree = ""; 

	//fixed stage
	g_Stage = 1;

	switch (g_Stage)
	{
	case 1:
		//pathMap = "Resource//map//Map1Old.txt";
		pathTree = "Resource//map//Map1OldTree.txt";
		break;
	case 2:
		//pathMap = "Resource//map//Map2.txt";
		pathTree = "Resource//map//Map2Tree.txt";
		break;
	case 3:
		//pathMap = "Resource//map//Map3.txt";
		pathTree = "Resource//map//Map3Tree.txt";
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

	//pathMap = "Resource//map//cut_man_stage.txt";



	//Load to quadtree tree
	quadTree = new CQuadTree();
	m_Map.LoadMap(pathMap, quadTree);	
	//quadTree->LoadNodeInFile(pathTree);
	quadTree->MapIdToObjectInTree(quadTree->m_nodeRoot, m_Map.m_ListObjects);


	//create scenery tile
	m_ScereryTile = new CSceneryTile(CResourceManager::GetInstance()->GetSprite(IMAGE_MAP_CUTMAN),
		m_Map.m_ArrayMapTile, m_Map.rowTitle, m_Map.colTitle, m_Map.countTile);


	//Set camera
	POINT* cameraPathPoint = getCameraPath();

	m_Camera->Initialize(cameraPathPoint, 20);
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

POINT *CPLayingGameState::getCameraPath()
{	
	vector<string> vectorDataFromMap = CUtils::LoadDataFromFile(pathMap);
	int start, size;
	for (int i = 0; i < vectorDataFromMap.size(); i++)
	{
		if (vectorDataFromMap.at(i).compare("#Camera_Path_Point") == 0)
		{
			// size point path camera is next row
			// start point is next 2 row
			size = atoi(vectorDataFromMap.at(i + 1).c_str());
			start = i + 2;
			break;
		}
	}

	vector<string> vectorStringPoint;
	POINT* arrayPoint = new POINT[size];	
	POINT tempPoint;

	for (int j = start; j < start + size; j++)
	{
		vectorStringPoint = CUtils::SplitString(vectorDataFromMap[j], CUtils::charSplit);
		tempPoint.x = atoi(vectorStringPoint.at(0).c_str());
		tempPoint.y = atoi(vectorStringPoint.at(1).c_str());
		arrayPoint[j - start] = tempPoint;
	}

	return arrayPoint;
}