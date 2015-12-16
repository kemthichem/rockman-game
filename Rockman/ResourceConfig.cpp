#include "ResourceConfig.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "utils.h"

#define PATH_CONFIG "Resource//rockman_config.txt"


ResourceConfig::ResourceConfig(void)
{
	m_ArrayConfig = new float[KEY_COUNT];
	LoadConfig(PATH_CONFIG);
}


ResourceConfig::~ResourceConfig(void)
{
}

ResourceConfig* ResourceConfig::GetInstance()
{
	if (!instance) {
		instance = new ResourceConfig();
	}

	return instance;
}

float ResourceConfig::GetValue(int inIDKey)
{
	return m_ArrayConfig[inIDKey];
}

void ResourceConfig::LoadConfig(char* inPath)
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
				m_ArrayConfig[i] = atof(stringsLine[1].c_str());
			}
			++i;
		}
	}
	ifstreamMapFile.close();
}

ResourceConfig* ResourceConfig::instance = 0;
