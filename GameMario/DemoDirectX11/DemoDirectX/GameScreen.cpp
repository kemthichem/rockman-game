#include "GameScreen.h"

CGameScreen::~CGameScreen(void)
{
}

bool CGameScreen::UpdateTransition( DWORD timeFrame, DWORD time, int direction )
{
	// How much should we move by?
	float transitionDelta;

	if (time == 0)
		transitionDelta = 1;
	else
		transitionDelta = (float)((float)timeFrame/ (float)time);

	// Update the transition position.
	transPosition += transitionDelta * direction;

	// Did we reach the end of the transition?
	if (((direction < 0) && (transPosition <= 0)) ||
		((direction > 0) && (transPosition >= 1)))
	{
		if(transPosition<0)transPosition=0;
		else if(transPosition > 1)transPosition = 1;
		return false;
	}

	// Otherwise we are still busy transitioning.
	return true;
}

void CGameScreen::Update( DWORD deltaTime, bool otherScreenHasFocus,bool coverByOtherScreen )
{
	this->otherScreenHasFocus = otherScreenHasFocus;

	if (isExiting)
	{
		// If the screen is going away to die, it should transition off.
		stateScreen = StateScreen::TransitionOn;

		if (!UpdateTransition(deltaTime,transTimeOff, 1))
		{
			// When the transition finishes, remove the screen.
			screenManager->RemoveScreen(this);
		}
	}
	else
	{
		// Otherwise the screen should transition on and become active.
		if (UpdateTransition(deltaTime, transTimeOn, -1))
		{
			// Still busy transitioning.
			stateScreen = StateScreen::TransitionOn;
		}
		else
		{
			// Transition finished!
			stateScreen = StateScreen::Actived;
		}
	}
}

bool CGameScreen::ExitScreen()
{
	if (transTimeOff == 0)
	{
		// If the screen has a zero transition time, remove it immediately.
		screenManager->RemoveScreen(this);
	}
	else
	{
		// Otherwise flag that it should transition off and then exit.
		isExiting = true;
	}
	return true;
}

CGameScreen::CGameScreen()
{
	transTimeOff = transTimeOn = 0;
	transPosition = 1;
	stateScreen = StateScreen::TransitionOn;
	isPopup = false;
	isExiting = false;
	rectToDrawText.top = 0;
	rectToDrawText.left = 0;
	rectToDrawText.right = 800;
	rectToDrawText.bottom = 600;
}

float CGameScreen::TransAlpha()
{
	return 1.0f - transPosition;
}

int CGameScreen::TransAlphaRGB()
{
	return (int)(TransAlpha()*255);
}


//------------------
void CGameScreen::InKey( DWORD deltaTime )
{

}

void CGameScreen::OnKeyDown( int keyCode )
{

}

void CGameScreen::OnKeyUp( int keyCode )
{

}

bool CGameScreen::IsActive()
{
	return !otherScreenHasFocus &&
		(stateScreen == StateScreen::TransitionOn ||
		stateScreen == StateScreen::Actived);
}

