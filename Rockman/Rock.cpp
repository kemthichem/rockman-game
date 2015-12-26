#include "Rock.h"

#include "Define.h"
#include "ResourceManager.h"

#define  NUMB_SPRITE 4

CRock::CRock(int _id, D3DXVECTOR3 _pos, bool _isCheckCollison)
{
	m_Id = _id;
	m_Type = BLOCK;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(428,239), 2, 2, D3DXVECTOR2(394,205), D3DXVECTOR2(1,1), D3DXVECTOR2(1,1));
	m_pos = _pos;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite() * NUMB_SPRITE, m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CRock::CRock(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = BLOCK;
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, DEPTH_BLOCK);
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES), D3DXVECTOR2(428,239), 2, 2, D3DXVECTOR2(394,205), D3DXVECTOR2(1,1), D3DXVECTOR2(1,1));
	UpdateRect();
}


CRock::~CRock(void)
{
}

void CRock::Update(float _deltaTime, CCamera *_camera, CInput *_input)
{
	//m_Sprite->IndexOf(0);
}

void CRock::Render(LPD3DXSPRITE _sp, CCamera* _camera)
{
	//CEntity::Render(_sp, _camera);
	D3DXVECTOR3 pos = m_pos;
	for (int i = 0; i < NUMB_SPRITE; i++)
	{
		m_Sprite->IndexOf(i);
		pos.x = m_pos.x + (i % 2) * m_Sprite->GetWidthRectSprite() + 1;
		pos.y = m_pos.y - (i / 2) * m_Sprite->GetHeightRectSprite() - 1;
		CEntity::RenderEachSprite(_sp, _camera, m_Sprite, pos);
	}
}