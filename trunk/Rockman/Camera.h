#ifndef CAMERA_H_
#define CAMERA_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

#include "Define.h"

class CCamera
{
private:
	D3DXVECTOR2 m_pos;
	D3DXVECTOR2 m_size;
	D3DXMATRIX m_viewPort;
	RECT m_rectCamera;

public:
	void Update(D3DXVECTOR2);

	CCamera(void);
	CCamera(D3DXVECTOR2);

	D3DXMATRIX GetMatrixCamera();
	D3DXVECTOR2 GetPosCamera();
	~CCamera(void);
};

#endif