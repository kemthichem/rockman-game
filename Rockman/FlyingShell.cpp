#include "FlyingShell.h"
#include "ResourceManager.h"

CFlyingShell::CFlyingShell(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = MET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(830, 50) , 2, 1, D3DXVECTOR2(670,20), D3DXVECTOR2(0,0), D3DXVECTOR2(40,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CFlyingShell::CFlyingShell(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;

	m_Type = FLYING_SHELL;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(335, 110) , 2, 1, D3DXVECTOR2(255, 90), D3DXVECTOR2(0, 0), D3DXVECTOR2(20, 0));
	m_Size = D3DXVECTOR2(widthCollide, heightCollide);
	m_pos = D3DXVECTOR3(posXCollide, posYCollide, 0);

	UpdateRect();
}


CFlyingShell::~CFlyingShell(void)
{
}

void CFlyingShell::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	m_Sprite->Next(_deltaTime);
}

void CFlyingShell::Draw()
{

}

