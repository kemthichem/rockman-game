#include "SupperCutter.h"
#include "ResourceManager.h"
#include "Define.h"

CSupperCutter::CSupperCutter(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = MET;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(830, 50) , 2, 1, D3DXVECTOR2(670,20), D3DXVECTOR2(0,0), D3DXVECTOR2(40,0));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();
}

CSupperCutter::CSupperCutter(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide)
{
	m_Id = objID;
	m_Type = SUPER_CUTTER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(295, 30) , 2, 1, D3DXVECTOR2(215, 10), D3DXVECTOR2(0,0), D3DXVECTOR2(23, 0));
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);

	m_posOrg = m_pos;

	UpdateRect();
}


CSupperCutter::~CSupperCutter(void)
{
}

void CSupperCutter::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	m_Sprite->Next(_deltaTime);
}

void CSupperCutter::Draw()
{

}

