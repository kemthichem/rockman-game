#include "GutsMan.h"

CGutsMan::CGutsMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = GUTSMAN;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(880, 210) , 9, 1, D3DXVECTOR2(250,140), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}


CGutsMan::~CGutsMan(void)
{
}

void CGutsMan::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	m_Sprite->Next(_deltaTime);
}

void CGutsMan::Render(LPD3DXSPRITE _sp, CCamera* _cam)
{
	CEntity::RenderEachSprite(_sp, _cam, m_Sprite, m_pos);

	m_Blood->Render(_sp, _cam);
}
