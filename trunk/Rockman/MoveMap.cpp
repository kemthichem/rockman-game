#include "MoveMap.h"
#include "Map.h"


int CMoveMap::g_DistanceMoveCameraY = HEIGHT_SCREEN;
bool CMoveMap::g_IsMovingMap = false;


CMoveMap::CMoveMap(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = MOVEMAPTYPE;
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
	/*Not Update*/
}

void CMoveMap::Render(LPD3DXSPRITE, CCamera*)
{
	/*Not Render*/
}

void CMoveMap::SetDirect(bool _isUp)
{
	m_MoveDirect = _isUp ? 1 : -1;
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

