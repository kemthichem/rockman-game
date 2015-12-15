#ifndef AABBCOLLISIONDETECTED_H_
#define AABBCOLLISIONDETECTED_H_
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include<stdlib.h>
class CEntity;

struct RECT_F
{
	float right;
	float left;
	float bottom;
	float top;
};
enum DirectCollision
{
	NONE,
	LEFT,
	TOP,
	RIGHT,
	BOTTOM
};
class CAABBCollision
{
private:
	DirectCollision m_directCollision;
	bool CheckCollision(RECT_F ,RECT);
public:
	CAABBCollision();
	~CAABBCollision();
	
	DirectCollision GetDirectCollision(){return m_directCollision;}
	float SweptAABB(CEntity* _ob1, CEntity* _ob2, float _time);
	bool IsCollision(CEntity* _ob1, CEntity* _ob2, float _time);
	float intersectX(CEntity* a,CEntity *b,float _time);
	static bool IntersectRectX(RECT r1, RECT r2);

	static bool  SortObject(CEntity * a, CEntity*b);


	static bool compSortObjectForType(CEntity* first, CEntity* second);
	static bool compSortObjectLeft (CEntity* first, CEntity* second);
	static bool compSortObjectTop (CEntity* first, CEntity* second);
	static bool compSortObjectRight (CEntity* first, CEntity* second);
	static bool compSortObjectBottom (CEntity* first, CEntity* second);
};

#endif


