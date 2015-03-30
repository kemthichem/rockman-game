#include "SaveScreen.h"


CSaveScreen::CSaveScreen(void)
{
	saveButton = new CButtonText("Save");
	cancelButton = new CButtonText("Cancel");
	AddButton(saveButton);
	AddButton(cancelButton);
	gFont = marioGame->GetLPFont();
	//--
	menuTitle = "SAVE GAME";
}


CSaveScreen::~CSaveScreen(void)
{
	delete saveButton;
	delete cancelButton;
	gFont->Release();
}

void CSaveScreen::ButtonCLick()
{
	if(saveButton->selected) SaveClick();
	else CancelClick();
}

void CSaveScreen::CancelClick()
{
	ExitScreen();
}

void CSaveScreen::SaveClick()
{
	if(!name.size()>0) return;
	CusRect rectMap = CusRect(0,0, marioGame->quadTree->GetWidth(),marioGame->quadTree->GetHeight());
	list<CStaticObject*> listOb = marioGame->quadTree->ListObjectInRect(rectMap);
	string s = SAVEPATH;//"Save/.txt"
	s.insert(5,name);
	CMapIO::SaveMap(listOb,s);
	ExitScreen();
}

void CSaveScreen::RenderTextAndSurface()
{
	CMenuScreen::RenderTextAndSurface();
	rectToDrawText.top = 300;
	RECT r;
	r.top = 295;
	r.bottom = 325;
	int widthStr = name.size()*20+10;
	r.left = WIDTHSCREEN/2 - widthStr/2;
	r.right = WIDTHSCREEN/2 +widthStr/2;
	
	marioGame->GetDevice3d()->ColorFill(marioGame->_backbuffer,&r,D3DCOLOR_XRGB(255,255,255));
	gFont->DrawText(NULL,name.c_str(),-1,&rectToDrawText,DT_CENTER,D3DCOLOR_XRGB(0,0,255));
	rectToDrawText.top = 250;
	gFont->DrawText(NULL,"Type your name : ",-1,&rectToDrawText,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
}

void CSaveScreen::OnKeyDown( int keyCode )
{
	CMenuScreen::OnKeyDown(keyCode);
	
	switch (keyCode)
	{
		#pragma region Keyboard
	case DIK_Z:
		name.append("z");
		break;
	case DIK_X:
		name.append("x");
		break;
	case DIK_C:
		name.append("c");
		break;
	case DIK_V:

		name.append("v");
		break;
	case DIK_B:
		name.append("b");
		break;
	case DIK_N:
		name.append("n");
		break;
	case DIK_M:
		name.append("m");
		break;
	case DIK_A:
		name.append("a");
		break;
	case DIK_S:
		name.append("s");
		break;
	case DIK_D:
		name.append("d");
		break;
	case DIK_SPACE:
		name.append(" ");
		break;
	case DIK_F:
		name.append("f");
		break;
	case DIK_G:
		name.append("g");
		break;
	case DIK_H:
		name.append("h");
		break;
	case DIK_J:
		name.append("j");
		break;
	case DIK_K:
		name.append("k");
		break;
	case DIK_L:
		name.append("l");
		break;
	case DIK_Q:
		name.append("q");
		break;
	case DIK_W:
		name.append("w");
		break;
	case DIK_E:
		name.append("e");
		break;
	case DIK_R:
		name.append("r");
		break;
	case DIK_T:
		name.append("t");
		break;
	case DIK_Y:
		name.append("y");
		break;
	case DIK_U:
		name.append("u");
		break;
	case DIK_I:
		name.append("i");
		break;
	case DIK_O:
		name.append("o");
		break;
	case DIK_P:
		name.append("p");
		break;
	case DIK_1:
		name.append("1");
		break;
	case DIK_2:
		name.append("2");
		break;
	case DIK_3:
		name.append("3");
		break;
	case DIK_4:
		name.append("4");
		break;
	case DIK_5:
		name.append("5");
		break;
	case DIK_6:
		name.append("6");
		break;
	case DIK_7:
		name.append("7");
		break;
	case DIK_8:
		name.append("8");
		break;
	case DIK_9:
		name.append("9");
		break;
	case DIK_0:
		name.append("0");
		break;
	case DIK_BACKSPACE:
		if(name.size()>0)
			name.pop_back();
		break;
#pragma endregion Keyboard
	default:
		break;
	}
}
