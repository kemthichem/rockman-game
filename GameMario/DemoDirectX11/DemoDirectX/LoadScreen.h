#include "MarioGame.h"

#ifndef _LSCREEN_H
#define  _LSCREEN_H

#define  SAVEPATH "Save/.txt"
#define  PARENTPATH "Save/"
#define  TYPE ".txt"
class CLoadScreen:public CMenuScreen
{
private:
vector<string> ListFileSave(string parentPath, char* type);
void ButtonCLick();
void OnKeyDown(int keyCode);
public:
	CLoadScreen(void);
	~CLoadScreen(void);
};
#endif // _LSCREEN_H


