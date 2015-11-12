#ifndef _SCENERY_H_
#define _SCENERY_H

#include "Sprite.h"
#include "Camera.h"
class CSceneryTile
{
private:
	int **m_ArrayMapTile;
	POINT m_PStart;
	POINT m_PEnd;
	CSprite *m_Sprite;
	int m_RowBitmap;
	int m_ColBitmap;
	int m_ColArray;
	int m_RowArray;
public:
	void Render(LPD3DXSPRITE _spriteHandle, CCamera *_camera);
	void Update(RECT _rectToRender);

	CSceneryTile();
	CSceneryTile(LPDIRECT3DTEXTURE9 _texture, int **arrayMapTitle, int _row, int _col, int _countTile);
	~CSceneryTile(void);
};
#endif
