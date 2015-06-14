#include "Ladder.h"

#define  NUMB_SPRITE 10

CLadder::CLadder(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = LADDER;	
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(618,410), 1, 1, D3DXVECTOR2(586,378), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite() * NUMB_SPRITE);
	UpdateRect();
}


CLadder::~CLadder(void)
{
}

void CLadder::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	CEntity::Update(_time, _camera, _input, _listObjectInViewPort);
}

void CLadder::Render(LPD3DXSPRITE _spriteHandler, CCamera* _camera) {
	D3DXVECTOR3 posRender = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		posRender.y = m_pos.y - i * m_Sprite->GetHeightRectSprite();
		RenderEachSprite(_spriteHandler, _camera,m_Sprite, posRender);
	}
	
}

void CLadder::UpdateCollison(CEntity* _other, float _time) {
}
