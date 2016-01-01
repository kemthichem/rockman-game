#ifndef CAMERA_H_
#define CAMERA_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

enum DirectMove
{
	DIRECT_NONE,
	DIRECT_X,
	DIRECT_Y
};

class CCamera
{
private:
	POINT m_pos;
	D3DXMATRIX m_matrixCamera;

	POINT *m_arrayPoint;
	int m_countPoint;
	int curIndex;
	int m_indexMoveTo;
	int GetNextIndexY(POINT _pos, float _vY);
	int GetNextIndexX(POINT _pos, float _vY);
	bool m_curIsBoundY;
	bool m_NextIsMiddleX;

	DirectMove m_DirectMove;
	
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
	DirectMove MoveMap();
	void MoveMapY();
	void MoveMapX();
	void GetMiddlePoint(int _index, bool *isMiddleX, bool *isMiddelY);
};

#endif