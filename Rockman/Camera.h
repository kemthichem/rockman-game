#ifndef CAMERA_H_
#define CAMERA_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

class CCamera
{
private:
	POINT m_pos;
	D3DXMATRIX m_matrixCamera;

	POINT *m_arrayPoint;
	int m_countPoint;
	int curIndex;
	int indexMoveTo;
	int GetNextIndexY(long _posY, float _vY);
	bool m_curIsBound;
public:
	static POINT g_PosCamera;
	static bool g_IsMoving;
	RECT m_viewPort;
	void Update(D3DXVECTOR2, D3DXVECTOR2);

	CCamera(void);
	CCamera(D3DXVECTOR2);

	void Initialize(POINT *array, int countPoint);
	D3DXMATRIX GetMatrixCamera();
	RECT GetViewPort();
	D3DXVECTOR2 GetPosCamera();
	void SetPosCamera(D3DXVECTOR2 _pos);
	~CCamera(void);
	void MoveMap();
};

#endif