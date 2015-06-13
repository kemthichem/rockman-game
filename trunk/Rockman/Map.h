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
	static int g_widthMap, g_heightMap;
	CMap();
	~CMap();

	vector<CEntity*> m_ListObjects;

	vector<string> SplitString(string str, char ch);
	void LoadObjectFromFile(char* filePath);

};



#endif