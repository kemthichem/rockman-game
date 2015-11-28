#include"Map.h"
#include "Land1.h"
#include "Land2.h"
#include "Land3.h"
#include "LandWhite.h"
#include "LandIceberg.h"
#include "MoveMap.h"
#include "Blader.h"
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
#include "LockCamera.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

int CMap::g_widthMap = 0;
int CMap::g_heightMap = 0;

CMap::CMap(){
	row, col, countTile = 0;
	m_ArrayMapTile = NULL;
}
CMap::~CMap()
{
	//delete list object
	for(int i = 0; i < m_ListObjects.size(); ++i)
		delete m_ListObjects[i];
	m_ListObjects.clear();

	//delete m_ArrayMapTile
	for (int i = 0; i < row; i++)
	{
		delete []m_ArrayMapTile[i];
	}
	delete []m_ArrayMapTile;
}

vector<string> CMap::SplitString(std::string str, char ch)
{
	vector<string> result;
	int n = str.size();
	string line = "";
	for(int i = 0; i < n; i++){
		while((i<n)&&(str.at(i)!=ch))
		{
			line.push_back(str.at(i));
			i++;
		}
		result.push_back(line);
		line.clear();		
	}
	return result;
}

void  CMap::LoadMap(char* pathMap,  CQuadTree *quadTree)
{	
	// define mapFile
	ifstream mapFile;

	// line of mapFile
	string line;

	// data from mapFile read into vector
	vector<string> listMap;

	// read file map and push data into a vector
	mapFile.open(pathMap);
	if (mapFile.is_open())
	{
		while (getline(mapFile,line))
		{
			listMap.push_back(line);
		}
	}

	istringstream istringstreamSize(listMap[2]);
	istream_iterator<std::string> istream_iteratorSize(istringstreamSize), end;
	// vector save row, column
	vector<string> sizeMap (istream_iteratorSize, end);

	// get row
	row = atoi(sizeMap.at(0).c_str());

	// get column
	col = atoi(sizeMap.at(1).c_str());

	countTile = atoi(sizeMap.at(2).c_str());

	// declare a 2 demen array to save tile 
	m_ArrayMapTile = new int *[row];

	//FIXME - help me define a array
	//int arrayTile[80][130];

	for (int i = 0; i < row; i++)
	{
		m_ArrayMapTile[i] = new int[col];
		istringstream istringstreamTile(listMap[i + 4]);
		istream_iterator<std::string> istream_iteratorTile(istringstreamTile), endTile;
		// vector save data of a row
		vector<string> rowTitle (istream_iteratorTile, endTile);

		for (int j = 0; j < col; j++)
		{
			m_ArrayMapTile[i][j] = atoi(rowTitle.at(j).c_str());
		}
	}
}

void CMap::AddObjectGame(int objID, int typeID, double posX, double posY, int width, int height, double posYCollide, int widthCollide, int heightCollide)
{
	CEntity *object;

	switch (objID)
	{
	case ID_ENEMY_BALL:
		break;
	case ID_ENEMY_BOOM_BLUE:
		break;
	case ID_ENEMY_EYE_RED_UP:
		break;
	case ID_ENEMY_EYE_RED_RIGHT:
		break;
	case ID_ENEMY_FISH_ORANGE:
		break;
	case ID_ENEMY_INK_RED:
		break;
	case ID_ENEMY_MACHINE_AUTO_BLUE_TOP:
		break;
	case ID_ENEMY_MACHINE_ORANGE:
		break;
	case ID_ENEMY_NINJA_GREEN:
		break;
	case ID_ENEMY_BUBBLE_BLUE:
		break;
	case ID_ENEMY_CUT:
		break;
	case ID_ENEMY_INK_BLUE:
		break;
	case ID_ENEMY_MACHINE_AUTO_ORGANGE_TOP:
		break;
	case ID_ENEMY_ROBOT_RED:
		break;
	case ID_ENEMY_TANK_RED:
		break;
	case ID_ENEMY_BUBBLE_GREEN:
		break;
	case ID_ENEMY_HAT:
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
		break;
	case ID_CLAMPER:
		break;
	case ID_ITEM_LIFE:
		break;
	case ID_ITEM_BLOOD_BIG:
		break;
	case ID_ITEM_BLOOD_SMALL:
		break;
	case ID_ITEM_MANA:
		break;
	case ID_ITEM_MANA_SMALL:
		break;
	case ID_ROCK:
		break;
	case ID_DIEAARROW:
		break;
	case ID_BOSSCUT:
		break;
	case ID_BOSSBOOM:
		break;
	case ID_BOSSRUT:
		break;
	case ID_ENEMY_MACHINE_AUTO_BLUE_BOTTOM:
		break;
	case ID_ENEMY_MACHINE_AUTO_ORGANGE_BOTT:
		break;
	case ID_CAMERA_PATH_POINT:
		break;
	case ID_FALLING_POINT:
		break;
	case ID_DOOR1_CUTMAN:
		break;
	case ID_DOOR1_GUTSMAN:
		break;
	case ID_DOOR1_BOOMMAN:
		break;
	case ID_DOOR2_BOOMMAN:
		break;
	case ID_DOOR2_CUTMAN:
		break;
	case ID_DOOR2_GUTSMAN:
		break;
	case ID_ENEMY_SNAPPER:
		break;
	case ID_ENEMY_WALL_SHOOTER_LEFT:
		break;
	case ID_ENEMY_WALL_SHOOTER_RIGHT:
		break;
	default:
		break;
	}

	m_ListObjects.push_back(object);
}
