#include "Ladder.h"
#include "Define.h"

CLadder::CLadder(int _id, D3DXVECTOR3 _pos, int _height)
{
	m_Id = _id;
	m_Type = LADDER;	
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(618,410), 1, 1, D3DXVECTOR2(586,378), D3DXVECTOR2(0,0), D3DXVECTOR2(0,0));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;
	m_accel = D3DXVECTOR2(0,0);

	//m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite() * m_HeightLadder);
	UpdateRect();
}

CLadder::CLadder(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = LADDER;
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);
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
	
}

void CLadder::UpdateCollison(CEntity* _other, float _time) {
}
