#include "Blader.h"

CBlader::CBlader(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BLADER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(190,700), 2, 1, D3DXVECTOR2(30,655), D3DXVECTOR2(0,0), D3DXVECTOR2(45,0));
	m_pos = _pos;
	m_PosInit = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = 10;
	m_IsLife = true;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	UpdateRect();
}


CBlader::~CBlader(void)
{
}

void CBlader::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (!m_IsLife) return;
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);
	
	if (m_pos.x < m_PosInit.x - (WIDTH_SCREEN/4) || m_pos.x > m_PosInit.x + (WIDTH_SCREEN/4)) {
		m_velloc.x *= -1;
	}

	m_Sprite->NextOf(_time, 0, 1);	 
}

void CBlader::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);

	} 
}


void CBlader::UpdateCollison(CEntity* _other, float _time) {

	if (_other->GetType() == LAND) {
		m_pos.x = GetRect().left - 1;
		m_velloc.x *= -1;
	}
}

void CBlader::SetInjured(CEntity* _other)
{
	m_IsCheckCollision = false;
	m_IsLife = false;
}