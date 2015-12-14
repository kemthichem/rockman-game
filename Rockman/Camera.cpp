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

	curIndex = 0;
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

int CCamera::GetNextIndexY(long _posY, float _vY)
{
	
	POINT curPoint = m_arrayPoint[curIndex];
	int nIdx = (curIndex > m_countPoint - 2) ? -1 : curIndex + 1;
	int pIdx = curIndex < 0 ? -1 : curIndex - 1;
	int arr[2] = { nIdx, pIdx };

	int dir = _vY > 0 ? 1 : -1;

	int idx = -1;
	for (int i = 0; i < 2; i++)
	{
		idx = arr[i];
		if ( idx != -1) {

			if (m_arrayPoint[idx].x == curPoint.x && m_arrayPoint[idx].y * dir > curPoint.y * dir) {
				return idx;
			}
		}
	}

	return -1;
}

void CCamera::Update(D3DXVECTOR2 _pos, D3DXVECTOR2 _velloc)
{
	//X
	POINT pCur = m_arrayPoint[curIndex];
	bool isHaveNextPointX = false;
	bool isHavePrePointX = false;

	if (curIndex < m_countPoint - 2) {
		isHaveNextPointX = pCur.y == m_arrayPoint[curIndex + 1].y;
	}

	if (curIndex > 0) {
		isHavePrePointX = pCur.y == m_arrayPoint[curIndex -1].y;
	}

	if (isHaveNextPointX) {
		if (_pos.x > pCur.x) {
			m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
		}

		if (_pos.x > m_arrayPoint[curIndex + 1].x) {
			curIndex = curIndex + 1;
		}
	} else
	{
		if (isHavePrePointX) {
			if (_pos.x < pCur.x) {
				m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
			} 

			if (_pos.x < m_arrayPoint[curIndex - 1].x) {
				curIndex = curIndex - 1;
			}
		}
	}


	int nextIndexY = GetNextIndexY(pCur.y, _velloc.y);
	if (nextIndexY != -1) {
		int dir = _velloc.y > 0 ? 1 : -1;
		if (m_arrayPoint[nextIndexY].y * dir > _pos.y * dir) {
			//MoveY;
			int k = 0;
		}
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

	curIndex = 0;
}

RECT CCamera::GetCurrentRect()
{


	RECT rect = {0};

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
