#ifndef  _SPRITE_H
#define  _SPRITE_H
#include <d3d9.h>
#include <d3dx9.h>
class CSprite
{
private:
	float  waitNextImage;  //Chờ chuyển hình
	float  timePerImage; 
	int width;
	int height;
	int index;
	int numImagePerRow;
	int numImagePerCol;
	int count;
	LPDIRECT3DTEXTURE9 mTexture;
	void SetSpriteHandleDefault(LPD3DXSPRITE);
	void SetTransform(LPD3DXSPRITE, float x, float y, float dir);
//	void SetSpriteHandleDefault();
public:


	int widthOfSprite;
	int heightOfSprite;
	CSprite(void);
	CSprite(LPDIRECT3DTEXTURE9 _image, int _widthOfImage, int _heightOfImage, int _countCol, int _countRow);
	void Render(LPD3DXSPRITE _spriteHandler, D3DXVECTOR3 _pos, int _dir);
	void Next();
	void NextOf(int indexStart, int indexEnd);
	void NextAt(int, int);
	void IndexOf(int _index);
	RECT rect;
	~CSprite(void);
};
#endif 
