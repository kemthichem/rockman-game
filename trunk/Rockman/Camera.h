#ifndef CAMERA_H_
#define CAMERA_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

#include "Define.h"

class CCamera
{
private:
	D3DXVECTOR2 mPos;
	D3DXVECTOR2 mSize;
	D3DXMATRIX mViewPort;
	RECT mRectCamera;

public:
	void Update(D3DXVECTOR2);

	CCamera(void);
	CCamera(D3DXVECTOR2);

	D3DXMATRIX GetMatrixCamera();
	D3DXVECTOR2 GetPosCamera();
	~CCamera(void);
};

#endif