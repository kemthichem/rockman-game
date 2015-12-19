#include "CConfig.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "utils.h"

#define PATH_CONFIG "Resources//Config//rockman_config.txt"


CConfig::CConfig(void)
{
	m_ArrayConfig = new float[KEY_COUNT];
	LoadConfig(PATH_CONFIG);
}


CConfig::~CConfig(void)
{
}

//CConfig* CConfig::GetInstance()
//{
//	if (!instance) {
//		instance = new CConfig();
//	}
//
//	return instance;
//}

float CConfig::ValueOf(int inIDKey)
{
	if (!instance) {
		instance = new CConfig();
	}

	return instance->m_ArrayConfig[inIDKey];
}

void CConfig::LoadConfig(char* inPath)
{
	using namespace std;
	ifstream ifstreamMapFile;
	string line;
	// read file map and push data into a vector
	ifstreamMapFile.open(inPath);
	if (ifstreamMapFile.is_open())
	{
		int i = 0;
		vector<string> stringsLine;
		while (getline(ifstreamMapFile,line) && i < KEY_COUNT)
		{
			stringsLine = CUtils::SplitString(line, ' ');
			if (stringsLine.size() > 1) {
				m_ArrayConfig[i] = (float)atof(stringsLine[1].c_str());
			}
			++i;
		}
	}
	ifstreamMapFile.close();
}

CConfig* CConfig::instance = 0;
