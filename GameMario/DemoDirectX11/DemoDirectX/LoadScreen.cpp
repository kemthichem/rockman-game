#include "LoadScreen.h"


CLoadScreen::CLoadScreen(void)
{
	vector<string> l =  ListFileSave(PARENTPATH,TYPE);
	int n = l.size();
	for(int i = 0; i< n; i++)
	{
		AddButton(new CButtonText(l[i]));
	}
	menuTitle = "LOAD GAME";
	//---
	SoundManager::GetInst()->PlayBgSound(SOUND_B_OPTION_STATE,true);
}


CLoadScreen::~CLoadScreen(void)
{
}

vector<string> CLoadScreen::ListFileSave( string parentPath, char* type )
{
	vector<string> listFile;
	string filePath = parentPath;
	DIR *dir;
	struct  dirent *ent;
	if((dir = opendir(parentPath.c_str())) !=NULL)
	{
		while ((ent = readdir(dir))!=NULL)
		{
			string str = ent->d_name;
			std::size_t found = str.find(type);
			if (found!=std::string::npos)
			{
				str.erase(str.end()-4,str.end());
				listFile.push_back(str);
			}
		}
		closedir (dir);
	}
	return listFile;
}

void CLoadScreen::ButtonCLick()
{
	for(CButtonGame* b : listButton)
		if(b->selected)
		{
			CRescource::mapFilePath = ((CButtonText*)b)->filePathSave();
			list<CGameScreen*> listToLoad;
			listToLoad.push_back(new CGamePlayScreen());
			CLoadingScreen::Load(screenManager, true,listToLoad);
			return;
		}
		
}

void CLoadScreen::OnKeyDown( int keyCode )
{
	CMenuScreen::OnKeyDown(keyCode);
	switch (keyCode)
	{
	case DIK_ESCAPE:
		ExitScreen();
		screenManager->AddScreen(new CMainMenuScreen());
		break;
	default:
		break;
	}
}
