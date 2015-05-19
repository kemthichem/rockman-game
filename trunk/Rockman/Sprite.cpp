#include "Sprite.h"

#define  TIME_PER_ANIMATION (3.0f)


CSprite::CSprite(void)
{
}
CSprite::CSprite(LPDIRECT3DTEXTURE9 _texture, int _width, int _height, int _countCol, int _countRow)
{
	mTexture = _texture;
	width = _width;
	height = _height;
	numImagePerCol = _countRow;
	numImagePerRow = _countCol;
	count = numImagePerCol*numImagePerRow;
	index = 0;
	waitNextImage = 0;
	timePerImage = 30;
	widthOfSprite = width/ numImagePerRow;
	heightOfSprite = height/numImagePerCol;
}
void CSprite::Next()
{
	waitNextImage += TIME_PER_ANIMATION;
	if(waitNextImage>=timePerImage)  //Chờ đến khi quá thời gian quy định thì chuyển frame kế tiếp
	{
		//	index = (index + count-1)% count;
		index = (index +1)%count;
		waitNextImage=0;
	}
}
void CSprite::IndexOf(int _index)
{
	index = _index;
}
void CSprite::NextOf(int indexStart, int indexEnd)
{
	if(index<indexStart)
		index = indexStart;
	waitNextImage+=TIME_PER_ANIMATION;
	if(waitNextImage>=timePerImage)  
	{		
		index++;
		if (index>indexEnd)
		{
			index = indexStart;
		}
		waitNextImage=0;
	}
}
void CSprite::Render(LPD3DXSPRITE _spriteHandler, D3DXVECTOR3 _pos, int _dir)
{
	RECT srect;
	srect.left = (index % numImagePerRow)*(widthOfSprite)+1;
	srect.top = (index / numImagePerRow)*(heightOfSprite)+1;
	srect.right = srect.left + widthOfSprite ;
	srect.bottom = srect.top + heightOfSprite +1;

	//---
	//SetFlipImage(dir, (float)x);
	//SetTransform(_spriteHandler, x,y,dir);
	_spriteHandler->Draw(
		mTexture,
		&srect,
		NULL,
		&_pos,
		D3DCOLOR_XRGB(0,255,255)
		);
	//SetSpriteHandleDefault(_spriteHandler);
}
void CSprite::SetSpriteHandleDefault(LPD3DXSPRITE _spriteHandler)
{
	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(&matrix
		,NULL//tâm của hình
		,0.0f
		,NULL//trục chéo của ma trận--phóng to, thu nhỏ, lật ngược hình
		,NULL
		,0
		,NULL//khoan dich chuyen toa do x,y theo vector2
		);
	_spriteHandler->SetTransform(&matrix);
}
void CSprite::NextAt( int index1, int index2)
{
	if(index1 == index2)
	{
		index = index1;
		return;
	}
	else if(index<index1)
		index = index1;
	waitNextImage+=TIME_PER_ANIMATION;
	if(waitNextImage>=timePerImage)  //Chờ đến khi quá thời gian quy định thì chuyển framekế tiếp
	{
		if(index==index1)
			index = index2;
		else
			index = index1;
		waitNextImage=0;
	}
}
CSprite::~CSprite(void)
{
}
void CSprite::SetTransform(LPD3DXSPRITE _spriteHandler, float x,float y, float dir)
{
	const int HEIGHT_SCREEN = 600;

	//--set camera
	LONG x0 = 0;//rockmanGame->rectScreen.left;
	LONG y0 =  0;//rockmanGame->rectScreen.top;

	//D3DXMATRIX matrixCamera;
	//D3DXVECTOR2 Transw(-x0,-y0);
	//D3DXMatrixTransformation2D(&matrixCamera,NULL,0.0f,NULL,NULL,0,&Transw);	
	//_spriteHandler->SetTransform(&matrixCamera);



	//flip coor
	D3DXMATRIX matrixFlipCoor;
	//D3DXVECTOR2 trans(0,-y0);
	D3DXVECTOR2 transCoor(0, HEIGHT_SCREEN -2 * y - height/numImagePerCol);
	D3DXVECTOR2 *vectorCoor = new D3DXVECTOR2(1,1);

	if(dir<0) {
		transCoor.x = 2*x+widthOfSprite;
		vectorCoor->x=-1;
	}

	D3DXMatrixTransformation2D(&matrixFlipCoor
		,NULL//tâm của hình
		,0.0f
		,vectorCoor//trục chéo của ma trận--phóng to, thu nhỏ, lật ngược hình theo truc Ox, Oy
		,NULL
		,0
		,&transCoor//khoang dich chuyen toa do x,y theo vector2
		);

	_spriteHandler->SetTransform(&matrixFlipCoor);
}
