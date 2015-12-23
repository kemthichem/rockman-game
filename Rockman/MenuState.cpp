#include"MenuState.h"
#include"GamestateManager.h"
#include"PLayingGameState.h"
#include "ChangeState.h"
#include "ResourceManager.h"
#include "Define.h"

CMenuState::CMenuState()
{
}
CMenuState::CMenuState(CGameStateManager* _game):CGameState(_game)
{
	 m_spriteSelect = m_spriteItem = NULL;

	this->m_StateManager = _game;
}
void CMenuState::Init()
{
	CGameState::Init();
	m_background = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(16,93), 1, 1, D3DXVECTOR2(0,77));
	m_spriteSelect = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(90,45), 2, 1);
	m_spriteItem = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_MENU), D3DXVECTOR2(192,77), 6, 1, D3DXVECTOR2(0,45));
	m_background->IndexOf(0);


	m_time = 0;
	m_indexSelect = 0;

	//init rect item
	RECT rItem1 = {100, 20, 100 + m_spriteItem->GetWidthRectSprite(), 20 + m_spriteItem->GetHeightRectSprite()};
	arrayRectItem[0] = rItem1;

	RECT rItem2 = { 180, 20, 180 + m_spriteItem->GetWidthRectSprite(), 20 + m_spriteItem->GetHeightRectSprite()};
	arrayRectItem[1] = rItem2;

	RECT rItem3 = {190,100, 190 + m_spriteItem->GetWidthRectSprite(), 100 + m_spriteItem->GetHeightRectSprite()};
	arrayRectItem[2] = rItem3;

	RECT rItem4 = {0,200, 100 + m_spriteItem->GetWidthRectSprite(), 200 + m_spriteItem->GetHeightRectSprite()};
	arrayRectItem[3] = rItem4;

	RECT rItem5 = {0,200, 100 + m_spriteItem->GetWidthRectSprite(), 200 + m_spriteItem->GetHeightRectSprite()};
	arrayRectItem[4] = rItem5;

	RECT rItem6 = {0,200, 100 + m_spriteItem->GetWidthRectSprite(), 200 + m_spriteItem->GetHeightRectSprite()};
	arrayRectItem[5] = rItem6;
}
void CMenuState::CleanUp()
{
	
}
void CMenuState::Update(CInput* _input,float _time)
{
	
	m_spriteSelect->Next(_time);


	int key = _input->GetKeyDown();
	if (key==DIK_DOWN || key==DIK_RIGHT)
	{
		m_indexSelect = (++m_indexSelect % COUNT_ITEM);
	}
	else if (key==DIK_UP || key==DIK_LEFT)
	{
		if (--m_indexSelect < 0) m_indexSelect = COUNT_ITEM - 1;
		m_indexSelect = (m_indexSelect % COUNT_ITEM);
	}
	else if (key == DIK_ESCAPE) {
		m_StateManager->ChangeState(new CChangeState(m_StateManager));
	}	
	if (key == DIK_RETURN)
	{
		CPLayingGameState::g_Stage = m_indexSelect + 1;
		m_StateManager->ChangeState(new CPLayingGameState(m_StateManager));
	}
}
void CMenuState::Render(LPD3DXSPRITE _spriteHandle)
{
	int currentIndex = m_spriteSelect->m_CurrentIndex;

	RECT rScreen = { 0, 0, WIDTH_SCREEN, HEIGHT_SCREEN };
	m_background->Draw(_spriteHandle, rScreen, D3DX_RESIZE_FILL);

	//Draw menu item
	for (int i = 0; i < COUNT_ITEM; i++)
	{
		m_spriteItem->IndexOf(i);
		RECT rItem = arrayRectItem[i];
		m_spriteItem->Draw(_spriteHandle, rItem, D3DX_RESIZE_NONE);

		RECT rSelect = { 
			rItem.left - 6,
			rItem.top - 6,
			rItem.right + 6,
			rItem.bottom + 6
		};
		m_spriteSelect->IndexOf(0);
		m_spriteSelect->Draw(_spriteHandle, rSelect, D3DX_RESIZE_FILL);
	}

	//Draw select
	RECT rItemSelect = arrayRectItem[m_indexSelect];
	RECT rSelect = { 
		rItemSelect.left - 6,
		rItemSelect.top - 6,
		rItemSelect.right + 6,
		rItemSelect.bottom + 6
	};
	//m_spriteItem->IndexOf(currentIndex);
	static int tempIndex = 0;
	tempIndex = (++tempIndex%2);
	m_spriteSelect->IndexOf(currentIndex);
	m_spriteSelect->Draw(_spriteHandle, rSelect, D3DX_RESIZE_FILL);

}
CMenuState::~CMenuState()
{
	delete m_background;
	delete m_spriteSelect;
	delete m_spriteItem;
}