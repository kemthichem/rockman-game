#include "QuadTreeNode.h"


CQuadTreeNode::CQuadTreeNode(void)
{
}


CQuadTreeNode::~CQuadTreeNode(void)
{
	//Delete listObject
	//Delete child node
}

void CQuadTreeNode::GetListObjectInNode(RECT _rect, vector<CEntity*>& _listObjects)
{
	int size = m_ListObject.size();
	for (int i = 0; i < size; i++)
	{
		if (Intersect(m_ListObject[i]->GetRect(), _rect))
			_listObjects.push_back(m_ListObject[i]);
	}
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



