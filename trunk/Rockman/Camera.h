#ifndef CAMERA_H_
#define CAMERA_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

#include "Define.h"

class CCamera
{
private:
	D3DXVECTOR2 m_posInit;
	D3DXVECTOR2 m_pos;
	D3DXMATRIX m_matrixCamera;
public:
	static D3DXVECTOR2 g_PosCamera;
	RECT m_viewPort;
	void Update(D3DXVECTOR2);

	CCamera(void);
	CCamera(D3DXVECTOR2);

	D3DXMATRIX GetMatrixCamera();
	D3DXVECTOR2 GetPosCamera();
	void SetPosCamera(D3DXVECTOR2 _pos);
	~CCamera(void);
	void Move(int);
	void MoveX(int);
};

#endif