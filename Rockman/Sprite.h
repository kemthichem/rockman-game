#ifndef  _SPRITE_H
#define  _SPRITE_H
#include <d3d9.h>
#include <d3dx9.h>
class CSprite
{
private:
	float  m_TimeWait;  //Chờ chuyển hình
	int m_WidthTexture;
	int m_HeightTexture;
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

	void Render(LPD3DXSPRITE _spriteHandler, D3DXVECTOR3 _pos, int _dir);
	void Next(float _time);
	void NextOf(float _time, int indexStart, int indexEnd);
	void NextAt(float _time, int, int);
	void IndexOf(int _index);

	int GetWidthRectSprite();
	int GetHeightRectSprite();
	RECT rect;
	~CSprite(void);
};
#endif 
