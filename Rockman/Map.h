#ifndef MAP_H_
#define MAP_H_
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <fstream>
#include <string>
#include <vector>

#include"Rockman.h"
#include"BigEye.h"
#include"Block.h"
#include "QuadTree.h"

using std::vector;
using namespace std;
class CMap{

private:
	void AddObjectGame(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	
public:
	static int g_widthMap, g_heightMap;
	int **m_ArrayMapTile;
	int rowTitle, colTitle, countTile;


	CMap();
	~CMap();

	CQuadTreeNode* m_nodeRoot;

	vector<CEntity*> m_ListObjects;

	void LoadMap(char* filePath, CQuadTree *quadTree);
};



#endif