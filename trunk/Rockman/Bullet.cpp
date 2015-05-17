#include "Bullet.h"
#include "ResourceManager.h"

CBullet::CBullet(D3DXVECTOR3 _pos)
{
	m_sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ITEMS), 32, 12, 1, 1);
	m_pos = _pos;

	m_collision = new CAABBCollision();
}


CBullet::~CBullet(void)
{
	delete m_collision;
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
	CEntity::Update(_time,_camera,_input,_listObjectInViewport);
}
