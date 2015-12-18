#include "Block.h"
#include "Define.h"
#include "ResourceManager.h"

#define  NUMB_SPRITE 4

CBlock::CBlock(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison)
{
	m_Id = _id;
	m_Type = BLOCK;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(140,35), 4, 1, D3DXVECTOR2(3,1), D3DXVECTOR2(1,1), D3DXVECTOR2(1,1));
	m_pos = _pos;
	m_pos.z = DEPTH_BLOCK;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * NUMB_SPRITE, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CBlock::CBlock(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = BLOCK;
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);

	UpdateRect();
}


CBlock::~CBlock(void)
{
}

void CBlock::Update(float _deltaTime, CCamera *_camera, CInput *_input)
{
	//m_Sprite->IndexOf(0);
}

void CBlock::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	//CEntity::Render(_sp, _camera);
	/*D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + i * m_Sprite->GetWidthRectSprite();
		CEntity::RenderEachSprite(_sp, _camera,m_Sprite, pos);
	}*/
}