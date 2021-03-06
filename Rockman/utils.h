﻿#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "conio.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class CUtils
{
public:
	const static char charSplit = '\t';
	static LPDIRECT3DSURFACE9 LoadSurface(LPDIRECT3DDEVICE9 _d3ddv, LPCSTR filepath);
	static LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 _d3ddv,LPCSTR filepath, COLORREF _colorFilter = D3DCOLOR_XRGB(0,102,102));
	static float Max(float n1, float n2);
	static float Min(float n1, float n2);
	static float Lerp(float value1, float value2, float amount);
	static vector<string> SplitString(std::string str, char ch);
	static vector<string> LoadDataFromFile(const char *pathMap);

};