#include "MarioGame.h"
#ifndef  _SPRITE_H
#define  _SPRITE_H

#define  timePerFrame (20)
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
	LPDIRECT3DTEXTURE9 image;
	void SetSpriteHandleDefault();
	void SetTransform(float x,float dir);
	LPD3DXSPRITE _spriteHandler;
//	void SetSpriteHandleDefault();
public:


	int widthOfSprite;
	int heightOfSprite;
	CSprite(void);
	CSprite(LPDIRECT3DTEXTURE9 _image, int _widthOfImage, int _heightOfImage, int _imagePerRow, int _imagePerCol);
	void Render(int x , int y, float direction, float z = 0);
	void Next();
	void NextOf(int indexStart, int indexEnd);
	void NextAt(int, int);
	void IndexOf(int _index);
	RECT rect;
	~CSprite(void);
};
#endif 
