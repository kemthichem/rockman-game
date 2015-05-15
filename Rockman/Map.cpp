#include"Map.h"

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
		m_widthmap = atoi(itemsInfo.at(0).c_str());
		m_heightmap = atoi(itemsInfo.at(1).c_str());

		while(1){
			getline(f,line);
			itemsInfo = SplitString(line,' ');
			if(strcmp(line.c_str(), "<End>") == 0)
				break;
			_idObject = atoi(itemsInfo.at(0).c_str());
			_objecttype=itemsInfo.at(1).c_str();
			_pos.x = atoi(itemsInfo.at(2).c_str());
			_pos.y=atoi(itemsInfo.at(3).c_str());
			if(_objecttype=="LAND"){
				CLand *_brick = new CLand(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				object.push_back(_brick);
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