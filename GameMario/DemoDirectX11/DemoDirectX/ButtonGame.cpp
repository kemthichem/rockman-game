#include "ButtonGame.h"


CButtonGame::CButtonGame(LPDIRECT3DTEXTURE9 image,RECT sRect)
{
	this->image = image;
	spriteHandle = marioGame->GetSpriteHandle();
	alpha = 0.0f;
	this->sRect = sRect;
	width = sRect.right-sRect.left;
	height = sRect.bottom - sRect.top;
	rotation = 1;
}

CButtonGame::CButtonGame()
{
	alpha = 0.0f;

}


CButtonGame::~CButtonGame(void)
{
	spriteHandle->Release();
	image->Release();
}

void CButtonGame::Update( DWORD deltaTime )
{
	
}

void CButtonGame::Draw( DWORD deltaTime )
{
	int _alpla = (int)(255*alpha);
	if(selected) { SetTransForm();_alpla = 100;}
	spriteHandle->Draw(image, &sRect, NULL, &pos,D3DCOLOR_XRGB(_alpla,_alpla,_alpla));
	SetDeafaultTrans();
}

void CButtonGame::SetTransForm()
{
	rotation*=-1;
	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(&matrix
		//,
		,NULL//tâm của hình
		,0.0f
		,new D3DXVECTOR2(1,1)//trục chéo của ma trận--phóng to, thu nhỏ, lật ngược hình theo truc Ox, Oy
		,new D3DXVECTOR2(pos.x+width/2,pos.y+height/2)//tâm của hình
		,(PI/180)*rotation
		,NULL//khoan dich chuyen toa do x,y theo vector2
		);
	spriteHandle->SetTransform(&matrix);
}

void CButtonGame::SetDeafaultTrans()
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
	spriteHandle->SetTransform(&matrix);
}

string CButtonText::filePathSave()
{
	string s = SAVEPATH;//"Save/.txt"
	s.insert(5,buttonTitle);
	return s;
}

void CButtonText::Draw( DWORD deltaTime )
{
	

}

void CButtonText::Update( DWORD deltaTime )
{

}

CButtonText::CButtonText( string text ):CButtonGame()
{
	buttonTitle = text;
	sRect.top = sRect.left = 0;
	sRect.bottom = 30;
	sRect.right = buttonTitle.length()*20;
	//---------
	gFont = marioGame->GetLPFont();
	d3ddv = marioGame->GetDevice3d();
}
CButtonText::~CButtonText( void )
{
	gFont->Release();
	d3ddv->Release();
}

void CButtonText::DrawText()
{
	RECT rectText;
	rectText.left = 0;
	rectText.bottom  =600;
	rectText.right = 800;
	rectText.top = pos.y;
	int widthButton = sRect.right-sRect.left;
	sRect.left = WIDTHSCREEN/2-widthButton/2;
	sRect.right = WIDTHSCREEN/2+widthButton/2;
	sRect.top = pos.y-5;
	sRect.bottom = sRect.top+30;
	if(selected)
		d3ddv->ColorFill(marioGame->_backbuffer,&sRect,D3DCOLOR_XRGB(243,240,57));
	else 	d3ddv->ColorFill(marioGame->_backbuffer,&sRect,D3DCOLOR_XRGB(255,255,255));
	gFont->DrawText(NULL, buttonTitle.c_str(),-1,&rectText,DT_CENTER,D3DCOLOR_XRGB(29,58,5));
}
