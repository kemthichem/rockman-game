#include "Camera.h"
#include "Rockman.h"
#include "Map.h"
#include "Define.h"

#define DIS_MOVE (5.0f)
#define OFFSET_MAP_Y (10.0f)


POINT CCamera::g_PosCamera = { 0 };
CCamera::CCamera(void)
{
	m_pos.x = 0;
	m_pos.y = HEIGHT_SCREEN;
	g_PosCamera = m_pos;
}

CCamera::CCamera(D3DXVECTOR2 _pos)
{
	m_pos.x = _pos.x;
	m_pos.y = _pos.y;
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

int CCamera::GetNextIndexY(POINT _pos, float _vY)
{
	if (_vY == 0) return -1;

	POINT curPoint = m_arrayPoint[curIndex];
	if (_pos.x > curPoint.x + WIDTH_SCREEN / 2 || _pos.x < curPoint.x - WIDTH_SCREEN / 2) return -1;
	
	int nIdx = (curIndex > m_countPoint - 2) ? -1 : curIndex + 1;
	int pIdx = curIndex < 0 ? -1 : curIndex - 1;
	int arr[2] = { nIdx, pIdx };

	int dir = _vY > 0 ? 1 : -1;

	int idx = -1;
	int reVal = -1;

	m_curIsBound = false;
	for (int i = 0; i < 2; i++)
	{
		idx = arr[i];
		if ( idx != -1) {
			if (m_arrayPoint[idx].x == curPoint.x && m_arrayPoint[idx].y * dir > curPoint.y * dir) {
				reVal =  idx;
			}
			m_curIsBound = (m_curIsBound == false) ? m_arrayPoint[idx].x != curPoint.x : true;
		}
	}

	return reVal;
}

void CCamera::Update(D3DXVECTOR2 _pos, D3DXVECTOR2 _velloc)
{
	//X
	POINT pCur = m_arrayPoint[curIndex];
	bool isHaveNextPointX = false;
	bool isHavePrePointX = false;

	if (curIndex < m_countPoint - 1) {
		isHaveNextPointX = pCur.y == m_arrayPoint[curIndex + 1].y;
	}

	if (curIndex > 0) {
		isHavePrePointX = pCur.y == m_arrayPoint[curIndex -1].y;
	}

	if (isHaveNextPointX) {
		if (_pos.x > pCur.x) {
			m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
		}else {
			m_pos.x = m_arrayPoint[curIndex].x - WIDTH_SCREEN / 2;
		}

		if (_pos.x > m_arrayPoint[curIndex + 1].x) {
			curIndex = curIndex + 1;
		}
	} else
	{
		if (isHavePrePointX) {
			if (_pos.x < pCur.x) {
				m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
			} else {
				m_pos.x = m_arrayPoint[curIndex].x - WIDTH_SCREEN / 2;
			}

			if (_pos.x < m_arrayPoint[curIndex - 1].x) {
				curIndex = curIndex - 1;
			}
		}
	}

	//Y
	POINT rPos = {_pos.x , _pos. y};
	int nextIndexY = GetNextIndexY(rPos, _velloc.y);

	if (nextIndexY != -1) {
		if (_velloc.y > 0 && m_arrayPoint[nextIndexY].y - m_arrayPoint[curIndex].y < HEIGHT_SCREEN && !m_curIsBound) {
			curIndex = nextIndexY;
			nextIndexY = GetNextIndexY(rPos, _velloc.y);
		}

		char dir = _velloc.y > 0 ? 1 : -1;
		long offsetY =  m_curIsBound ? HEIGHT_SCREEN / 2 + OFFSET_MAP_Y : 0;
		long temp = _velloc.y > 0 ? m_arrayPoint[curIndex].y + HEIGHT_SCREEN + OFFSET_MAP_Y - offsetY : m_arrayPoint[curIndex].y - offsetY;
		if ((_velloc.y < 0 ||_velloc.y > 0 && CRockman::m_IsClimbing) && _pos.y * dir > (temp)* dir) {
			if (m_pos.x == m_arrayPoint[curIndex].x - WIDTH_SCREEN / 2) {
				indexMoveTo = nextIndexY;
				MoveMap();
				return;
			}
		}
	}

	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}

D3DXVECTOR2 CCamera::GetPosCamera()
{
	return D3DXVECTOR2(m_pos.x, m_pos.y);
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

void CCamera::MoveMap()
{
	g_IsMoving = true;
	if (indexMoveTo != -1) {
		char dirX = m_arrayPoint[indexMoveTo].x - m_arrayPoint[curIndex].x == 0 ? 0 : (m_arrayPoint[indexMoveTo].x - m_arrayPoint[curIndex].x > 0 ? 1 : -1);
		char dirY = m_arrayPoint[indexMoveTo].y - m_arrayPoint[curIndex].y == 0 ? 0 : (m_arrayPoint[indexMoveTo].y - m_arrayPoint[curIndex].y > 0 ? 1 : -1);

		m_pos.x += dirX * DIS_MOVE;
		m_pos.y += dirY * DIS_MOVE;

		long temp = dirY == 1 ? m_arrayPoint[indexMoveTo].y + OFFSET_MAP_Y + HEIGHT_SCREEN : m_arrayPoint[curIndex].y - OFFSET_MAP_Y;
		if (m_arrayPoint[curIndex].x == m_arrayPoint[indexMoveTo].x && dirY *m_pos.y >= dirY * (temp)) {
			g_IsMoving = false;
			m_pos.y = temp;
			curIndex = indexMoveTo;
			indexMoveTo = -1;
		} 

		m_viewPort.left = m_pos.x;
		m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
		m_viewPort.top = m_pos.y;
		m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

		g_PosCamera = m_pos;
	}
}

RECT CCamera::GetViewPort()
{
	RECT rect = m_viewPort;
	return rect;
}

void CCamera::Initialize(POINT *array, int countPoint)
{
	m_arrayPoint = array;
	m_countPoint = countPoint;
	indexMoveTo = -1;

	curIndex = 0;
	m_curIsBound = true;
}
bool CCamera::g_IsMoving = false;
