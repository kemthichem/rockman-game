#include "BigEye.h"



CBigEye::CBigEye(D3DXVECTOR3 _pos)
{
	m_Type = ObjectType::BIGEYE;
	m_sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), 160, 630, 2, 6);
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_veloc.x = -5;
}


CBigEye::~CBigEye(void)
{
}

void CBigEye::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_deltaTime, _camera, _input, _listObjectInViewPort);
	m_sprite->NextAt(9,11);

	if (m_pos.x < 0 || m_pos.x > 800) {
		m_veloc.x *= -1;
	}
	
}

void CBigEye::Draw()
{

}

void CBigEye::Collision()
{

}
