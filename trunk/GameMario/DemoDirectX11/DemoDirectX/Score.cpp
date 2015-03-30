#include "Score.h"


CScore::CScore(void)
{
	WinState = false;
	numLife = 2;
	numCoin = score = 0;
	level = 1;
	time = 200;
	timeStart = GetTickCount();
}


CScore::~CScore(void)
{
}

void CScore::SetScore( CStaticObject* ob,int _score )
{
	D3DXVECTOR3 pos;
	pos.x = ob->rectagle.left- marioGame->rectScreen.left;
	pos.y = ob->rectagle.top;
	marioGame->listAnimation.push_back(new CScoreEff(pos, _score));
	score+=_score;
}

void CScore::SetNumCoin()
{
	numCoin++;
	if(numCoin>=50)
	{
		numLife++;
		SoundManager::GetInst()->PlayEffSound(SOUND_E_1UP);
		numCoin = numCoin%50;
	}
}

void CScore::SetTime(int minus)
{
	if(GetTickCount()-timeStart>1000)
	{
		timeStart = GetTickCount();
		time+=minus;
	}
	if(minus==0) 
		time = 200;
	if(time<0) time = 0;
}

void CScore::SetLife( int value )
{
	numLife +=value;
	if(value>0)
		SoundManager::GetInst()->PlayEffSound(SOUND_E_1UP);
}

void CScore::Reset( int level, int _numLife )
{
	WinState=false;
	this->level++;
	time = 200;
	//nums
}
