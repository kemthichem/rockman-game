#include "ScoreEff.h"




CScoreEff::CScoreEff( D3DXVECTOR3 pos, int _score )
{
	this->pos = pos;
	score = _score;
	gFont = marioGame->GetLPFont();
	firstY = pos.y;
	//---
	rectToDraw.top = pos.y;
	rectToDraw.left = pos.x;
	rectToDraw.right = rectToDraw.left+WIDTHSCREEN;
	rectToDraw.bottom = rectToDraw.top+HEIGHTSCREEN;
	visible = true;
}


CScoreEff::~CScoreEff(void)
{
}

void CScoreEff::Update( CQuadTreeNode* root,DWORD t )
{
	pos.y-=3;
	if(firstY - pos.y>40)
		this->visible = false;
	
}

void CScoreEff::Render()
{
	string s = std::to_string(score);
	s.c_str();
	rectToDraw.top = pos.y;
	gFont->DrawText(NULL,s.c_str(),-1,&rectToDraw,NULL,D3DCOLOR_XRGB(255,255,255));
}
