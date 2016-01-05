#include "Camera.h"
#include "Rockman.h"
#include "Map.h"
#include "Define.h"
#include "Config.h"
#include "PLayingGameState.h"


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

	m_curIsBoundY = false;
	for (int i = 0; i < 2; i++)
	{
		idx = arr[i];
		if ( idx != -1) {
			if (m_arrayPoint[idx].x == curPoint.x && m_arrayPoint[idx].y * dir > curPoint.y * dir) {
				reVal =  idx;
			}
			m_curIsBoundY = (m_curIsBoundY == false) ? m_arrayPoint[idx].x != curPoint.x : true;
		}
	}

	return reVal;
}

void CCamera::Update(D3DXVECTOR2 _pos, D3DXVECTOR2 _velloc)
{
	if (_velloc == D3DXVECTOR2(0,0) || g_IsMoving) 
		return;
	if (curIndex == m_countPoint-1) {
		m_pos.x = m_arrayPoint[curIndex].x - WIDTH_SCREEN/2;

		if (CPLayingGameState::g_Stage==3) //cheat 
			{
				m_pos.x += 10;
				m_pos.y =  m_arrayPoint[curIndex].y + HEIGHT_SCREEN/2;
			}
		goto updateViewport;
		return;
	}
	{
		POINT rPos = {_pos.x , _pos. y};
		//X
		if (_velloc.x != 0) {
			POINT pCur = m_arrayPoint[curIndex];

			bool isHaveNextX = (curIndex < m_countPoint -1) & (pCur.y == m_arrayPoint[curIndex+1].y);
			bool isHavePreX = (curIndex > 0) & (pCur.y == m_arrayPoint[curIndex-1].y);
			bool isNextMiddleX = false;
			GetMiddlePoint(curIndex + 1, &isNextMiddleX, NULL);
			bool isCurMiddleX = false;
			GetMiddlePoint(curIndex, &isCurMiddleX, NULL);

			if (isNextMiddleX || (isHaveNextX && curIndex==m_countPoint-2)) { 
				m_indexMoveTo = curIndex + 1; m_DirectMove = DIRECT_X;
			}

			if (_velloc.x > 0 && isHaveNextX) {
				int boundX = isNextMiddleX ? m_arrayPoint[curIndex + 1].x - WIDTH_SCREEN / 2 : m_arrayPoint[curIndex + 1].x;
				int temp = isCurMiddleX ? pCur.x + WIDTH_SCREEN/2 : pCur.x;

				if (rPos.x > temp && rPos.x < boundX) {
					m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
				}

				if (rPos.x > m_arrayPoint[curIndex + 1].x) {
					curIndex = curIndex + 1;
				}
			} else {
				if (_velloc.x < 0) {
					if ((isHavePreX && curIndex != m_countPoint-1) || isCurMiddleX) {
						if (rPos.x < pCur.x) {
							curIndex = curIndex -1;
						}
						if (isCurMiddleX) {
							if (rPos.x > pCur.x + WIDTH_SCREEN/2) {
								m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
							}
						}

					} else {
						int boundX = isNextMiddleX ? m_arrayPoint[curIndex + 1].x - WIDTH_SCREEN / 2 : m_arrayPoint[curIndex + 1].x;
						if (rPos.x > pCur.x && rPos.x < boundX && curIndex != m_countPoint-1) {
							//update
							m_pos.x = (float)_pos.x - WIDTH_SCREEN/2;
						}
					}
				}
			}
		}


		//Y
		if (_velloc.y != 0) {
			int nextIndexY = GetNextIndexY(rPos, _velloc.y);

			if (nextIndexY != -1) {
				if (_velloc.y > 0 && m_arrayPoint[nextIndexY].y - m_arrayPoint[curIndex].y < HEIGHT_SCREEN && !m_curIsBoundY) {
					curIndex = nextIndexY;
					nextIndexY = GetNextIndexY(rPos, _velloc.y);
				}

				char dirY = _velloc.y > 0 ? 1 : -1;
				long offsetY =  m_curIsBoundY ? HEIGHT_SCREEN / 2 + OFFSET_MAP_Y : 0;
				long temp = _velloc.y > 0 ? m_arrayPoint[curIndex].y + HEIGHT_SCREEN + OFFSET_MAP_Y - offsetY : m_arrayPoint[curIndex].y - offsetY;
				if ((_velloc.y < 0 ||_velloc.y > 0 && CRockman::m_IsClimbing) && _pos.y * dirY > (temp)* dirY) {
					if ((m_pos.x - m_arrayPoint[curIndex].x - WIDTH_SCREEN / 2) < 10) {
						m_indexMoveTo = nextIndexY;
						m_DirectMove = DIRECT_Y;
						MoveMap();
						return;
					}
				}
			}
		}
	}
updateViewport:
	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}


