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

int CMap::g_widthMap = 0;
int CMap::g_heightMap = 0;

CMap::CMap(){}
CMap::~CMap()
{
	//delete list object
	for(int i = 0; i < m_ListObjects.size(); ++i)
		delete m_ListObjects[i];
	m_ListObjects.clear();
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

void  CMap::LoadObjectFromFile(char* filePath)
{	
	ifstream f(filePath);
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

			//*************SCENERY****************//

			//*************BLOCK****************//
			if(_objecttype == "LAND"){
				CLand *_brick = new CLand(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(_brick);
			}  else if(_objecttype == "_LAND"){
				CLand *ob = new CLand(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0), false);
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "LAND1"){
				CLand1 *ob = new CLand1(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			}  else if(_objecttype == "_LAND1"){
				CLand1 *ob = new CLand1(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0), -1);
				m_ListObjects.push_back(ob);
			}  else if(_objecttype == "LAND4"){
				CLand1 *ob = new CLand1(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0), 1);
				m_ListObjects.push_back(ob);
			}  else if(_objecttype == "LAND5"){
				CLand2 *ob = new CLand2(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			}else if(_objecttype == "LANDWHITE"){
				CLandWhite *ob = new CLandWhite(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "LAND3"){
				CLand3 *ob = new CLand3(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "LAND2"){
				CLand2 *ob = new CLand2(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			}else if(_objecttype == "_LANDWHITE"){
				CLandWhite *ob = new CLandWhite(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0), false);
				m_ListObjects.push_back(ob);
			}else if(_objecttype == "LANDICEBERG"){
				CLandIceberg *ob = new CLandIceberg(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "_LANDICEBERG"){
				CLandIceberg *ob = new CLandIceberg(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0), false);
				m_ListObjects.push_back(ob);
			}   else if(_objecttype == "MOVEMAP"){
				CMoveMap *moveMap = new CMoveMap(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(moveMap);
			}else if(_objecttype == "BLOCKCAMERA"){
				CLockCamera *moveMap = new CLockCamera(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(moveMap);
			}else if(_objecttype == "UNLOCKCAMERA"){
				CLockCamera *moveMap = new CLockCamera(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0), false);
				m_ListObjects.push_back(moveMap);
			}else if(_objecttype == "BLADER"){
				CBlader *ob = new CBlader(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "LADDER10"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), 10);
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "LADDER5"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), 5);
				m_ListObjects.push_back(ob);
			}  else if(_objecttype == "LADDER6"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), 6);
				m_ListObjects.push_back(ob);
			}  else if(_objecttype == "LADDER2"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), 2);
				m_ListObjects.push_back(ob);
			} 	else if(_objecttype == "LADDER4"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), 4);
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "LADDER7"){
				CLadder *ob = new CLadder(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), 7);
				m_ListObjects.push_back(ob);
			} 							
			
			//*************ENEMIES****************//
			
			else if(_objecttype == "SCREW_BOMBER"){
				CScrewBomber *ob = new CScrewBomber(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "SCREW_BOMBER_D"){
				CScrewBomber *ob = new CScrewBomber(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), false);
				m_ListObjects.push_back(ob);
			}else if(_objecttype == "OCTOPUS") {
				COctopus *ob = new COctopus(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "OCTOPUS_D") {
				COctopus *ob = new COctopus(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), false);
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "MET") {
				CMet *ob = new CMet(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "BEAK") {
				CBeak *ob = new CBeak(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			}	else if(_objecttype == "FLEA") {
				CFlea *ob = new CFlea(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			}	else if(_objecttype == "SPINE") {
				CSpine *ob = new CSpine(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			}	else if(_objecttype == "BEAK") {
				CBeak *ob = new CBeak(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			}	 else if(_objecttype == "BEAK_R") {
				CBeak *ob = new CBeak(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0), false);
				m_ListObjects.push_back(ob);
			}else if(_objecttype == "BIGEYE"){
				CBigEye *bigEye = new CBigEye(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(bigEye);
			} 
			//*************BOSS****************//
			
			else if(_objecttype == "ICEMAN"){				
				CIceMan *ob = new CIceMan(_idObject, D3DXVECTOR3((float)_pos.x,(float)_pos.y,0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "CUTMAN"){
				CCutMan *ob = new CCutMan(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			} else if(_objecttype == "GUTSMAN"){
				CGutsMan *ob = new CGutsMan(_idObject, D3DXVECTOR3((float)_pos.x, (float)_pos.y, 0));
				m_ListObjects.push_back(ob);
			} 
		}
	}
}
