#include "Camera.h"
#include "Rockman.h"
#include "MoveMap.h"
#include "Map.h"
#include "Define.h"

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
	bool isMoveX, isMoveY;

	//check next point follow x
	if (_pos.x > m_arrayPoint[curIndex].x) {
		m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
	}

	//check pre point follow x

	//check next point follow y
	//check pre point follow y

	if (_pos.x >= CMap::g_widthMap - WIDTH_SCREEN - 14 && m_pos.x <= CMap::g_widthMap - 2 * WIDTH_SCREEN) {
		CMoveMap::g_TypeMove = TypeMove::MOVEX;
		//MoveX(WIDTH_SCREEN);
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

void CCamera::SetPosCamera(D3DXVECTOR2 _pos)
{
	m_pos.y = _pos.y + HEIGHT_SCREEN;
	m_pos.x = _pos.x;

	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom = m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}

void CCamera::MoveY(int _distanceY)
{ 
	int desY =  m_posInit.y + _distanceY;

	if (_distanceY < 0)
		if (m_pos.y > desY) {
			m_pos.y -= 5;
		} else
		{
			m_pos.y = desY;
			CMoveMap::g_TypeMove = TypeMove::MOVENONE;
		}
	else {
		if (m_pos.y < desY) {
			m_pos.y += 5;
		} else
		{
			m_pos.y = desY;
			CMoveMap::g_TypeMove = TypeMove::MOVENONE;
		}
	}
	
	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}

void CCamera::MoveX(int _distanceX) 
{
	int desX =  m_posInit.x + _distanceX;

	if (m_pos.x < desX) {
		m_pos.x += 5;
	}
	else
	{
		m_pos.x = desX;
		CMoveMap::g_TypeMove = TypeMove::MOVENONE;
;
	}
	
	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom = m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}

RECT CCamera::GetViewPortEx()
{
	RECT rect = m_viewPort;
	rect.top += 50;
	return rect;
}

void CCamera::Initialize(POINT *array, int m_countPoint)
{
	m_arrayPoint = array;
	m_countPoint = countPoint;

	curIndex = 0;
}

bool CCamera::g_IsMoveX = true;
