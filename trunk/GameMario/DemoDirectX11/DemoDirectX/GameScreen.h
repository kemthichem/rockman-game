#include "MarioGame.h"
#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H
using namespace std;
class CScreenManager;
class CGameScreen 
{
private:
	bool UpdateTransition(DWORD gameTime, DWORD time, int direction);
protected:
	CGameScreen();	

public:
	enum StateScreen
	{
		TransitionOn,
		Actived,
		TransitionOff,
		Hidden,
	};
	~CGameScreen(void);
	CScreenManager* screenManager;
	bool otherScreenHasFocus;
	bool coverByOtherScreen;
	bool isExiting;
	DWORD transTimeOn;
	DWORD transTimeOff;
	bool isPopup;
	float transPosition;

	StateScreen stateScreen;
	RECT rectToDrawText;
	//--
	virtual void Update(DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen);
	virtual void Draw(DWORD deltaTime)=0;
	virtual void Active()=0;
	virtual void RenderTextAndSurface(){};
	bool IsActive();
	bool ExitScreen();
	float TransAlpha();
	int TransAlphaRGB();
	///Events
	virtual void InKey(DWORD deltaTime);
	virtual void OnKeyDown(int keyCode);
	virtual void OnKeyUp(int keyCode);

};

#endif