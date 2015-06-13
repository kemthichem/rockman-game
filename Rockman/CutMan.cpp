#include "CutMan.h"

CCutMan::CCutMan(int _id, D3DXVECTOR3 _pos)
{
	m_Id = _id;
	m_Type = CUTMAN;
	m_Status = StandHaveCut;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MASTER), D3DXVECTOR2(870, 140) , 9, 2, D3DXVECTOR2(430, 10));
	m_pos = _pos;
	m_accel = D3DXVECTOR2(0,0);
	m_velloc.x = -10;
	m_accel.y = 0.0f;

	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	UpdateRect();

	//create blood
	m_Blood = new CBlood(D3DXVECTOR2(740, 30), 100);
}


CCutMan::~CCutMan(void)
{
	if (m_Blood)
		delete m_Blood;
}

void CCutMan::Update(float _time, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	//CEntity::Update(_time, _camera, _input, _listObjectInViewPort);

	if (m_pos.x < 0 || m_pos.x > 800) {
		m_velloc.x *= -1;
	}

	//if( m_pos.y <= 135){
	//	m_veloc.y = 80.0f;
	//}
	m_velloc.x = 0;
	m_velloc.y = 0;


	switch (m_Status)
	{
	case StandNormal:
		// stand normal
		m_Sprite->NextOf(_time, 16, 17);
		break;
	case MoveNormal:
		// move normal
		m_Sprite->NextOf(_time, 11, 14);
		break;
	case StandHaveCut:
		// Stand have cut
		m_Sprite->NextOf(_time, 11, 17);
		break;
	case MoveHaveCut:
		// Stand have cut
		m_Sprite->NextOf(_time, 2, 5);
		break;
	case JumpNormal:
		// Stand have cut
		m_Sprite->IndexOf(15);
		break;
	case JumpHaveCut:
		// Stand have cut
		m_Sprite->IndexOf(6);
		break;
	default:
		break;
	}	
}

void CCutMan::Render(LPD3DXSPRITE _sp, CCamera* _cam)
{
	CEntity::RenderEachSprite(_sp, _cam, m_Sprite, m_pos);

	m_Blood->Render(_sp, _cam);
}
