#include "Camera.h"

#include "Rockman.h"

CCamera::CCamera(void)
{
	mPos = D3DXVECTOR2(0,600);
}

CCamera::CCamera(D3DXVECTOR2 _pos, bool _isMoveRight)
{
	mPos = _pos;
	mIsMoveRight = _isMoveRight;
}

D3DXMATRIX CCamera::GetMatrixCamera()
{
	D3DXMatrixIdentity(&mViewPort);
	D3DXMatrixAffineTransformation(&mViewPort , 1, &D3DXVECTOR3(0,0,0), &D3DXQUATERNION(0,0,0,0), &D3DXVECTOR3((float)-mPos.x, (float) mPos.y, 0));
	mViewPort._22 = -1;

	return mViewPort;
}


CCamera::~CCamera(void)
{
}

void CCamera::Update(D3DXVECTOR2 _pos)
{
	//if (_pos.x < CRockman::posInMap.x - 400)
	//{
		mPos.x = (float)_pos.x - 400;

	//}

	if (mPos.x < 0)
	{
		mPos.x =  0;
	}

	mRectCamera.left = mPos.x;
	mRectCamera.right = mRectCamera.left + 900;
	mRectCamera.top = 1200;
	mRectCamera.bottom =0;
}

D3DXVECTOR2 CCamera::GetPosCamera()
{
	return mPos;
}
