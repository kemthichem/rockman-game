#include "RockmanGame.h"
#include "BigEye.h"
#include "Land.h"
#include "MoveMap.h"
#include "Map.h"

CRockmanGame::CRockmanGame(void)
{

}
CRockmanGame::CRockmanGame( HINSTANCE hInstance ):CGame(hInstance)
{	
}
CRockmanGame::~CRockmanGame(void)
{
	//delete list object
	for(int i = 0; i < m_listObject.size(); ++i)
		delete m_listObject[i];

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
	quadTree->Render(GetSpriteHandle(), m_camera);

	/*for(list<CEntity*>::const_iterator it = m_listObject.begin(); it != m_listObject.end(); it++)
	{
		(*it)->Render(GetSpriteHandle(), m_camera);
	}*/
}

void CRockmanGame::UpdateWorld(float deltaTime, CCamera *_camera, CInput *_input)
{
	vector<CEntity*> listOb = quadTree->GetListObjectInRect(_camera->m_viewPort);

	if (!CMoveMap::g_IsMovingMap) {
		rockman->Update(deltaTime, _camera, _input, listOb);
		quadTree->Update(_camera, deltaTime);
	} else
		_camera->Move(CMoveMap::g_DistanceMoveCameraY);

}
void CRockmanGame::InitGame()
{	
	CMap map;
	m_listObject = map.GetObjectFromFile("Resource//map//Map1.txt");	
	//Load tree
	quadTree = new CQuadTree();
	quadTree->LoadNodeInFile("Resource//map//Map1Tree.txt");

	quadTree->MapIdToObjectInTree(quadTree->m_nodeRoot, m_listObject);
	//
	rockman = new CRockman(D3DXVECTOR3(200,1000,0));
}
LPD3DXFONT CRockmanGame::GetLPFont()
{
	return g_Font;
}


