#include "Camera.h"
#include "Rockman.h"

CCamera::CCamera(void)
{
	m_pos = D3DXVECTOR2(0,600);
}

CCamera::CCamera(D3DXVECTOR2 _pos)
{
	m_pos = _pos;
}

D3DXMATRIX CCamera::GetMatrixCamera()
{
	D3DXMatrixIdentity(&m_viewPort);
	D3DXMatrixAffineTransformation(&m_viewPort , 1, &D3DXVECTOR3(0,0,0), &D3DXQUATERNION(0,0,0,0), &D3DXVECTOR3((float)-m_pos.x, (float) m_pos.y, 0));
	m_viewPort._22 = -1;

	return m_viewPort;
}


CCamera::~CCamera(void)
{
}

void CCamera::Update(D3DXVECTOR2 _pos)
{
	if (_pos.x < CRockman::posInMap.x - WIDTH_SCREEN/2)
	{
		//mPos.x = (float)_pos.x - WIDTH_SCREEN/2;
	}

	if (m_pos.x < 0)
	{
		m_pos.x =  0;
	}

	m_rectCamera.left = m_pos.x;
	m_rectCamera.right = m_rectCamera.left + 900;
	m_rectCamera.top = 1200;
	m_rectCamera.bottom =0;
}

D3DXVECTOR2 CCamera::GetPosCamera()
{
	return m_pos;
}
