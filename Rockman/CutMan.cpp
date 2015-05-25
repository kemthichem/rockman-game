#include "CutMan.h"

CCutMan::CCutMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = CUTMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(450,140) , 9, 2);
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_veloc.x = -10;
	m_accel.y = -20.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
}


CCutMan::~CCutMan(void)
{
}

void CCutMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	if (m_pos.x < 0 || m_pos.x > 800) {
		m_veloc.x *= -1;
	}

	if( m_pos.y <= 135){
		m_veloc.y = 80.0f;
	}

	m_Sprite->NextOf(_time,0,9);
	
}

void CCutMan::Draw()
{

}

void CCutMan::Collision()
{

}
