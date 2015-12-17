#include "BigEye.h"

CBigEye::CBigEye(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = BIGEYE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(641,626) , 1, 2, D3DXVECTOR2(575,372), D3DXVECTOR2(0,30), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;
	m_Blood = 10;
	m_IsLife = true;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}
CBigEye::CBigEye(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;

	m_Type = BIGEYE;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(641,626) , 1, 2, D3DXVECTOR2(575,372), D3DXVECTOR2(0,30), D3DXVECTOR2(0,0));
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);
	m_velloc.x = -10;
	m_accel.y = -5.0f;
	m_Blood = 10;
	m_IsLife = true;

	UpdateRect();
}

CBigEye::~CBigEye(void)
{
}

void CBigEye::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	if (!m_IsLife) return;
	CEntity::Update(_deltaTime, _camera, _input, _listObjectInViewPort);

	//if (m_pos.x < m_PosInit.x - (WIDTH_SCREEN/2) || m_pos.x > m_PosInit.x + (WIDTH_SCREEN/2)) {
	//	m_velloc.x *= -1;
	//}

	//if( m_pos.y <= m_PosInit.y){
	//	m_velloc.y = 35.0f;
	//}

	if(m_velloc.y > 34.0f){
		m_Sprite ->IndexOf(0);
	}else{
		m_Sprite ->IndexOf(1);
	}

	
}
void CBigEye::UpdateCollison(CEntity* _other,float _time)
{
	switch (_other->GetType())
	{
	case BLOCK:	
	default:
		break;
	}
}

void CBigEye::ExecuteCollision(CEntity* _other,DirectCollision m_directCollion,float _timeEntry)
{
	if( m_directCollion == BOTTOM)
	{
		m_pos.y = _other->GetRect().top + m_Size.y + 1;
		m_velloc.y = 35.0f;
	}

	if( m_directCollion == LEFT)
	{
		m_velloc.x *= -1;
		m_accel.x = 0;
		m_pos.x = _other->GetRect().right + 1 ;
	}

	if( m_directCollion == RIGHT)
	{
		m_velloc.x *= -1;
		m_accel.x = 0;
		m_pos.x = _other->GetRect().left - m_Size.x -1;
	}

	if (m_directCollion == TOP)
	{
		m_pos.y = _other->GetRect().bottom;
		m_velloc.y = 0;
	}
}

void CBigEye::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	if (m_IsLife) {
		CEntity::Render(_spriteHandle, _camera);

	} 
}

void CBigEye::SetInjured(CEntity* _other)
{
	m_Blood --;
	if (m_Blood <= 0) {
		m_IsLife = false;
		m_IsCheckCollision = false;
	}
}
