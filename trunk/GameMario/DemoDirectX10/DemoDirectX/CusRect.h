#pragma  once
#include <d3d9.h>
#include <d3dx9.h>
#define HRZT  1;
#define VRTC  2;
#define vTOP 3;
#define vBOTTOM 4;
class CusRect
{
private:
	RECT rect;
	void Init();
public:
	LONG top, left, bottom, right;
	LONG  width, height;
	D3DXVECTOR3 PosMidle();
	CusRect();
	CusRect(RECT _rect);
	CusRect(LONG _left, LONG _top, LONG _width, LONG _height);
	CusRect(CusRect oldRect, float vx, float vy);
	bool Contains(CusRect rectangle);
	bool Equals(CusRect _rect);
	void UpdateRect(LONG x, LONG y);
	void UpdateRect(LONG x, LONG y,LONG width, LONG height);
	CusRect IntersectRect(CusRect _rect);
    CusRect OverRect(CusRect _rect);
	~CusRect();
	bool CusRect::IntersectWith( CusRect _rect );
	bool IsIntersectHorizotal(CusRect oldRect, float vx, float vy);
	bool IsIntersectVertical(CusRect oldRect, float vx, float vy);
	bool IsIntersectTop(CusRect oldRect, float vx, float vy);
	bool IsIntersectBottom(CusRect oldRect,  float vx, float vy);
	int InterSect(CusRect oldRect, float vx, float vy);
};

