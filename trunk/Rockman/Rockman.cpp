#include "Rockman.h"

D3DXVECTOR2 CRockman::posInMap;
CRockman::CRockman(void)
{

}
CRockman::CRockman(D3DXVECTOR3 _pos)
{
	mSprite = new CSprite(CResourceManager::GetInstance()->GetSprite(IMAGE_ROCKMAN), 960, 320, 12, 4);
	mPos = _pos;
}
CRockman::~CRockman()
{

}

void CRockman::Update(DWORD deltaTime, CCamera *_camera, CInput *_input){
	CEntity::Update(deltaTime, _camera, _input);


	if (_input->KeyDown(DIK_RIGHT)) {
		mVeloc.x = 10;
	} else if(_input->KeyDown(DIK_LEFT)) {
		mVeloc.x = -10;
	} else {
		mVeloc.x = 0;
	}

	mPos.x += mVeloc.x;

	//Update sprite
	if (mVeloc.x == 0) {
		mSprite->NextOf(12,15);
	} else {
		mSprite->NextOf(24,28);
	}
}
