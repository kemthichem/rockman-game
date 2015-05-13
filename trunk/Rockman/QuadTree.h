#ifndef _QUADTREE_H_
#define _QUADTREE_H_
#include<map>

#include "QuadtreeNode.h"

using std::map;
class CQuadTree
{
private:
	map<int,CQuadTreeNode*> m_mapNode ;
	vector<CQuadTreeNode*> m_listNodeInViewPort;
public:
	CQuadTree(void);
	~CQuadTree(void);

	CQuadTreeNode* m_nodeRoot;

	void LoadNodeInFile(char*);
	void MapIdToObjectInTree(vector<CEntity*> _listobject);
	vector<CEntity*> GetListObjectInRect(RECT _rect);
	void Update(CCamera* _camera, float _time);
	void Draw (LPD3DXSPRITE _spriteHandle);
};

#endif//_QUADTREE_H_