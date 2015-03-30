#include "MarioGame.h"
#ifndef _QUADTREENODE_H
#define _QUADTREENODE_H
using namespace std;

class CQuadTreeNode
{
private:
	CusRect rect;
	CQuadTreeNode* root;
	int level;
	list<CStaticObject*> listObjects;
	list<CQuadTreeNode*> listNode;
	int CountObject();

//	CQuadTreeNode *LT, *RT, *LB, *RB;
	
	void CreateSubNode();
public:
	list<CStaticObject*> SubTreeObject(bool updated = false);
	list<CStaticObject*> ListObjectInRect(CusRect screenRect, bool updated = false);

	bool Check(CusRect rectOld, CusRect rect);
	void AddObject(CStaticObject *object);
	void AddListObject(list<CStaticObject *> listObject);
	void DeleteObject( CusRect _rect);
	void Update(CusRect _rect, DWORD deltaTime);
	CQuadTreeNode(void);
	CQuadTreeNode(CusRect _bounds,CQuadTreeNode * root = NULL, int level= 0);
	//CQuadTreeNode(CusRect _bounds);
	~CQuadTreeNode(void);
};
#endif