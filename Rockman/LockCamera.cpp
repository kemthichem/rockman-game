#include "LockCamera.h"

CLockCamera::CLockCamera(int _id, D3DXVECTOR3 _pos, bool _isLock)
{
	m_Id = _id;
	m_Type = _isLock ? BLOCK_CAMERA : UNLOCK_CAMERA;
	m_pos = _pos;
	m_Sprite = NULL;
	m_Rect.top = m_pos.y;
	m_Rect.left = m_pos.x;
	m_Rect.bottom = m_Rect.top - 1;
	m_Rect.right = m_Rect.left + 32;
}


CLockCamera::~CLockCamera(void)
{
}

void CLockCamera::Update(float , CCamera *, CInput *, vector<CEntity*>)
{
	/**/
}

void CLockCamera::Render(LPD3DXSPRITE, CCamera*)
{
	/*Not Render*/
}
