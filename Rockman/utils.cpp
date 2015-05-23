#include "utils.h"

LPDIRECT3DSURFACE9 CUtils::LoadSurface(LPDIRECT3DDEVICE9 _d3ddv, LPCSTR filepath)
{
	LPDIRECT3DSURFACE9 surface = NULL;
	HRESULT re;
	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(filepath, &info);//lấy thông tin của ảnh
	re = _d3ddv->CreateOffscreenPlainSurface(info.Width,info.Height,D3DFMT_X8R8G8B8,D3DPOOL_DEFAULT,&surface,NULL);//khởi tạo vùng nhớ surface để lưu giữ đối tượng chuẩn bị load
	if(re != D3D_OK)
	{
		MessageBox(0, "Can not load surface from file", "Error", MB_OK); 
		return NULL;
	}
	re = D3DXLoadSurfaceFromFile(surface, NULL, NULL, filepath, NULL, D3DX_DEFAULT, 0, NULL);//load ảnh vào surface
	return surface;
}
LPDIRECT3DTEXTURE9 CUtils::LoadTexture(LPDIRECT3DDEVICE9 _d3ddv,LPCSTR filepath)
{
	HRESULT result;  
	LPDIRECT3DTEXTURE9 texture;  
	/*Tạo D3DIMAGE_INFO*/  
	D3DXIMAGE_INFO info;  
	/*Load image info từ file image.png*/  
	result = D3DXGetImageInfoFromFile(filepath,&info)  ;
	if (result!=D3D_OK) 
	{
		MessageBox(NULL, "Not specify file path ", "Error", MB_OK); 
		return NULL;  
	}
	/*Load texture resource*/  

	result = D3DXCreateTextureFromFileEx(  
		_d3ddv,         // LPDIRECT3DDEVICE9  
		filepath,                // LPCTSTR  
		info.Width,            // UINT Width  
		info.Height,            // UINT Height  
		1,                    // UINT MipLevels  
		D3DUSAGE_DYNAMIC,        // DWORD Usage  
		D3DFMT_UNKNOWN,        // D3DFORMAT Format  
		D3DPOOL_DEFAULT,        // D3DPOOL Pool  

		D3DX_DEFAULT,            // DWORD Filter  
		D3DX_DEFAULT,            // DWORD MipFilter  
		NULL,
		//D3DCOLOR_XRGB(255,255,255),    // D3DCOLOR ColorKey  
		&info,                // D3DXIMAGE_INFO *pSrcInfo  
		NULL,                // PALETTEENTRY *pPalette  
		&texture);                // LPDIRECT3DTEXTURE9 *ppTexture  

	if (result!=D3D_OK) 
	{
		return NULL;  
		MessageBox(NULL, "Can not load texture from file", "Error", MB_OK); 
	}
	return texture;
}

vector<string> CUtils::SplitString(std::string str, char ch)
{
	vector<string> result;
	int n = str.size();
	string line = "";
	for(int i = 0; i < n; i++){
		while((i<n)&&(str.at(i)!=ch))
		{
			line.push_back(str.at(i));
			i++;
		}
		result.push_back(line);
		line.clear();		
	}
	return result;
}

float CUtils::Max( float n1, float n2 )
{
	if(n1>n2) return n1;
	return n2;
}
 
 float CUtils::Min( float n1, float n2 )
 {
 	if(n1<n2) return n1;
 	return n2;
 }
  float CUtils::Lerp(float value1, float value2, float amount)
 {
	return value1 + (value2 - value1) * amount;
}