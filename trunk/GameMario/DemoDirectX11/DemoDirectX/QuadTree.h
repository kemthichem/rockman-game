#include "MarioGame.h"
#ifndef _QUADTREE_H
#define _QUADTREE_H
class CQuadTree
{
private:
	CusRect rectangle;
	
	
public:

	CQuadTree(void);
	CQuadTreeNode *root;
	~CQuadTree(void);
	list<CStaticObject*> ListObjectInRect(CusRect screenRect);
	CQuadTree(LONG widht, LONG height);
	void AddObject(CStaticObject *object);
	void DeleteObject(CStaticObject* object);
	void Render();
	void Update(DWORD deltaTime);
	void AddListObject( list<CStaticObject*> _listObject );
	LONG GetHeight();
	LONG GetWidth();
};
#endif
