#include "Blader.h"

CBlader::CBlader(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BLADER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(190,700), 2, 1, D3DXVECTOR2(30,655), D3DXVECTOR2(0,0), D3DXVECTOR2(45,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_veloc.x = 10;
	//m_accel.y = -20.0f;
}


CBlader::~CBlader(void)
{
}

void CBlader::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);
	
	if (m_pos.x < 0 || m_pos.x > 800) {
		m_veloc.x *= -1;
	}


	m_Sprite->NextOf(_time, 0, 1);	 
}


void CBlader::UpdateCollison(CEntity* _orther, float _time) {
	if (_orther->GetType() != BLADER)
	{
		m_pos.x = GetRect().left;
		m_veloc.x *= -1;
	}
}
