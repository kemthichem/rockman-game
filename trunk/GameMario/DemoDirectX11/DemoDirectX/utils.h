#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "conio.h"
LPDIRECT3DSURFACE9 LoadSurface(LPDIRECT3DDEVICE9 _d3ddv, LPCSTR filepath);

LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 _d3ddv,LPCSTR filepath);

float Max(float n1, float n2);
float Min(float n1, float n2);
float Lerp(float value1, float value2, float amount);