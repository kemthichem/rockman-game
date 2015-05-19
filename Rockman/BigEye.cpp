#include "BigEye.h"



CBigEye::CBigEye(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BIGEYE;
	m_sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), 800, 630, 10, 6);
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_veloc.x = -5;
	m_accel.y = -20.0f;
}


CBigEye::~CBigEye(void)
{
}

void CBigEye::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_deltaTime, _camera, _input, _listObjectInViewPort);
	//m_sprite->NextAt(49, 59);

	if (m_pos.x < 0 || m_pos.x > 800) {
		m_veloc.x *= -1;
	}

	if( m_pos.y <= 135){
		m_veloc.y = 80.0f;
	}

	if(m_pos.y > 135){
		m_sprite ->IndexOf(49);
	}else{
		m_sprite ->IndexOf(59);
	}

	
}

void CBigEye::Draw()
{

}

void CBigEye::Collision()
{

}
