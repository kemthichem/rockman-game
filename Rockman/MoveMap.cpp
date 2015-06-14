#include "MoveMap.h"
#include "Map.h"


int CMoveMap::g_DistanceMoveCameraY = HEIGHT_SCREEN;
int CMoveMap::g_DistanceMoveCameraX = WIDTH_SCREEN;
TypeMove CMoveMap::g_TypeMove = TypeMove::MOVENONE;


CMoveMap::CMoveMap(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = MOVEMAP;
	m_pos = _pos;
	m_Sprite = NULL;
	m_Rect.top = m_pos.y;
	m_Rect.left = m_pos.x;
	m_Rect.bottom = m_Rect.top - 1;
	m_Rect.right = m_Rect.left + 32;

	m_MoveDirect = 0;
}


CMoveMap::~CMoveMap(void)
{
}

void CMoveMap::Update(float , CCamera *, CInput *, vector<CEntity*>)
{
	if (m_pos.y > CCamera::g_PosCamera.y - HEIGHT_SCREEN/2) {
		m_pos.y = CCamera::g_PosCamera.y;
	} else {
		m_pos.y = CCamera::g_PosCamera.y;
	}
}

void CMoveMap::Render(LPD3DXSPRITE, CCamera*)
{
	/*Not Render*/
}


bool CMoveMap::IsCanWithDirect(bool _isUp)
{
	if (_isUp) {
		if (!(m_MoveDirect > 0)) {
			m_MoveDirect = 1;
			return true;
		}
	} else {
		if (!(m_MoveDirect < 0)) {
			m_MoveDirect = -1;
			return true;
		}
	}

	return false;
}

