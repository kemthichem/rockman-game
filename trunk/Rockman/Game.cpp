#include "Game.h"
#include "ResourceManager.h"

CGame::CGame(HINSTANCE hInstance)
{
	_hInstance = hInstance;
	deltaTime = deltaTimePress = 0;
}

CGame::CGame()
{

}

void CGame::Init()
{

	mTime = new CTimer();
	mTime->SetMaxFps(60.0f);

	mCamera = new CCamera();

	_InitWindow();
	_InitDirectX();
	_InitInput();
	_InitFont();
	//RenderTextAndSurface();
	InitGame();

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
	if (_d3ddv!=NULL) _d3ddv->Release();
	if (_d3d!=NULL) _d3d->Release();

	if( _keyboardDevice )  
	{
		_keyboardDevice->Unacquire();
		_keyboardDevice->Release();
	}

	if (_input) _input->Release();
	_backbuffer->Release();
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

	_hWnd    = CreateWindow( 
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

	if (!_hWnd) 
	{ 
		MessageBox(0, "Can not Create Window", "Error", MB_OK); 
		return false; 
	} 

	ShowWindow(_hWnd,SW_SHOWNORMAL); 
	UpdateWindow(_hWnd); 

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
	d3dpp.BackBufferHeight    = 600; 
	d3dpp.BackBufferWidth    = 800; 
	d3dpp.hDeviceWindow        = _hWnd; 
	d3dpp.SwapEffect        = D3DSWAPEFFECT_DISCARD; 

	if(FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd,  D3DCREATE_HARDWARE_VERTEXPROCESSING,  &d3dpp, &_d3ddv))) 
		if(FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, _hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &_d3ddv))) 
			if(FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, _hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &_d3ddv))) 
			{ 
				MessageBox(0, "Can not create device","Error", MB_OK); 
				return false; 
			} 

			D3DXCreateSprite(_d3ddv, &_spriteHandler);
			_d3ddv->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&_backbuffer);//chỉ thị vùng nhớ đệm để vẽ lên

			//set device to resource manager
			CResourceManager::GetInstance()->LoadResource(_d3ddv);

			return true; 
}
bool CGame::_InitInput()
{
	//	HRESULT hresult;
	//	//Khoi tao direct input
	//	hresult=DirectInput8Create(GetModuleHandle(NULL),  //HINSTANCE : hinstance ha
	//		DIRECTINPUT_VERSION,  //Direct input version
	//		IID_IDirectInput8,  //a reference identifier
	//		(void**)&_input,  //Con tro tro toi doi tuong	
	//		NULL);  //always pass NULL						
	//	if(FAILED(hresult))//Kiem tra xem Khoi tao Direct input co duoc hay khong
	//	{
	//		MessageBox(0,"Loi xay ra " ,0,0);
	//		return false;
	//	}
	//	//init keyboard
	//	hresult=_input->CreateDevice(GUID_SysKeyboard,&_keyboardDevice,NULL);
	//	if(FAILED(hresult))
	//	{
	//		return false;
	//		MessageBox(_hWnd, "Error create Input", "Error", MB_OK);
	//	}
	//
	//	//--Init KeyBoard
	//
	//	hresult=_keyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	//	if(FAILED(hresult))
	//		return false;
	//	hresult=_keyboardDevice->SetCooperativeLevel(_hWnd,DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	//	if(FAILED(hresult))
	//		return false;
	//
	//	//--
	//	DIPROPDWORD dipdw;
	//	dipdw.diph.dwSize  = sizeof(DIPROPDWORD);
	//	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	//	dipdw.diph.dwObj  = 0;
	//	dipdw.diph.dwHow  = DIPH_DEVICE;
	//	dipdw.dwData  = 256; // Arbitary buffer size
	//
	//
	//	hresult = _keyboardDevice->SetProperty( DIPROP_BUFFERSIZE, &dipdw.diph );
	//	if (hresult!=DI_OK)
	//	{
	//		MessageBox(_hWnd, "Error set Propety key board divice", "Error", MB_OK);
	//		return false;
	//	}
	//	hresult=_keyboardDevice->Acquire();
	//	if(FAILED(hresult)) return false;
	//
	//	return true;


	mInput = new CInput(); 
	if (!mInput->InitKeyboard(_hInstance,_hWnd))
	{
		MessageBox(_hWnd, "Can't create input", "Error", MB_OK );

	}
	return 0;
}
void CGame::_ProcessKeyBoard()
{
	_keyboardDevice->GetDeviceState( sizeof(keys), (LPVOID)&keys); // Fill bo dem
	//Tham so dau la size cua bo dem
	//Tham so thu hai la con tro tro toi bo dem


	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = _keyboardDevice->GetDeviceData( sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0 );
	// Scan through all data, check if the key is pressed or released
	for( DWORD i = 0; i < dwElements; i++ ) //cho phep dung stack
	{
		int KeyCode = _KeyEvents[i].dwOfs;
		int KeyState = _KeyEvents[i].dwData;
		if ( (KeyState & 0x80) > 0)
			OnKeyDown(KeyCode);// event press key
		else 
			OnKeyUp(KeyCode);//event release key`
	}
}
void CGame::_Render()
{

	HRESULT re = _d3ddv->BeginScene();
	_d3ddv->StretchRect(CResourceManager::GetInstance()->GetSurface(CResourceManager::mPathFileBg),NULL,_backbuffer, NULL,D3DTEXF_NONE);
	if (re) 
	{
		//_d3ddv->StretchRect(CResourceManager::GetInstance()->GetSurface(IMAGE_BG1), NULL,_backbuffer, NULL,D3DTEXF_NONE);
		_spriteHandler->Begin(D3DXSPRITE_ALPHABLEND|D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);	
		Render();		
		_spriteHandler->End();
		RenderTextAndSurface();
		_d3ddv->EndScene();	
	}
	_d3ddv->Present(NULL,NULL,NULL,NULL);
}
//------------------------
bool CGame::IsKeyDown(int keycode)
{
	if(keys[keycode] & 0x80)
		return true;
	return false;
}
void CGame::Release()
{
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

	if (mInput!=NULL)
	{
		mInput->Kill_Keyboard();
		delete mInput;
	}
}
int CGame::RunGame()
{
	mTime->StartCount();
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
			if (mTime->GetTime () < 1.0f)
			{
				mTime->EndCount();
				mInput->ProcessKeyBoard();
				_Update();
				_Render();
			}

		}	
	}
	//
	return (int) msg.wParam;
}
void CGame::_Process()
{
	//deltaTimePress = GetTickCount()-timePressStart;
	_ProcessKeyBoard();
	if(IsKeyDown(DIK_LEFT)||IsKeyDown(DIK_RIGHT))
		deltaTimePress = (GetTickCount()-timePressStart)/100;

	ProcessInput(deltaTimePress);	
}
void CGame::_Update()
{
	UpdateWorld(mTime->GetDeltaTime(), mCamera, mInput);
}
//------------------------
void CGame::InitGame()
{
}
void CGame::RenderTextAndSurface()
{
}
void CGame::UpdateWorld(float deltaTime, CCamera *_camera, CInput *mInput)
{
}
void CGame::Render()
{

}
void CGame::ProcessInput(float _deltaTimePress)
{
}
void CGame::OnKeyDown(int keycode)
{
}
void CGame::OnKeyUp(int keycode)
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

	HRESULT hre = D3DXCreateFontIndirect(_d3ddv,&FontDesc,&g_Font);
	return true;
}
