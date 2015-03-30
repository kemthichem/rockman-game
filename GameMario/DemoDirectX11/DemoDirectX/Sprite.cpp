#include "Sprite.h"

CSprite::CSprite(void)
{
}
CSprite::CSprite(LPDIRECT3DTEXTURE9 _image, int _width, int _height, int _numImagePerRow, int _numImagePerCol)
{
	image = _image;
	width = _width;
	height = _height;
	numImagePerCol = _numImagePerCol;
	numImagePerRow = _numImagePerRow;
	count = numImagePerCol*numImagePerRow;
	index = 0;
	waitNextImage = 0;
	timePerImage = 30;
	_spriteHandler = marioGame->GetSpriteHandle();
	widthOfSprite = width/ numImagePerRow;
	heightOfSprite = height/numImagePerCol;
}
void CSprite::Next()
{
	waitNextImage+=timePerFrame;
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
	waitNextImage+=timePerFrame;
	if(waitNextImage>=timePerImage)  //Chờ đến khi quá thời gian quy định thì chuyển framekế tiếp
	{
	/*index =(index<indexStart)?indexStart:index;
		index++;
	if(index ==indexEnd+1)
		index = indexStart;*/
		index++;
		if (index>indexEnd)
		{
			index = indexStart;
		}

	waitNextImage=0;
	}
}
void CSprite::Render(int x, int y, float dir,float z)
{
	RECT srect;
	srect.left = (index % numImagePerRow)*(widthOfSprite)+1;
	srect.top = (index / numImagePerRow)*(heightOfSprite)+1;
	srect.right = srect.left + widthOfSprite ;
	srect.bottom = srect.top + heightOfSprite +1;

	D3DXVECTOR3 position((float)x, (float)y, z);

	//---
	//SetFlipImage(dir, (float)x);
	SetTransform(x,dir);
	_spriteHandler->Draw(
		image,
		&srect,
		NULL,
		&position,
		D3DCOLOR_XRGB(255,255,255)
		);
	SetSpriteHandleDefault();


	///cập nhật lại RECT
	rect.top = y;
	rect.left = x;
	rect.bottom = y+height;
	rect.right = x+width;
}
void CSprite::SetSpriteHandleDefault()
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
	waitNextImage+=timePerFrame;
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
	image->Release();
	_spriteHandler->Release();

}
void CSprite::SetTransform(float x, float dir)
{
	//--set camera
	LONG x0 = marioGame->rectScreen.left;
	LONG y0 =  marioGame->rectScreen.top;

	D3DXMATRIX matrixCamera;
	D3DXVECTOR2 Transw(-x0,-y0);
	D3DXMatrixTransformation2D(&matrixCamera,NULL,0.0f,NULL,NULL,0,&Transw);	
	_spriteHandler->SetTransform(&matrixCamera);


	//--set flip image

	if(dir>=0)
		return;
	D3DXMATRIX matrixFlip;
	D3DXVECTOR2 trans(2*x+widthOfSprite,-y0);
	if(x0>0)
		 trans = D3DXVECTOR2(2*x-(x0-widthOfSprite),-y0);
	D3DXMatrixTransformation2D(&matrixFlip
		,NULL//tâm của hình
		,0.0f
		,new D3DXVECTOR2(-1,1)//trục chéo của ma trận--phóng to, thu nhỏ, lật ngược hình theo truc Ox, Oy
		,NULL
		,0
		,&trans//khoang dich chuyen toa do x,y theo vector2
		);
	_spriteHandler->SetTransform(&matrixFlip);
}
