#include "Blood.h"
#include "ResourceManager.h"
#include "Define.h"
#include "Rockman.h"

#define SIZE_OF_BLOOD (30)

CBlood::CBlood(D3DXVECTOR2 _offsetPosCamera, int _totalBlood)
{
	m_Type = SCENERY;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES)
		,D3DXVECTOR2(112, 175), 1, 1
		,D3DXVECTOR2(105, 120));

	//Blood
	m_SpriteBar = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_TILES)
		,D3DXVECTOR2(123, 122), 1, 1
		,D3DXVECTOR2(115, 120));

	m_Offset = _offsetPosCamera;
	m_CurrentBlood = m_TotalBlood = _totalBlood;
	m_CurrentPer = SIZE_OF_BLOOD;
	
}

CBlood::CBlood()
{
	
}


CBlood::~CBlood(void)
{
	if (m_SpriteBar)
		delete m_SpriteBar;
}


void CBlood::Update(float _time, CCamera *_camera, CInput *_input, vector<CEntity*> _listObjectInViewport)
{
	
}


void CBlood::Render(LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{
	m_pos = D3DXVECTOR3(CCamera::g_PosCamera.x + m_Offset.x, CCamera::g_PosCamera.y - m_Offset.y, DEPTH_MOTION);
	CEntity::Render(_spriteHandle,_camera);
	
	D3DXVECTOR3 pos = m_pos;
	pos.x = m_pos.x + 2;
	pos.y = m_pos.y - m_Sprite->GetHeightRectSprite() + 3;
	for (int i = 0; i < m_CurrentPer; i++)
	{
		CEntity::RenderEachSprite(_spriteHandle, _camera,m_SpriteBar, pos);
		pos.y += 4;		
	}	
}

void CBlood::ChangeBlood(int _num)
{
	m_CurrentBlood += _num;
	if (m_CurrentBlood > m_TotalBlood) m_CurrentBlood = m_TotalBlood;
	if (m_CurrentBlood < 0) m_CurrentBlood = 0;

	m_CurrentPer =  SIZE_OF_BLOOD * ((float)m_CurrentBlood/ m_TotalBlood);
}

bool CBlood::IsOver()
{
	return m_CurrentBlood > 0 ? false: true;
}
