#ifndef _QUADTREE_NODE_H_
#define _QUADTREE_NODE_H_
#include <vector>

#include "Entity.h"

using std::vector;
using namespace std;

class CQuadTreeNode
{
public:
	CQuadTreeNode(void);
	~CQuadTreeNode(void);

	//Member
	int m_IdNode;
	RECT m_Rect;
	vector<int> m_ListIdObject;
	vector<CEntity*> m_ListObject;

	//Child
	CQuadTreeNode* ChildTopLeft;
	CQuadTreeNode* ChildTopRight;
	CQuadTreeNode* ChildBottomLeft;
	CQuadTreeNode* ChildBottomRight;

	//Method
	vector<CEntity*> GetListObjectInNode();
};

#endif//_QUADTREE_NODE_H_