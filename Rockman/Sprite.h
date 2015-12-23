#ifndef  _SPRITE_H
#define  _SPRITE_H
#include <d3d9.h>
#include <d3dx9.h>
#include "Camera.h"

#define  TIME_PER_ANIMATION (2.0f)

enum D3DX_RESIZE
{
	D3DX_RESIZE_NONE = 0x00000001,
	D3DX_RESIZE_FILL = 0x00000010,
};

class CSprite
{
private:
	float  m_TimeWait;  //Chờ chuyển hình
	int m_CurrentIndex;
	int m_CountPerRow;
	int m_CountPerCol;
	int m_CountSprite;

	D3DXVECTOR2 m_SizeSprite;
	D3DXVECTOR2 m_OffsetLeftTop;
	D3DXVECTOR2 m_OffsetRightBottom;
	D3DXVECTOR2 m_PosSrc;
	LPDIRECT3DTEXTURE9 m_Texture;	
public:
	CSprite(void);
	CSprite(LPDIRECT3DTEXTURE9 _texture, D3DXVECTOR2 _sizeTexture,
		int _countCol, int _countRow,
		D3DXVECTOR2 _posSrc = D3DXVECTOR2(0,0),
		D3DXVECTOR2 _offsetLeftTop = D3DXVECTOR2(0,0),
		D3DXVECTOR2 _offsetRightBottom = D3DXVECTOR2(0,0));

	void Render(LPD3DXSPRITE _spriteHandler, CCamera *_camera, D3DXVECTOR3 _pos, bool _isTurnLeft = false);
	void Next(float _time);
	void OneOf(int, int);
	void NextOf(float _time, int _indexStart, int indexEnd);
	void NextAt(float _time, int _indexStart, int indexEnd);
	void IndexOf(int _index);
	void Draw(LPD3DXSPRITE _spHandle, RECT _rectDraw, D3DX_RESIZE _styleResize);

	int GetWidthRectSprite();
	int GetHeightRectSprite();
	RECT rect;
	~CSprite(void);
};
#endif 
