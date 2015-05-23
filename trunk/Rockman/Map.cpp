#include"Map.h"
#include "MoveMap.h"
#include "Blader.h"
#include "Ladder.h"

int CMap::g_widthMap = 0;
int CMap::g_heightMap = 0;

CMap::CMap(){}
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
vector<CEntity*> CMap::ObjectFromFile(char* _pathFileMap)
{
	vector<CEntity*> object;
	ifstream f(_pathFileMap);
	vector<string> itemsInfo;
	if(f.is_open())
	{
		string line;
		D3DXVECTOR2 _pos;
		string _objecttype;
		int _idObject;
		getline(f,line);
		itemsInfo = SplitString(line,' ');
		g_widthMap = atoi(itemsInfo.at(0).c_str());
		g_heightMap = atoi(itemsInfo.at(1).c_str());

		while(1){
			getline(f,line);
			itemsInfo = SplitString(line,' ');
			if(strcmp(line.c_str(), "<End>") == 0)
				break;
			_idObject = atoi(itemsInfo.at(0).c_str());
			_objecttype= itemsInfo.at(1).c_str();
			_pos.x = atoi(itemsInfo.at(2).c_str());
			_pos.y= atoi(itemsInfo.at(3).c_str());

			if(_objecttype == "LAND"){
				CLand *_brick = new CLand(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				object.push_back(_brick);
			} else if(_objecttype == "MOVEMAP"){
				CMoveMap *moveMap = new CMoveMap(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				object.push_back(moveMap);
			} else if(_objecttype == "BIGEYE"){
				CBigEye *bigEye = new CBigEye(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				object.push_back(bigEye);
			} else if(_objecttype == "BLADER"){
				CBlader *ob = new CBlader(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				object.push_back(ob);
			}

			else if(_objecttype == "LADDER"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				object.push_back(ob);
			}
		}
	}

	return object;
}
vector<CEntity*> CMap::GetObjectFromFile(char* filePath)
{	
	//doi background ve truoc cac doi tuong game
	vector<CEntity*> object;
	object = ObjectFromFile(filePath);
	vector<CEntity*> listBackground;
	vector<CEntity*> listObject;
	for (int i = 0; i < object.size(); i++)
	{
		if (object[i]->GetType()==OBJECTTYPE)
		{
			listBackground.push_back(object[i]);
		}
		else
		{		
			listObject.push_back(object[i]);
		}
	}
	object.clear();
	for (int i = 0; i < listBackground.size(); i++)
	{
		object.push_back(listBackground[i]);
	}
	for (int i = 0; i < listObject.size(); i++)
	{
		object.push_back(listObject[i]);
	}
	return object;
}
CMap::~CMap(){}


