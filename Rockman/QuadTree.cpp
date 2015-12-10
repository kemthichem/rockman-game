#include "QuadTree.h"
#include "utils.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>


CQuadTree::CQuadTree(void)
{
	m_listObjectViewportToUpdate.clear();
	m_listObjectViewportToRender.clear();
}

vector<string> CQuadTree::getListFromFile(vector<string> listMap, int i)
{
	istringstream istringStream(listMap[i]);
	istream_iterator<std::string> istream_Iterator(istringStream), end;

	vector<string> sizeObject (istream_Iterator, end);
	return sizeObject;
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


	//if(f.is_open()){
	//string line;
	//while(1){
	for(int i = startRow; i < startRow + nodeCount; i++)
	{
		CQuadTreeNode* node= new CQuadTreeNode();
		//getline(f,line);
		itemsInfo = getListFromFile(listMap, i);
		//if(strcmp(line.c_str(), "<End>") == 0)
		//break;
		node->m_IdNode = atoi(itemsInfo.at(0).c_str());
		node->m_Rect.left =(LONG)atoi(itemsInfo.at(1).c_str());
		node->m_Rect.top =(LONG)atoi(itemsInfo.at(2).c_str());
		node->m_Rect.right = (LONG)atoi(itemsInfo.at(3).c_str());
		node->m_Rect.bottom =(LONG)atoi(itemsInfo.at(4).c_str());
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

vector<CEntity*>CQuadTree::ClearDuplicate(vector<CEntity*> list)
{
	vector<CEntity*> Listkq;
	int size =  list.size();
	for (int i=0;i<size - 1;i++) 
		for (int j=i+1;j<size;j++) 
		{ 
			if (list[i]->GetId()==list[j]->GetId()) 
				list[j--]=list[--size];   
		}

		for (int i = 0; i < size; i++)
		{
			Listkq.push_back(list[i]);
		}
		return Listkq;
}


vector<CEntity*> CQuadTree::GetListObjectInRect(RECT _rect)
{
	m_listObjectViewportToRender.clear();
	m_listObjectViewportToUpdate.clear();
	m_listNodeInViewPort.clear();

	GetListNodeIntersectRect(m_nodeRoot, _rect);
	for (int i = 0; i < m_listNodeInViewPort.size(); i++)
	{
		vector<CEntity*> listObjectInNode;
		m_listNodeInViewPort[i]->GetListObjectInNode(_rect, listObjectInNode);


		//m_listObjectViewportToUpdate.insert(m_listObjectViewportToUpdate.begin(), listObjectInNode.begin(), listObjectInNode.end());

		for (int j = 0; j < listObjectInNode.size(); j++) {
			if (listObjectInNode[j]->IsShowed()) {
				m_listObjectViewportToRender.push_back(listObjectInNode[j]);
			}
			if ((int)listObjectInNode[j]->GetType() > -10) {
				m_listObjectViewportToUpdate.push_back(listObjectInNode[j]);

				if (listObjectInNode[j]->GetType() == BLOCK_CAMERA) {
					CCamera::g_IsMoveX = false;
				} else if (listObjectInNode[j]->GetType() == UNLOCK_CAMERA) {
					CCamera::g_IsMoveX = true;
				}
			}
		}
	}
	m_listObjectViewportToUpdate = ClearDuplicate(m_listObjectViewportToUpdate);
	return m_listObjectViewportToUpdate;
}

void CQuadTree::Update(CCamera* _camera, float _time)
{
	for (int i = 0; i < m_listObjectViewportToUpdate.size(); i++)
	{
		if (m_listObjectViewportToUpdate[i]->GetType() != ROCKMAN)
			m_listObjectViewportToUpdate[i]->Update(_time, _camera, NULL, m_listObjectViewportToUpdate);
	}
}

void CQuadTree::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	for (int i = 0; i < m_listObjectViewportToRender.size(); i++)
	{
		m_listObjectViewportToRender[i]->Render(_spriteHandle, _camera);
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

bool CQuadTree::IsContains(RECT _rectBig, RECT _rectSmall)
{
	if (_rectSmall.left < _rectBig.left || _rectSmall.right > _rectBig.right)
		return false;
	else if (_rectSmall.top < _rectBig.top || _rectSmall.bottom > _rectBig.bottom)
		return false;
	return true;
}

