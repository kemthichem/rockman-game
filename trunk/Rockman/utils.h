#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "conio.h"

class CUtils
{
public:
	static LPDIRECT3DSURFACE9 LoadSurface(LPDIRECT3DDEVICE9 _d3ddv, LPCSTR filepath);
	static LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 _d3ddv,LPCSTR filepath);
	static float Max(float n1, float n2);
	static float Min(float n1, float n2);
	static float Lerp(float value1, float value2, float amount);
};