DirectMove CCamera::MoveMap()
{
	g_IsMoving = true;
	if (m_indexMoveTo != -1) {
		if (m_DirectMove== DIRECT_Y) 
			MoveMapY();
		else if (m_DirectMove == DIRECT_X) {
			MoveMapX();
		}

		m_viewPort.left = m_pos.x;
		m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
		m_viewPort.top = m_pos.y;
		m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

		g_PosCamera = m_pos;
	}

	return m_DirectMove;
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

RECT CCamera::GetViewPort()
{
	RECT rect = m_viewPort;
	return rect;
}

void CCamera::Initialize(POINT *array, int countPoint)
{
	m_arrayPoint = array;
	m_countPoint = countPoint;
	m_indexMoveTo = -1;

	m_DirectMove = DIRECT_NONE;

	curIndex = CConfig::ValueOf(KEY_CAMERA_CURRENT_POINT);
	m_curIsBoundY = true;

	m_pos.x = m_arrayPoint[curIndex].x - WIDTH_SCREEN/2;
	m_pos.y = m_arrayPoint[curIndex].y + HEIGHT_SCREEN/2;

	m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;
}

void CCamera::MoveMapY()
{
	char dirY = m_arrayPoint[m_indexMoveTo].y - m_arrayPoint[curIndex].y == 0 ? 0 : (m_arrayPoint[m_indexMoveTo].y - m_arrayPoint[curIndex].y > 0 ? 1 : -1);
	m_pos.y += dirY * CConfig::ValueOf(KEY_CAMERA_MOVE_Y);;

	long temp = dirY == 1 ? m_arrayPoint[m_indexMoveTo].y + OFFSET_MAP_Y + HEIGHT_SCREEN : m_arrayPoint[curIndex].y - OFFSET_MAP_Y;
	if (m_arrayPoint[curIndex].x == m_arrayPoint[m_indexMoveTo].x && dirY *m_pos.y >= dirY * (temp)) {
		g_IsMoving = false;
		m_pos.y = temp;
		curIndex = m_indexMoveTo;
		m_indexMoveTo = -1;

		m_DirectMove = DIRECT_NONE;
	} 


}

void CCamera::MoveMapX()
{
	g_IsMoving = true;
	//char dirX = m_arrayPoint[m_indexMoveTo].x - m_arrayPoint[curIndex].x == 0 ? 0 : (m_arrayPoint[m_indexMoveTo].x - m_arrayPoint[curIndex].x > 0 ? 1 : -1);
	m_pos.x += CConfig::ValueOf(KEY_CAMERA_MOVE_X);

	int compareX = m_indexMoveTo == m_countPoint - 1 ? m_arrayPoint[m_indexMoveTo].x - WIDTH_SCREEN / 2 : m_arrayPoint[m_indexMoveTo].x;

	if (m_pos.x > compareX) {
		g_IsMoving = false;
		curIndex = m_indexMoveTo;
	}

	/*m_viewPort.left = m_pos.x;
	m_viewPort.right = m_viewPort.left + WIDTH_SCREEN;
	m_viewPort.top = m_pos.y;
	m_viewPort.bottom =m_viewPort.top - HEIGHT_SCREEN;

	g_PosCamera = m_pos;*/
}

int CCamera::GetNextIndexX(POINT _pos, float _vX)
{
	POINT pCur = m_arrayPoint[curIndex];
	bool isHaveNextPointX = false;
	bool isHavePrePointX = false;
	int indexNext = -1;

	m_NextIsMiddleX = false;
	if (curIndex < m_countPoint - 1) {
		isHaveNextPointX = pCur.y == m_arrayPoint[curIndex + 1].y;
	}

	if (curIndex > 0) {
		isHavePrePointX = pCur.y == m_arrayPoint[curIndex -1].y;
	}

	if (isHaveNextPointX) {
		if (_vX > 0) {
			indexNext = curIndex + 1;
			m_NextIsMiddleX = (indexNext< m_countPoint -1 ) && (m_arrayPoint[indexNext].y == m_arrayPoint[indexNext + 1].y);
		}

	} 
	if (isHavePrePointX) {
		if (_vX < 0) {
			indexNext = curIndex - 1;

			m_NextIsMiddleX = (indexNext - 1 >= 0) && (m_arrayPoint[indexNext].y == m_arrayPoint[indexNext - 1].y);
		}
	}

	return indexNext;
}

void CCamera::GetMiddlePoint(int _index, bool *isMiddleX, bool *isMiddelY)
{
	if (_index > 0 && _index < m_countPoint - 1) {
		if (isMiddleX) {
			if (m_arrayPoint[_index-1].y == m_arrayPoint[_index].y && m_arrayPoint[_index+1].y == m_arrayPoint[_index].y) {
				*isMiddleX = true;
			}
		}
	}
}

bool CCamera::g_IsMoving = false;
