#include"MenuState.h"
#include"GamestateManager.h"
#include"ChangeState.h"
#include "About.h"
#include "HelpState.h"

CMenuState::CMenuState()
{
}
CMenuState::CMenuState(CGameStateManager* _game):CGameState(_game)
{
	 m_menunewgame = NULL;
	 m_menunewgame = NULL;
	 m_menuexit = NULL;
	 m_menuoption = NULL;
	 m_menucontinue = NULL;

	this->m_StateManager = _game;
}
void CMenuState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_BG_MENU), D3DXVECTOR2(800,600), 1, 1);
	
	m_menuoption = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(380,40), 2, 1, D3DXVECTOR2(0,0));
	m_menuexit = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(200,90), 2, 1, D3DXVECTOR2(0,50));
	m_menucontinue = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(400,140), 2, 1, D3DXVECTOR2(0,100));
	m_menuabout = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(300,190), 2, 1, D3DXVECTOR2(0,150));
	m_menunewgame =  new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(420,240), 2, 1, D3DXVECTOR2(0,200));
	
	m_time = 0;
	m_Select = 1;
}
void CMenuState::CleanUp()
{
	
}
void CMenuState::Update(CInput* _input,float _time,CCamera* _camera)
{
	
	m_background->IndexOf(0);
	m_menunewgame->IndexOf(0);
	m_menucontinue->IndexOf(0);
	m_menuoption->IndexOf(0);
	m_menuabout->IndexOf(0);
	m_menuexit->IndexOf(0);
	int key = _input->GetKeyDown();
	if (key==DIK_DOWN)
	{
		m_Select++;
	}
	else if (key==DIK_UP)
	{
		m_Select--;
	}
	if (m_Select > 5)
	{
		m_Select = 1;
	}
	if (m_Select < 1)
	{
		m_Select = 5;
	}

	if (m_Select==1)
	{
		m_menunewgame->IndexOf(1);

	}
	else if (m_Select==2)
	{
		m_menucontinue->IndexOf(1);

	}
	else if (m_Select==3)
	{
		m_menuoption->IndexOf(1);

	}	
	else if (m_Select==4)
	{
		m_menuabout->IndexOf(1);

	}	
	else if (m_Select==5)
	{
		m_menuexit->IndexOf(1);

	}	
	if (key == DIK_RETURN)
	{
		switch (m_Select)
		{
		case 1:
			{
				m_StateManager->ChangeState(new CChangeState(this->m_StateManager));
				break;
			}
	/*	case 2:
			{
				m_game->ChangeState( new CContinueState(this->m_game));
				m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_MENU_ID));
				break;
			}*/
		case 3:
			{
				m_StateManager->ChangeState(new CHelpState(this->m_StateManager));
				break;
			}
		case 4:
			{
				m_StateManager->ChangeState(new CAboutState(this->m_StateManager));
				break;
			}
		case 5:
			{
				PostQuitMessage(0);
				break;
			}
		default:
			break;
		}
	}
}
void CMenuState::Render(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->Render(_spriteHandle,D3DXVECTOR3(0,0,0));
	m_menunewgame->Render(_spriteHandle,D3DXVECTOR3(400 - m_menunewgame->GetWidthRectSprite()/2,100,0));
	m_menucontinue->Render(_spriteHandle,D3DXVECTOR3(400 - m_menucontinue->GetWidthRectSprite()/2,180,0));
	m_menuoption->Render(_spriteHandle,D3DXVECTOR3(400 - m_menuoption->GetWidthRectSprite()/2,260,0));
	m_menuabout->Render(_spriteHandle,D3DXVECTOR3(400 - m_menuabout->GetWidthRectSprite()/2,340,0));
	m_menuexit->Render(_spriteHandle,D3DXVECTOR3(400 - m_menuexit->GetWidthRectSprite()/2,420,0));
}
CMenuState::~CMenuState()
{
	delete m_background;
	delete m_menunewgame;
	delete m_menuabout;
	delete m_menuexit;
	delete m_menuoption;
	delete m_menucontinue;
}