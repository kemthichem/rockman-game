#ifndef AABBCOLLISIONDETECTED_H_
#define AABBCOLLISIONDETECTED_H_
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include<stdlib.h>
class CEntity;
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
	bool CheckCollision(RECT ,RECT);
public:
	CAABBCollision();
	~CAABBCollision();
	
	DirectCollision GetDirectCollision(){return m_directCollision;}
	float SweptAABB(CEntity* _ob1, CEntity* _ob2, float _time);
	bool IsCollision(CEntity* _ob1, CEntity* _ob2, float _time);
};

#endif


