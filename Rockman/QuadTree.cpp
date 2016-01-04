#include "QuadTree.h"
#include "utils.h"
#include "Enemy.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>


CQuadTree::CQuadTree(void)
{
	m_listObjectViewportWillUpdate.clear();
	m_listObjectViewportCheckCollision.clear();
}

CQuadTree::~CQuadTree(void)
{
	for (map<int, CQuadTreeNode *>::iterator it = m_mapNode.begin(); it != m_mapNode.end(); ++it)
	{
		delete it->second;
	} 
	m_mapNode.clear();

	if (m_nodeRoot != NULL)
		delete m_nodeRoot;
}

void CQuadTree::LoadNodeInFile(vector<string> listMap, int startRow, int nodeCount)
{
	//ifstream f(_pathFileTree);
	vector<string> itemsInfo;
	char splitChar = '\t';

	//if(f.is_open()){
	//string line;
	//while(1){
	for(int i = startRow; i < startRow + nodeCount; i++)
	{
		CQuadTreeNode* node= new CQuadTreeNode();
		//getline(f,line);
		itemsInfo = CUtils::SplitString(listMap[i], splitChar);
		//if(strcmp(line.c_str(), "<End>") == 0)
		//break;
		node->m_IdNode = atoi(itemsInfo.at(0).c_str());
		node->m_Rect.left =(LONG)atoi(itemsInfo.at(1).c_str());
		node->m_Rect.top =(LONG)atoi(itemsInfo.at(2).c_str());
		node->m_Rect.right = node->m_Rect.left + (LONG)atoi(itemsInfo.at(3).c_str());
		node->m_Rect.bottom =node->m_Rect.top - (LONG)atoi(itemsInfo.at(4).c_str());

		if (node->m_IdNode==256)
			int k = 0;
		if (itemsInfo.size() > 6)
		{
			for (int i = 6; i < itemsInfo.size(); i++)
			{

				node->m_ListIdObject.push_back(atoi(itemsInfo.at(i).c_str()));
			}
		}
		if(node->m_IdNode!=0)
		{
			m_mapNode[node->m_IdNode] = node;
		}
		else
		{
			m_nodeRoot = node;
		}
		//}
		//}	
	}
	CreateTree(m_nodeRoot, m_mapNode);
}

vector<CEntity*> CQuadTree::GetListObjectInRect(RECT _rect)
{
	m_listNodeInViewPort.clear();
	HeldObjectInScreen(m_listObjectViewportCheckCollision, _rect);
	HeldObjectInScreen(m_listObjectViewportWillUpdate, _rect);	

	GetListNodeIntersectRect(m_nodeRoot, _rect);
	for (int i = 0; i < m_listNodeInViewPort.size(); i++)
	{
		vector<CEntity*> listObjectInNode;
		m_listNodeInViewPort[i]->GetListObjectInNode(_rect, listObjectInNode);

		for (int j = 0; j < listObjectInNode.size(); j++) {
			if (listObjectInNode[j]->IsShowed()) {
				AddObjectToList(m_listObjectViewportCheckCollision, listObjectInNode[j]);
			}
			if ((int)listObjectInNode[j]->GetType() > 0 && listObjectInNode[j]->IsShowed()) {
				AddObjectToList(m_listObjectViewportWillUpdate, listObjectInNode[j]);
			}
		}
	}

	return m_listObjectViewportCheckCollision;
}

void CQuadTree::Update(CCamera* _camera, float _time)
{
	for (int i = 0; i < m_listObjectViewportWillUpdate.size(); i++)
	{
		if (m_listObjectViewportWillUpdate[i]->GetType() > ROCKMAN && m_listObjectViewportWillUpdate[i]->IsShowed())
			m_listObjectViewportWillUpdate[i]->Update(_time, _camera, NULL, m_listObjectViewportCheckCollision);
	}
}

void CQuadTree::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	for (int i = 0; i < m_listObjectViewportCheckCollision.size(); i++)
	{
		m_listObjectViewportCheckCollision[i]->Render(_spriteHandle, _camera);
	}
}

void CQuadTree::MapIdToObjectInTree(CQuadTreeNode* _nodeParent, vector<CEntity*> _listobject)
{
	if (_nodeParent->m_ListIdObject.size()!=0)
	{
		for (int i = 0; i < _listobject.size(); i++)
		{
			for (int j = 0; j < _nodeParent->m_ListIdObject.size(); j++)
			{
				if (_listobject[i]->GetId() == _nodeParent->m_ListIdObject[j])
				{
					_nodeParent->m_ListObject.push_back(_listobject[i]);
				}
			}
		}
	}
	//
	if(_nodeParent->ChildTopLeft != NULL)
	{
		MapIdToObjectInTree(_nodeParent->ChildTopLeft, _listobject);
	}
	if(_nodeParent->ChildBottomLeft != NULL)
	{
		MapIdToObjectInTree(_nodeParent->ChildBottomLeft, _listobject);
	}
	if(_nodeParent->ChildBottomRight != NULL)
	{
		MapIdToObjectInTree(_nodeParent->ChildBottomRight, _listobject);
	}
	if(_nodeParent->ChildTopRight != NULL)
	{
		MapIdToObjectInTree(_nodeParent->ChildTopRight, _listobject);
	}
}

