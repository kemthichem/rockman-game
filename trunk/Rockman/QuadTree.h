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
	vector<CEntity*> m_listObjectInViewport;


	vector<CQuadTreeNode*> GetListNodeIntersectRect(CQuadTreeNode*,RECT );
	bool IsBound(RECT ,RECT);

public:
	CQuadTree(void);
	~CQuadTree(void);

	CQuadTreeNode* m_nodeRoot;

	void LoadNodeInFile(char*);
	void MapIdToObjectInTree(CQuadTreeNode* _nodeParent, vector<CEntity*> _listobject);
	vector<CEntity*> GetListObjectInRect(RECT _rect);
	void Update(CCamera* _camera, float _time);
	void Draw (LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void CreateTree(CQuadTreeNode *_NodeParent,map<int,CQuadTreeNode*> _map);
};

#endif//_QUADTREE_H_