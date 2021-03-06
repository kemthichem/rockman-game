#ifndef _QUADTREE_H_
#define _QUADTREE_H_
#include<map>

#include "QuadtreeNode.h"

using std::map;
class CQuadTree
{
private:
	map<int, CQuadTreeNode*> m_mapNode ;
	vector<CQuadTreeNode*> m_listNodeInViewPort;
	
	vector<CEntity*> m_listObjectViewportWillUpdate;
	void HeldObjectInScreen(vector<CEntity*>& listObject, RECT rScreen);
	vector<CQuadTreeNode*> GetListNodeIntersectRect(CQuadTreeNode*, RECT );
	bool IsIntersect(RECT, RECT);
public:
	CQuadTree(void);
	~CQuadTree(void);
	vector<CEntity*> m_listObjectViewportCheckCollision;
	CQuadTreeNode* m_nodeRoot;
	void LoadNodeInFile(vector<string>, int, int);
	void MapIdToObjectInTree(CQuadTreeNode* _nodeParent, vector<CEntity*> _listobject);
	vector<CEntity*> GetListObjectInRect(RECT _rect);
	void Update(CCamera* _camera, float _time);
	void Render (LPD3DXSPRITE _spriteHandle, CCamera* _camera);
	void CreateTree(CQuadTreeNode *_NodeParent, map<int,CQuadTreeNode*> _map);
	bool IsContains(RECT _rectBig, RECT _rectSmall);
	bool IsObjectInRect(CEntity *entity, RECT rect);
	bool AddObjectToList(vector<CEntity*>& list, CEntity* obAdd);
};

#endif//_QUADTREE_H_