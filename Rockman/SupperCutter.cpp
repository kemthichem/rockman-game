#include "SupperCutter.h"
#include "ResourceManager.h"
#include "Rockman.h"
#include "Define.h"

#define TIME_CHANGE 8.0f

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

CSupperCutter::CSupperCutter(int objID, int typeID, double posX, double posY, int width, int height, double posXCollide, double posYCollide, int widthCollide, int heightCollide, bool _child)
{
	m_Id = objID;
	m_Type = SUPER_CUTTER;
	m_Sprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ENEMIES), D3DXVECTOR2(295, 30) , 2, 1, D3DXVECTOR2(215, 10), D3DXVECTOR2(0,0), D3DXVECTOR2(23, 0));
	m_Size = D3DXVECTOR2(m_Sprite->GetWidthRectSprite(), m_Sprite->GetHeightRectSprite());
	m_pos = D3DXVECTOR3(posX - m_Size.x/2, posY + m_Size.y/2, DEPTH_MOTION);
	m_isChild = _child;

	if (m_isChild) {
		m_velloc.y = 10.0f;
		m_accel.y = -6.0f;
	}

	//Create child
	for (int i = 0; i < 4; i++)
	{
		if (!m_isChild)
			m_childCutter[i] = new CSupperCutter(-1, -1, posX, posY, -1, -1, -1, -1, -1, -1, true);
		else
		{
			m_childCutter[i] = NULL;
		}
	}

	m_isActive = false;
	m_timeJump = TIME_CHANGE;

	m_posOrg = m_pos;

	UpdateRect();
}


CSupperCutter::~CSupperCutter(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_childCutter[i]);
		{
			delete m_childCutter[i];
			m_childCutter[i] = NULL;
		}
	}
}

void CSupperCutter::Update(float _deltaTime, CCamera *_camera, CInput *_input,vector<CEntity* > _listObjectInViewPort)
{
	D3DXVECTOR3 posRockman = CRockman::g_PosRockman;
	if (m_isChild) {
		if (m_isActive) {
			m_Sprite->Next(_deltaTime);
			CEntity::Update(_deltaTime, _camera, NULL, _listObjectInViewPort);

			if(m_Rect.left < _camera->m_viewPort.left || m_Rect.right > _camera->m_viewPort.right 
				|| m_Rect.top > _camera->m_viewPort.top || m_Rect.bottom < _camera->m_viewPort.bottom)
			{
				m_isActive = false;
				m_pos = m_posOrg;
			}
		}

	}
	else
	{
		int n = m_pos.x - posRockman.x < 0 ? 2 : 0;
		for (int i = 0; i < 4; i++)
		{
			if (i > n && i < n + 2) {
				if (m_timeJump > TIME_CHANGE) {
					if (abs(m_pos.x - posRockman.x) < 100) {
						m_childCutter[i]->SetActive(true);
						float vx = (m_pos.x - posRockman.x) < 0 ? 12.0 : -12.0;
						m_childCutter[i]->SetVelloc(D3DXVECTOR2(vx, 10));

					}
					m_timeJump = 0;
				}
				m_timeJump += _deltaTime;
				m_childCutter[i]->Update(_deltaTime, _camera, _input, _listObjectInViewPort);
			} else {
				m_childCutter[i]->Reset();
			}
		}
	}

}

void CSupperCutter::Render(LPD3DXSPRITE _spHandle, CCamera* _camera)
{
	if (m_isChild) {
		if (m_isActive) {
		CEnemy::Render(_spHandle, _camera);
		}
	} else
	{
		for (int i = 0; i < 4; i++)
		{
			m_childCutter[i]->Render(_spHandle, _camera);
		}
	}
}

void CSupperCutter::SetActive(bool inActive)
{
	m_isActive = inActive;
}

void CSupperCutter::Reset()
{
	if (!m_isChild) {
	for (int i = 0; i < 4; i++)
	{
		if (m_childCutter[i]) {
			m_childCutter[i]->Reset();
		}
	}
	}

	m_isActive = false;
	m_pos  = m_posOrg;
}

void CSupperCutter::SetVelloc(D3DXVECTOR2 _velloc)
{
	m_velloc = _velloc;
}

void CSupperCutter::UpdateCollison(CEntity* _other,float _time)
{
	if (m_isActive && m_isChild) {
		switch (_other->GetType())
		{
		case ROCKMAN:
			(dynamic_cast<CRockman*>(_other))->SetInjured(this, -6);
			Reset();
		default:
			break;
		}
	}
}


