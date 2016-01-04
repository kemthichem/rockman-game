#include "Blader.h"
#include "Rockman.h"
#include "ResourceManager.h"
#include "Define.h"
#include "Config.h"

#define VELLOC_X (50.0f)
D3DXVECTOR2 POS_INVALID  = D3DXVECTOR2(-1,-1);

CBlader::CBlader(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BLADER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(95,350), 2, 1, D3DXVECTOR2(15,310), D3DXVECTOR2(0,0), D3DXVECTOR2(20,0));
	m_pos = _pos;	
	m_posOrg = _pos;
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
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(95, 350), 2, 1, D3DXVECTOR2(15, 330), D3DXVECTOR2(0, 0), D3DXVECTOR2(20, 0));
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);
	m_pos.z = DEPTH_MOTION;

	m_posOrg = m_pos;
	m_state = Bide;
	disBack = 0;
	m_posAttack = POS_INVALID;
	m_isCompleteAttack = false;
	m_velloc.x = -CConfig::ValueOf(KEY_BD_VX);
	m_rangeItem = 3;

	UpdateRect();
}

CBlader::~CBlader(void)
{
}

void CBlader::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (!m_IsLife) return CEnemy::Update(_time, _camera, _input, _listObjectInViewPort);

	if (m_state == Bide) {
		int disX = abs(CRockman::g_PosRockman.x - m_pos.x);
		int disY = abs(CRockman::g_PosRockman.y - m_pos.y);

		if (disX < CConfig::ValueOf(KEY_BD_DIS_ATTACK)) {
 			m_posAttack.x = CRockman::g_PosRockman.x;
			m_posAttack.y = CRockman::g_PosRockman.y;

			char dir = m_posAttack.y - m_posOrg.y > 0 ? 1 : -1;
			m_velloc.y = (double)(dir * CConfig::ValueOf(KEY_BD_VY_ACTTACK) * disY);

			char dirX = m_velloc.x > 0 ? 1 : -1;
			m_velloc.x = dirX * abs(m_velloc.y) * disX / disY;

			m_isCompleteAttack = false;
			m_state = Attack;
		}
	} else
	if (m_state == Attack) {
		char dir = m_velloc.y > 0 ? 1 : -1;
		if (!m_isCompleteAttack && m_pos.y * dir >= m_posAttack.y * dir) {
			m_velloc.y = -1 * m_velloc.y;
			m_isCompleteAttack = true;
		}
		else if (m_isCompleteAttack &&m_pos.y * dir >= m_posOrg.y * dir) {
			m_velloc.y = 0;
			m_state = Back;
		}
	} else {
		if (disBack < 40) {
			disBack += CConfig::ValueOf(KEY_BD_VX);
		} else
		{
			m_velloc.x = CRockman::g_PosRockman.x > m_pos.x ? CConfig::ValueOf(KEY_BD_VX) : -CConfig::ValueOf(KEY_BD_VX);
			disBack = 0;
			m_state = Bide;
		}
	}
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	m_Sprite->NextOf(_time, 0, 1);	 
}

void CBlader::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (!m_IsLife) return CEnemy::Render(_spriteHandle, _camera);
	CEntity::Render(_spriteHandle, _camera);
		
}

void CBlader::SetInjured(CEntity* _other)
{
	m_IsCheckCollision = false;
	m_IsLife = false;

	CreateItem();
}
bool CBlader::IsObtainCollision(CEntity* _other)
{
	if (_other->GetType() == ROCKMAN) {
		return true;
	}
	return false;
}

void CBlader::Reset()
{

}
