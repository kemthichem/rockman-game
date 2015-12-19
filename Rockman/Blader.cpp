#include "Blader.h"
#include "Rockman.h"
#include "ResourceManager.h"

#define VELLOC_X (50.0f)

CBlader::CBlader(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BLADER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(95,350), 2, 1, D3DXVECTOR2(15,310), D3DXVECTOR2(0,0), D3DXVECTOR2(20,0));
	m_pos = _pos;
	m_PosInit = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_IsLife = true;
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());

	UpdateRect();
}
CBlader::CBlader(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = BLADER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(95, 350), 2, 1, D3DXVECTOR2(15,310), D3DXVECTOR2(0,0), D3DXVECTOR2(20,0));
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);
	m_PosInit = m_pos;
	m_IsLife = true;

	UpdateRect();
}

CBlader::~CBlader(void)
{
}

void CBlader::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (!m_IsLife) return;

	
	if (abs(CRockman::g_PosRockman.x - m_pos.x) <= 200 && m_pos.y >= m_PosInit.y ) {
		m_velloc.x = -VELLOC_X;
		m_velloc.y = -(abs(CRockman::g_PosRockman.y - m_pos.y) / 2);
		m_accel.y = 20.0f;
	}
	if (m_pos.y >= m_PosInit.y && CRockman::g_PosRockman.x - m_pos.x > 0) {
		m_velloc.x = -10;
		m_accel.y = m_velloc.y = 0;
	}


	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	m_Sprite->NextOf(_time, 0, 1);	 
}

void CBlader::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);
		
	} 
}


void CBlader::UpdateCollison(CEntity* _other, float _time) {

	if (_other->GetType() == BLOCK) {
		m_pos.x = GetRect().left - 1;
		m_velloc.x *= -1;
	}
}

void CBlader::SetInjured(CEntity* _other)
{
	m_IsCheckCollision = false;
	m_IsLife = false;
}