void CQuadTree::CreateTree(CQuadTreeNode *_nodeParent,map<int,CQuadTreeNode*> _map){

	if(_map.find(_nodeParent->m_IdNode * 4 + 1) != _map.end())
	{
		_nodeParent->ChildTopLeft = _map.find(_nodeParent->m_IdNode * 4  + 1)->second;
		CreateTree(_nodeParent->ChildTopLeft, _map);
	}
	if(_map.find(_nodeParent->m_IdNode * 4  + 2) != _map.end())
	{
		_nodeParent->ChildTopRight = _map.find(_nodeParent->m_IdNode * 4  + 2)->second;
		CreateTree(_nodeParent->ChildTopRight, _map);
	}
	if(_map.find(_nodeParent->m_IdNode * 4  + 3) != _map.end())
	{
		_nodeParent->ChildBottomLeft = _map.find(_nodeParent->m_IdNode * 4  + 3)->second;
		CreateTree(_nodeParent->ChildBottomLeft, _map);
	}
	if(_map.find(_nodeParent->m_IdNode * 4  + 4) != _map.end())
	{
		_nodeParent->ChildBottomRight = _map.find(_nodeParent->m_IdNode * 4  + 4)->second;
		CreateTree(_nodeParent->ChildBottomRight, _map);
	}
}

vector<CQuadTreeNode*> CQuadTree::GetListNodeIntersectRect(CQuadTreeNode* _nodeParent, RECT _rect)
{
	if(IsIntersect(_rect, _nodeParent->m_Rect) && _nodeParent->m_ListIdObject.size()!=0)
	{
		m_listNodeInViewPort.push_back(_nodeParent);
	}

	if(_nodeParent->m_ListIdObject.size()==0 && IsIntersect(_nodeParent->m_Rect, _rect))
	{
		if(_nodeParent->ChildTopLeft != NULL)
		{
			GetListNodeIntersectRect(_nodeParent->ChildTopLeft, _rect);
		}
		if(_nodeParent->ChildBottomLeft != NULL)
		{
			GetListNodeIntersectRect(_nodeParent->ChildBottomLeft, _rect);
		}
		if(_nodeParent->ChildBottomRight != NULL)
		{
			GetListNodeIntersectRect(_nodeParent->ChildBottomRight, _rect);
		}
		if(_nodeParent->ChildTopRight != NULL)
		{
			GetListNodeIntersectRect(_nodeParent->ChildTopRight, _rect);
		}
	}

	return m_listNodeInViewPort;
}

bool CQuadTree::IsIntersect(RECT _rect1, RECT _rect2)
{
	if (_rect1.right <= _rect2.left)
		return false;
	else if (_rect1.left >= _rect2.right)
		return false;
	else if (_rect1.top <= _rect2.bottom)
		return false;
	else if (_rect1.bottom >= _rect2.top)
		return false;
	return true;
}

void CQuadTree::HeldObjectInScreen(vector<CEntity*>& listObject, RECT rScreen)
{
	int size = listObject.size();
	for (int i = 0; i < size; i++)
	{
		if (listObject[i]->GetType() > 0 && !IsObjectInRect(listObject[i], rScreen)) {
			CEnemy *enemy = dynamic_cast<CEnemy*> (listObject[i]);
			if(enemy)
				enemy->Reset();
		}

		if (listObject[i]->GetType() < 0 || !IsObjectInRect(listObject[i], rScreen)) {
			listObject.erase(listObject.begin() + i);
			i--;
			size--;
		}
	}
}

bool CQuadTree::IsObjectInRect(CEntity *entity, RECT rect)
{
	return CAABBCollision::IntersectRect(entity->GetRect(), rect);
}

bool CQuadTree::AddObjectToList(vector<CEntity*>& list, CEntity* obAdd)
{
	bool isCanAdd = true;
	int id = obAdd->GetId();

	int size = list.size();
	for (int i = 0; i < size; i++)
	{
		if (list[i]->GetId() == id) {
			isCanAdd = false;
			break;
		}
	}
	if (isCanAdd) {
		list.push_back(obAdd);
	}

	return isCanAdd;
}
