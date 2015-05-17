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
public:
	CAABBCollision();
	~CAABBCollision();
	bool CheckCollision(RECT ,RECT);
	float CheckAABBCollision(CEntity*,CEntity*,float);
	DirectCollision GetDirectCollision(){return m_directCollision;}
	void SetDirectCollsion(DirectCollision Direct){m_directCollision = Direct; }
	static bool SortObject(CEntity* a,CEntity* b);
	float intersectX(CEntity* ,CEntity*,float);
	RECT CLip(CEntity*,CEntity*);

	float SweptAABB(CEntity* _ob1, CEntity* _ob2, float _time);
	bool IsCollision(CEntity* _ob1, CEntity* _ob2, float _time);
};

#endif


