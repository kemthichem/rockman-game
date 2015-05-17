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
	D3DXMatrixIdentity(&m_matrixCamera);
	D3DXMatrixAffineTransformation(&m_matrixCamera , 1, &D3DXVECTOR3(0,0,0), &D3DXQUATERNION(0,0,0,0), &D3DXVECTOR3((float)-m_pos.x, (float) m_pos.y, 0));
	m_matrixCamera._22 = -1;

	return m_matrixCamera;
}


CCamera::~CCamera(void)
{
}

void CCamera::Update(D3DXVECTOR2 _pos)
{
	if (_pos.x < CRockman::posInMap.x - WIDTH_SCREEN/2)
	{
		m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
	}

	if (m_pos.x < 0)
	{
		m_pos.x =  0;
	}

	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + 800;
	m_viewPort.top = 600;
	m_viewPort.bottom =0;
}

D3DXVECTOR2 CCamera::GetPosCamera()
{
	return m_pos;
}
