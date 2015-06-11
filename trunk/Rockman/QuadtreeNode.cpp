#include "QuadTreeNode.h"


CQuadTreeNode::CQuadTreeNode(void)
{
}


CQuadTreeNode::~CQuadTreeNode(void)
{
	//Delete listObject
	//Delete child node
}

vector<CEntity*> CQuadTreeNode::GetListObjectInNode(RECT _rect)
{
	vector<CEntity*> listObjects;

	int size = m_ListObject.size();
	for (int i = 0; i < size; i++)
	{
		if (Intersect(m_ListObject[i]->GetRect(), _rect))
			listObjects.push_back(m_ListObject[i]);
	}

	return listObjects;
/*
	if(this->ChildTopLeft != NULL)
	{
		vector<CEntity*> listObjectsOfChild = ChildTopLeft->GetListObjectInNode();
		listObjects.insert( listObjects.end(), listObjectsOfChild.begin(), listObjectsOfChild.end());
	}
	if(ChildBottomLeft != NULL)
	{
		vector<CEntity*> listObjectsOfChild = ChildBottomLeft->GetListObjectInNode();
		listObjects.insert( listObjects.end(), listObjectsOfChild.begin(), listObjectsOfChild.end());
	}
	if(ChildBottomRight != NULL)
	{
		vector<CEntity*> listObjectsOfChild = ChildBottomRight->GetListObjectInNode();
		listObjects.insert( listObjects.end(), listObjectsOfChild.begin(), listObjectsOfChild.end());
	}
	if(ChildTopRight != NULL)
	{
		vector<CEntity*> listObjectsOfChild = ChildTopRight->GetListObjectInNode();
		listObjects.insert( listObjects.end(), listObjectsOfChild.begin(), listObjectsOfChild.end());
	}

	return listObjects;*/
}

bool CQuadTreeNode::Intersect(RECT _rect1, RECT _rect2)
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



