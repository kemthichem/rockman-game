#include "Game.h"
#include "ResourceManager.h"

CGame::CGame(HINSTANCE hInstance)
{
	_hInstance = hInstance;
}

CGame::CGame()
{

}

void CGame::InitGame()
{
	m_time = new CTimer();
	m_time->SetMaxFps(60.0f);

	m_camera = new CCamera();

	_InitWindow();
	_InitDirectX();
	_InitInput();
	_InitFont();
	
	 m_StateManager = new CGameStateManager();
	 m_StateManager->Init(m_hWnd, m_SpriteHandler, m_GraphicText);
}

LRESULT CALLBACK CGame::_WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{ 
	switch(message) 
	{ 
	case WM_DESTROY: 
		PostQuitMessage(0); 
		break; 
	default: 
		return DefWindowProc(hWnd, message, wParam, lParam); 
	} 
	return 1;
}  
CGame::~CGame(void)
{
}
bool CGame::_InitWindow()
{
	WNDCLASS    wndc; 
	ZeroMemory(&wndc, sizeof(wndc)); 

	wndc.hbrBackground    = (HBRUSH)GetStockObject(WHITE_BRUSH); 
	wndc.hCursor        = LoadCursor(NULL, IDC_ARROW); 
	wndc.hIcon            = (HICON)LoadImage(GetModuleHandle(NULL), "mario.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE); 
	wndc.hInstance        = _hInstance; 
	wndc.lpfnWndProc    = (WNDPROC)CGame::_WinProc; 
	wndc.lpszClassName    = "CGame"; 
	wndc.lpszMenuName    = NULL; 
	wndc.style            = NULL; 

	if (!RegisterClass(&wndc)) 
	{ 
		MessageBox(0, "Can not Register Class", "Error", MB_OK); 
		return false; 
	} 

	m_hWnd    = CreateWindow( 
		"CGame", 
		"Rockman", 
		WS_OVERLAPPEDWINDOW, 
		250,//x 
		100, //y
		WIDTH_SCREEN, 
		HEIGHT_SCREEN,
		NULL, 
		NULL, 
		_hInstance, 
		NULL); 

	if (!m_hWnd) 
	{ 
		MessageBox(0, "Can not Create Window", "Error", MB_OK); 
		return false; 
	} 

	ShowWindow(m_hWnd,SW_SHOWNORMAL); 
	UpdateWindow(m_hWnd); 

	return true; 

}
bool CGame::_InitDirectX() 
{       
	_d3d    = Direct3DCreate9(D3D_SDK_VERSION); 

	if (!_d3d ) 
	{ 
		MessageBox(0, "Can not create directX 9", "Error", MB_OK); 
		return false; 
	} 

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp)); 

	d3dpp.Windowed            = true; 
	d3dpp.BackBufferCount    = 1; 
	d3dpp.BackBufferFormat    = D3DFMT_X8R8G8B8;//D3DFMT_UNKNOWN; 
	d3dpp.BackBufferHeight    = HEIGHT_SCREEN; 
	d3dpp.BackBufferWidth    = WIDTH_SCREEN; 
	d3dpp.hDeviceWindow        = m_hWnd; 
	d3dpp.SwapEffect        = D3DSWAPEFFECT_DISCARD; 

	if(FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,  D3DCREATE_HARDWARE_VERTEXPROCESSING,  &d3dpp, &_d3ddv))) 
		if(FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, m_hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &_d3ddv))) 
			if(FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, m_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &_d3ddv))) 
			{ 
				MessageBox(0, "Can not create device","Error", MB_OK); 
				return false; 
			} 

			D3DXCreateSprite(_d3ddv, &m_SpriteHandler);
			_d3ddv->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&_backbuffer);

			//set device to resource manager
			CResourceManager::GetInstance()->LoadResource(_d3ddv);

			return true; 
}
bool CGame::_InitInput()
{
	m_input = new CInput(); 
	if (!m_input->InitKeyboard(_hInstance,m_hWnd))
	{
		MessageBox(m_hWnd, "Can't create input", "Error", MB_OK );

	}
	return 0;
}

void CGame::Render()
{
	HRESULT re = _d3ddv->BeginScene();
	//if (re) 
	//{
		_d3ddv->StretchRect(CResourceManager::GetInstance()->GetSurface(IMAGE_BG), NULL,_backbuffer, NULL,D3DTEXF_NONE);
		m_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND|D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);	
		RenderWorld();		
		m_SpriteHandler->End();
		RenderTextAndSurface();
		_d3ddv->EndScene();	
	//}
	_d3ddv->Present(NULL,NULL,NULL,NULL);
}
void CGame::Release() {
	if (_d3d != NULL)
	{
		_d3d->Release();
		_d3d = NULL;
	}
	if (_d3ddv != NULL)
	{
		_d3ddv->Release();
		_d3ddv = NULL;
	}
	if (_backbuffer != NULL)
	{
		_backbuffer->Release();
		_backbuffer = NULL;
	}

	if (m_input!=NULL)
	{
		m_input->Kill_Keyboard();
		delete m_input;
	}

	if (m_StateManager) {
		delete m_StateManager;
	}

	if (m_camera) {
		delete m_camera;
		m_camera = NULL;
	}
}
int CGame::RunGame()
{
	m_time->StartCount();
	MSG msg;
	ZeroMemory(&msg,sizeof(msg));
	int done=0;
	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
			{
				done = 1;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (m_time->GetTime () < 1.0f)
			{
				m_time->EndCount();
				m_input->ProcessKeyBoard();
				UpdateWorld();
				Render();
			}

		}	
	}
	Release();
	return (int) msg.wParam;
}

void CGame::UpdateWorld()
{
}

void CGame::RenderWorld()
{

}
bool CGame::_InitFont()
{

	D3DXFONT_DESC FontDesc = {24,
		0,
		400,
		0,
		false,
		DEFAULT_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_PITCH,
		"Broadway"};

	HRESULT hre = D3DXCreateFontIndirect(_d3ddv,&FontDesc,&m_GraphicText);
	return true;
}

void CGame::RenderTextAndSurface()
{
	//_d3ddv->StretchRect(CResourceManager::GetInstance()->GetSurface(IMAGE_BG_MENU), NULL,_backbuffer, NULL,D3DTEXF_NONE);
}
