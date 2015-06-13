#include "Camera.h"
#include "Rockman.h"
#include "MoveMap.h"
#include "Map.h"

D3DXVECTOR2 CCamera::g_PosCamera = D3DXVECTOR2(0,0);
CCamera::CCamera(void)
{
	m_pos = D3DXVECTOR2(0, HEIGHT_SCREEN*1);
	g_PosCamera = m_pos;
}

CCamera::CCamera(D3DXVECTOR2 _pos)
{
	m_pos = _pos;
	g_PosCamera = m_pos;
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
	if (_pos.x < CMap::g_widthMap - WIDTH_SCREEN/2)
	{
		m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
	}

	if (m_pos.x < 0)
	{
		m_pos.x =  0;
	}

	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	m_posInit = m_pos;
	g_PosCamera = m_pos;
}

D3DXVECTOR2 CCamera::GetPosCamera()
{
	return m_pos;
}

void CCamera::SetPosCamera(D3DXVECTOR2 _posRockMan)
{
	m_pos.y = ((int)(_posRockMan.y - 80)/HEIGHT_SCREEN + 1) * HEIGHT_SCREEN;
	m_pos.x = ((int)(_posRockMan.x/WIDTH_SCREEN)) * WIDTH_SCREEN;
}

void CCamera::Move(int _distanceY)
{ 
	int desY =  m_posInit.y + _distanceY;

	if (_distanceY < 0)
		if (m_pos.y > desY) {
			m_pos.y -= 5;
		} else
		{
			m_pos.y = desY;
			CMoveMap::g_IsMovingMap = false;
		}
	else {
		if (m_pos.y < desY) {
			m_pos.y += 5;
		} else
		{
			m_pos.y = desY;
			CMoveMap::g_IsMovingMap = false;
		}
	}
	
	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}

