#include "MarioGame.h"

#ifndef _SCROEEFF_H
#define _SCROEEFF_H
class CScoreEff:public CStaticObject
{
private:
	LPD3DXFONT gFont;
	int score;
	RECT rectToDraw;
	int firstY;
public:
	void Update(CQuadTreeNode* root,DWORD t);
	void Render();
	CScoreEff(D3DXVECTOR3 pos, int _score);
	~CScoreEff(void);
};

#endif // _SCROEEFF_H
