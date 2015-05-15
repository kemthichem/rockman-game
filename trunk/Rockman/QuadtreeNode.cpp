#include "QuadTreeNode.h"


CQuadTreeNode::CQuadTreeNode(void)
{
}


CQuadTreeNode::~CQuadTreeNode(void)
{
	//Delete listObject
	//Delete child node
}

vector<CEntity*> CQuadTreeNode::GetListObjectInNode()
{
	vector<CEntity*> listObjects = m_ListObject;

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

	return listObjects;
}
