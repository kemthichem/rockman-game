#include "RockmanGame.h"
#include "BigEye.h"
#include "Land.h"
#include "Map.h"

CRockmanGame::CRockmanGame(void)
{
	
}
CRockmanGame::CRockmanGame( HINSTANCE hInstance ):CGame(hInstance)
{	
}
CRockmanGame::~CRockmanGame(void)
{
	//delete rockman;
	for(list<CEntity*>::const_iterator it = m_listObject.begin(); it != m_listObject.end(); it++)
	{
		delete *it;
	} 
	m_listObject.clear();

	delete quadTree;
	//Release resource
	CResourceManager::Release();
}
LPD3DXSPRITE CRockmanGame::GetSpriteHandle()
{
	return _spriteHandler;
}
LPDIRECT3DDEVICE9 CRockmanGame::GetDevice3d()
{
	return _d3ddv;
}
void CRockmanGame::Render()
{	
	rockman->Render(GetSpriteHandle(), m_camera);
	quadTree->Draw(GetSpriteHandle(), m_camera);

	/*for(list<CEntity*>::const_iterator it = m_listObject.begin(); it != m_listObject.end(); it++)
	{
		(*it)->Render(GetSpriteHandle(), m_camera);
	}*/
}
void CRockmanGame::ProcessInput( float deltaTime )
{
	/*if(IsKeyDown(DIK_RIGHT))
	rockman->TurnRight(deltaTime);
	else
	if(IsKeyDown(DIK_LEFT))
	rockman->TurnLeft(deltaTime);
	else
	if(IsKeyDown(DIK_DOWN))
	rockman->Sitting(deltaTime);	
	else
	rockman->Stop(deltaTime);*/
}
void CRockmanGame::UpdateWorld(float deltaTime, CCamera *_camera, CInput *_input)
{
	vector<CEntity*> listOb = quadTree->GetListObjectInRect(_camera->m_viewPort);
	rockman->Update(deltaTime, _camera, _input, listOb);
	quadTree->Update(_camera, deltaTime);

	//TODO
	//listOb.clear();
	//for(list<CEntity*>::const_iterator it = m_listObject.begin(); it != m_listObject.end(); it++)
	//{
	//	(*it)->Update(deltaTime, _camera, _input,listOb);
	//}
	
}
void CRockmanGame::InitGame()
{	
	CMap map;
	vector<CEntity*> listObject = map.GetObjectFromFile("Resource//map//Map1.txt");	

	//Load tree
	quadTree = new CQuadTree();
	quadTree->LoadNodeInFile("Resource//map//Map1Tree.txt");
	//quadTree->CreateTree(quadTree->m_nodeRoot, quadTree->m_mapNode);

	quadTree->MapIdToObjectInTree(quadTree->m_nodeRoot, listObject);
	//
	rockman = new CRockman(D3DXVECTOR3(100,600,0));
	CRockman::posInMap = D3DXVECTOR2(2000,600);
	m_listObject.push_back(rockman);
	bigEye = new CBigEye(D3DXVECTOR3(300,135,0));
	m_listObject.push_back(bigEye);
}
LPD3DXFONT CRockmanGame::GetLPFont()
{
	return g_Font;
}


