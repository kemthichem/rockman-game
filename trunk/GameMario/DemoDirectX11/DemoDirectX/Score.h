#include "MarioGame.h"
#ifndef _SCORE_H
#define _SCORE_H
class CScore
{
private:
	LONG score;

	DWORD timeStart;
	int numLife;
	int time;	
	int numCoin;
	int level;

public:	
	LONG Score() const { return score; }
	void Score(LONG val) { score = val; }
	bool WinState;
	int NumLife() const { return numLife; }
	void NumLife(int val) { numLife = val; }

	int NumCoin() const { return numCoin; }
	void NumCoin(int val) { numCoin = val; }

	int Level() const { return level; }
	void Level(int val) { level = val; }

	int Time() const { return time; }
	void Time(int val) { time = val; }
	CScore(void);
	void SetScore(CStaticObject* ob,int _score);
	void SetNumCoin();
	void SetLife(int value);
	void SetTime(int minus);
	void Reset(int level, int _numLife);
	~CScore(void);
};
#endif // _SCORE_H

