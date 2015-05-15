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
#include"Land.h"
using std::vector;
using namespace std;
class CMap{
public:
	int m_widthmap,m_heightmap;
public:
	CMap();
	~CMap();
	vector<string> SplitString(string str, char ch);
	vector<CEntity*> ObjectFromFile(char* filePath);
	vector<CEntity*> GetObjectFromFile(char* filePath);
	int GetWidthMap(){return m_widthmap;};
	int GetHeightMap(){return m_heightmap;}
};



#endif