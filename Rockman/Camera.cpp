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

	curIndex1 = curIndex2 = 0;
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

void CCamera::Update(D3DXVECTOR2 _pos, D3DXVECTOR2 _velloc)
{
	bool isTurnLeft = _velloc.x < 0;
	int nextIndex = curIndex1 < m_countPoint - 1 ? curIndex1 + 1: m_countPoint -1;
	if (isTurnLeft) {
		nextIndex = curIndex1 > 0 ? curIndex1 - 1: 0;
	}







	bool isHavePointNextX = false;
	if (curIndex1 != nextIndex) {
		isHavePointNextX = m_arrayPoint[nextIndex].y == m_arrayPoint[curIndex1].y ? true : false;
	}

	//check next point follow x
	
	if (_pos.x > m_arrayPoint[curIndex1].x && isHavePointNextX) {
		m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
	}

	int dir = isTurnLeft ? -1 : 1;
	if (_pos.x * dir> m_arrayPoint[nextIndex].x *dir && isHavePointNextX) {
		curIndex1 = nextIndex;
	}

	//check pre point follow y
	if (0 < curIndex1 && curIndex1 < m_countPoint - 2) {
		int nextIndex = curIndex1 - 1;

		if (m_arrayPoint[curIndex1].x == m_arrayPoint[curIndex1 - 1].x) {

		}

		else
			//check next point follow y
			if (m_arrayPoint[curIndex1].x == m_arrayPoint[curIndex1 + 1].x) {
				//turn up
				if (_velloc.y > 0) {
					if (_pos.y > m_arrayPoint[curIndex1 + 1].y) {
						nextIndex = curIndex1 + 1;
					} 
				} 
				//turn down
				else if (_velloc.y < 0) {
					if (_pos.y < m_arrayPoint[curIndex1 + 1].y) {
						nextIndex = curIndex1 + 1;
					} 
				}
			}
			//check pre point follow y

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

void CCamera::Initialize(POINT *array, int countPoint)
{
	m_arrayPoint = array;
	m_countPoint = countPoint;

	curIndex1 = 0;
	if (countPoint >= 2) {
		curIndex2 = 1;
	}
}

RECT CCamera::GetCurrentRect()
{


	RECT rect;
	rect.top = m_arrayPoint[curIndex1].y > m_arrayPoint[curIndex2].y ? m_arrayPoint[curIndex1].y : m_arrayPoint[curIndex2].y;
	rect.left = m_arrayPoint[curIndex1].x < m_arrayPoint[curIndex2].x ? m_arrayPoint[curIndex1].x : m_arrayPoint[curIndex2].x;
	rect.bottom = rect.top - (abs(m_arrayPoint[curIndex1].y - m_arrayPoint[curIndex2].y));
	rect.right = rect.left + (abs(m_arrayPoint[curIndex1].x - m_arrayPoint[curIndex2].x));

	return rect;
}

bool CCamera::IsInRect(POINT inPoint)
{
	RECT r = GetCurrentRect();

	if (inPoint.x < r.left || inPoint.x > r.right
		|| inPoint.y < r.bottom || inPoint.y > r.top)
	{
		return false;
	}
	return true;
}

bool CCamera::g_IsMoveX = true;
