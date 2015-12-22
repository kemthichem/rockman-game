#ifndef MAP_H_
#define MAP_H_
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <fstream>
#include <string>
#include <vector>

#include "QuadTree.h"
#include "Camera.h"

using std::vector;
using namespace std;

#define PATH_STAGE_MAP "Resources//map//map_stages.txt";

struct MAP
{
	string pathMapObject;
	string pathMapImage;

};

class CMap{

private:
	void AddObjectGame(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide);
	vector<MAP> m_Maps;
public:
	static int g_widthMap, g_heightMap;
	int **m_ArrayMapTile;
	int rowTitle, colTitle, countTile;

	CMap();
	~CMap();

	CQuadTreeNode* m_nodeRoot;
	vector<CEntity*> m_ListObjects;
	void LoadMap(const char* filePath, CQuadTree *quadTree, CCamera*);
	void LoadMapStages(const char* fileStage);
	bool GetMap(int stage, string& pathMap, string& pathMapTile);
};



#endif