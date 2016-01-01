#include"Map.h"
#include "Blader.h"
#include "BigEye.h"
#include "Block.h"
#include "Rock.h"
#include "Ladder.h"
#include "Cutman.h"
#include "ScrewBomber.h"
#include "Octopus.h"
#include "IceMan.h"
#include "GutsMan.h"
#include "Flea.h"
#include "Beak.h"
#include "Met.h"
#include "Spine.h"
#include "FlyingShell.h"
#include "QuadTree.h"
#include "SupperCutter.h"
#include "Door.h"
#include "Ramie.h"
#include "Item.h"
#include "utils.h"


int CMap::g_widthMap = 0;
int CMap::g_heightMap = 0;

CMap::CMap(){
	rowTitle, colTitle, countTile = 0;
	m_ArrayMapTile = NULL;
}
CMap::~CMap()
{
	//delete list object
	for(int i = 0; i < m_ListObjects.size(); ++i)
		delete m_ListObjects[i];
	m_ListObjects.clear();

	//delete m_ArrayMapTile
	for (int i = 0; i < rowTitle; i++)
	{
		delete []m_ArrayMapTile[i];
	}
	delete []m_ArrayMapTile;
}

void  CMap::LoadMap(const char* pathMap,  CQuadTree *quadTree, CCamera *camera)
{
	// get data from map
	vector<string> vectorDataFromMap = CUtils::LoadDataFromFile(pathMap);

	// get a row contain row, col
	vector<string> sizeMap = CUtils::SplitString(vectorDataFromMap[2], CUtils::charSplit);

	// get row
	rowTitle = atoi(sizeMap.at(0).c_str());	
	// get column
	colTitle = atoi(sizeMap.at(1).c_str());
	countTile = atoi(sizeMap.at(2).c_str());

	// declare a 2 dimensional array to save tile 
	m_ArrayMapTile = new int *[rowTitle];
	vector<string> vectorTitle;
	for (int i = 0; i < rowTitle; i++)
	{
		m_ArrayMapTile[i] = new int[colTitle];
		vectorTitle = CUtils::SplitString(vectorDataFromMap[i + 4], CUtils::charSplit);

		for (int j = 0; j < colTitle; j++)
		{
			m_ArrayMapTile[i][j] = atoi(vectorTitle.at(j).c_str());
		}
	}

	// get object count at row 75 on fileMap
	vector<string> vectorSize = CUtils::SplitString(vectorDataFromMap[rowTitle + 7], CUtils::charSplit);
	int objectCount = atoi(vectorSize.at(0).c_str());

	int startRowObject = rowTitle + 9;
	vector<string> vectorObject;
	int objID, typeID, width, height, widthCollide, heightCollide;
	double posX, posY, posXCollide, posYCollide;
	for (int k = startRowObject; k < startRowObject + objectCount; k++)
	{
		//vector<string> sizeObject = getListFromFile(listMap, k);
		vectorObject = CUtils::SplitString(vectorDataFromMap[k], CUtils::charSplit);//
		objID = atoi(vectorObject.at(0).c_str());
		typeID = atoi(vectorObject.at(1).c_str());
		posX = atoi(vectorObject.at(2).c_str());
		posY = atoi(vectorObject.at(3).c_str());
		width = atoi(vectorObject.at(4).c_str());
		height = atoi(vectorObject.at(5).c_str());
		posXCollide = atoi(vectorObject.at(6).c_str());
		posYCollide = atoi(vectorObject.at(7).c_str());
		widthCollide = atoi(vectorObject.at(8).c_str());
		heightCollide = atoi(vectorObject.at(9).c_str());
		// add object game
		AddObjectGame(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
	}
	int nodeCount = atoi(CUtils::SplitString(vectorDataFromMap[rowTitle + 12 + objectCount], CUtils::charSplit).at(0).c_str());
	int startRowQuadTree = rowTitle + 14 + objectCount;
	quadTree->LoadNodeInFile(vectorDataFromMap, startRowQuadTree, nodeCount);

	quadTree->MapIdToObjectInTree(quadTree->m_nodeRoot, m_ListObjects);

	int sizePathPoint = atoi(CUtils::SplitString(vectorDataFromMap[rowTitle + 14 + objectCount + nodeCount + 2], CUtils::charSplit).at(0).c_str());
	int startPathPoint = rowTitle + 14 + objectCount + nodeCount + 3;
	
	int _temp = 0;
	int X, Y;
	POINT * arrayPoint = new POINT[sizePathPoint];
	for (int k = startPathPoint; k < startPathPoint + sizePathPoint; k++)
	{
		vectorObject = CUtils::SplitString(vectorDataFromMap[k], CUtils::charSplit);
		X = atoi(vectorObject.at(0).c_str());
		Y = atoi(vectorObject.at(1).c_str());
		arrayPoint[_temp].x = X;
		arrayPoint[_temp].y = Y;
		_temp++;
	}

	camera->Initialize(arrayPoint, sizePathPoint);
}

void CMap::AddObjectGame(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	CEntity *object = NULL;

	switch (typeID)
	{
	case ID_ENEMY_BALL:
		object = new CFlyingShell(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_BOOM_BLUE:
		break;
	// FIX-ME UP - RIGHT
	case ID_ENEMY_EYE_RED_UP:
		object = new COctopus(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_EYE_RED_RIGHT:
		break;
	case ID_ENEMY_FISH_ORANGE:
		break;
	// Flea
	case ID_ENEMY_INK_RED:
		object = new CFlea(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_MACHINE_AUTO_BLUE_TOP:
		break;
	// Spine
	case ID_ENEMY_MACHINE_ORANGE:
		object = new CSpine(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_NINJA_GREEN:
		break;
	// CBlader
	case ID_ENEMY_BUBBLE_BLUE:
		object = new CBlader(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_CUT:
		object = new CSupperCutter(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_INK_BLUE:
		object = new CFlea(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_MACHINE_AUTO_ORGANGE_TOP:
		break;
	// BigEye
	case ID_ENEMY_ROBOT_RED:
		object = new CBigEye(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_TANK_RED:
		break;
	case ID_ENEMY_BUBBLE_GREEN:
		break;
	// Met
	case ID_ENEMY_HAT:
		object = new CMet(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_ROBOT_BLUE:
		break;
	case ID_ENEMY_WORKER:
		break;
	case ID_BLOCK_TROUBLE_OF_ELEVATOR:
		break;
	case ID_ELEVATOR:
		break;
	case ID_ROCKGUSTMAN:
		break;
	case ID_BLOCK:
		object = new CBlock(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ROCK:
		object = new CRock(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_CLAMPER:
		object = new CLadder(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ITEM_LIFE:
		break;
	case ID_ITEM_BLOOD_BIG:
		object = new CItem(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide, BLOOD_BIG);
		break;
	case ID_ITEM_BLOOD_SMALL:
		object = new CItem(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide, BLOOD_SMALL);
		break;
	case ID_ITEM_MANA:
		break;
	case ID_ITEM_MANA_SMALL:
		break;
	case ID_DIEAARROW:
		object = new CRamie(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_BOSSCUT:
		object = new CCutMan(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_BOSSBOOM:
		break;
	case ID_BOSSRUT:
		break;
	case ID_ENEMY_MACHINE_AUTO_BLUE_BOTTOM:
		break;
	case ID_ENEMY_MACHINE_AUTO_ORGANGE_BOTT:
		object = new CScrewBomber(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_CAMERA_PATH_POINT:
		break;
	case ID_FALLING_POINT:
		break;
	case ID_DOOR1_CUTMAN:
		object = new CDoor(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_DOOR1_GUTSMAN:
		break;
	case ID_DOOR1_BOOMMAN:
		break;
	case ID_DOOR2_BOOMMAN:
		break;
	case ID_DOOR2_CUTMAN:
		object = new CDoor(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_DOOR2_GUTSMAN:
		break;
	case ID_ENEMY_SNAPPER:
		break;
	// Beak
	case ID_ENEMY_WALL_SHOOTER_LEFT:
		object = new CBeak(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide);
		break;
	case ID_ENEMY_WALL_SHOOTER_RIGHT:
		object = new CBeak(objID, typeID, posX, posY, width, height, posXCollide, posYCollide, widthCollide, heightCollide, false);
		break;
	default:
		break;
	}
	if (object) {
		m_ListObjects.push_back(object);
	}
}

void CMap::LoadMapStages(const char* fileStage)
{
	using namespace std;
	ifstream ifstreamMapFile;
	string line;
	// read file map and push data into a vector
	ifstreamMapFile.open(fileStage);
	if (ifstreamMapFile.is_open())
	{
		vector<string> stringsLine;
		while (getline(ifstreamMapFile,line))
		{
			stringsLine = CUtils::SplitString(line, '\t');
			if (stringsLine.size() >= 3) {
				MAP map = { stringsLine[1], stringsLine[2] };
				m_Maps.push_back(map);
			}
		}
	}
	ifstreamMapFile.close();
}

bool CMap::GetMap(int stage, string& pathMap, string& pathMapTile)
{
	if (stage > m_Maps.size() || stage < 1) {
		return false;
	}

	pathMap = m_Maps[stage - 1].pathMapObject;
	pathMapTile = m_Maps[stage - 1].pathMapImage;
}
