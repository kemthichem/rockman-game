#include "ResourceManager.h"
#include "Spine.h"
#include "Define.h"
#include "Rockman.h"

CSpine::CSpine(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = SPINE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(504, 208) , 2, 1, D3DXVECTOR2(352,190), D3DXVECTOR2(0,0), D3DXVECTOR2(44,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc = D3DXVECTOR2(2, 0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CSpine::CSpine(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = SPINE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(255, 104) , 2, 1, D3DXVECTOR2(175, 95), D3DXVECTOR2(0,0), D3DXVECTOR2(22, 0));


	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);
	m_posOrg = m_pos;

	m_rectCollide.left = posXCollide;
	m_rectCollide.top = posYCollide;
	m_rectCollide.right = m_rectCollide.left + widthCollide;
	m_rectCollide.bottom = m_rectCollide.top + heightCollide;

	UpdateRect();
}

CSpine::~CSpine(void)
{
}

void CSpine::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{	
	if (m_IsLife) {
		m_Sprite->Next(_deltaTime);

		D3DXVECTOR3 rPos = CRockman::g_PosRockman;
		if (rPos.x < m_rectCollide.right && rPos.x > m_rectCollide.left) {
			m_velloc.x = m_velloc.x > 0 ? 15 : -15;
		} else
		{
			m_velloc.x = m_velloc.x > 0 ? 2 : -2;
		}

		if (m_pos.x > m_rectCollide.right - m_Size.x || m_pos.x < m_rectCollide.left) {
			m_velloc *= -1;
		}

		m_pos.x += m_velloc.x * _deltaTime + 1.0f/2 * m_accel.x *_deltaTime * _deltaTime;
		UpdateRect();

	}
	else {
		CEnemy::Update(_deltaTime, _camera, _input, _listObjectInViewPort);
	}
}
