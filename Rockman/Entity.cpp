#include "Entity.h"
#include <windows.h>
#include <stdio.h>


CEntity::CEntity(void)
{
	mIsTurnLeft = false;
	mVeloc = D3DXVECTOR2(0,0);
	mAccel = D3DXVECTOR2(0,0);
}

void CEntity::Update(float deltaTime, CCamera *_camera, CInput *_input){
	//set is turn left
	if (mVeloc.x < 0) mIsTurnLeft = true;
	else if (mVeloc.x > 0) mIsTurnLeft = false;

	//set position
	UpdatePosition(deltaTime);



	if (1/*is rockman*/)
	{
		_camera->Update(D3DXVECTOR2(mPos.x, mPos.y));
	}
}

void CEntity::Render(LPD3DXSPRITE _spriteHandler, CCamera* _camera){

	D3DXMATRIX Scale;
	D3DXMatrixIdentity(&Scale);
	D3DXMatrixTransformation2D(&Scale, &D3DXVECTOR2(mPos.x, mPos.y), 0.0f, &D3DXVECTOR2(1.f, -1.f),NULL, 0.f, NULL);
	D3DXMatrixMultiply(&Scale,&Scale, &_camera->GetMatrixCamera());

	//flip sprite when move left
	D3DXMATRIX matrixFlip;
	D3DXVECTOR2 trans(2*(mPos.x - _camera->GetPosCamera().x ) + mSprite->widthOfSprite, 0);
	if (mIsTurnLeft) {
		D3DXMatrixTransformation2D(&matrixFlip
			,NULL//center of sprite
			,0.0f
			,new D3DXVECTOR2(-1,1)//flip Ox
			,NULL
			,0
			,&trans//distance transform
			);

		D3DXMatrixMultiply(&Scale,&Scale,&matrixFlip);
	}

	_spriteHandler->SetTransform(&Scale);

	mSprite->Render(_spriteHandler, D3DXVECTOR3(mPos.x,mPos.y,0), 1);
}

void CEntity::UpdatePosition(float _time)
{
	mVeloc += mAccel * _time;
	mPos.x += mVeloc.x * _time + 1.0f/2 *mAccel.x*_time*_time;
	mPos.y += mVeloc.y * _time + 1.0f/2 *mAccel.y*_time*_time;
}

CEntity::~CEntity(void)
{
	delete mSprite;
}
