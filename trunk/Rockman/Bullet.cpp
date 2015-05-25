#include "Bullet.h"
#include "ResourceManager.h"

CBullet::CBullet(D3DXVECTOR3 _pos)
{
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(335,205), 1, 1, D3DXVECTOR2(320,190));
	m_pos = _pos;
	m_posInit = _pos;

	m_collision = new CAABBCollision();
	m_accel = D3DXVECTOR2(0,0);
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	m_IsActive = false;
}


CBullet::~CBullet(void)
{
}

void CBullet::UpdateCollison(CEntity* ,float)
{

}

void CBullet::SetVelloc(D3DXVECTOR2 _velloc)
{
	m_veloc = _velloc;
}

void CBullet::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	if (m_IsActive) {
		CEntity::Update(_time,_camera,_input,_listObjectInViewport);
	} else {
		m_pos = m_posInit;
	}

	if(m_Rect.left<0 || m_Rect.right>800||m_Rect.top>600||m_Rect.bottom<0)
	{
		m_IsActive = false;
	}
}

void CBullet::SetActive(bool _isActive)
{
	m_IsActive = _isActive;
}

void CBullet::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsActive) {
		CEntity::Render(_spriteHandle, _camera);
	}
}
