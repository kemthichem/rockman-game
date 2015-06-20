#include "BigEye.h"

CBigEye::CBigEye(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BIGEYE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(641,626) , 1, 2, D3DXVECTOR2(575,372), D3DXVECTOR2(0,30), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_PosInit = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}


CBigEye::~CBigEye(void)
{
}

void CBigEye::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_deltaTime, _camera, _input, _listObjectInViewPort);

	if (m_pos.x < m_PosInit.x - (WIDTH_SCREEN/2) || m_pos.x > m_PosInit.x + (WIDTH_SCREEN/2)) {
		m_velloc.x *= -1;
	}

	if( m_pos.y <= m_PosInit.y){
		m_velloc.y = 35.0f;
	}

	if(m_pos.y > m_PosInit.y + 25){
		m_Sprite ->IndexOf(1);
	}else{
		m_Sprite ->IndexOf(0);
	}

	
}

void CBigEye::Draw()
{

}

void CBigEye::Collision()
{

}
