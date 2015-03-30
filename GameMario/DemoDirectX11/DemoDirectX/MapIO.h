#include "MarioGame.h"
#include <fstream>
#ifndef	_MAPIO_H
#define  _MAPIO_H
class CMapIO
{
private:
	int row,column;
	 int size ;	
	LPCSTR fileMap;
	int** arrMap;
	void AddObject(int id,int i, int j);
	int  Time, Score, Coin,Life,Level;
	string FilePathBackround;

public:
	//----------
	LONG GetWidht(){return column*size;}
	LONG GetHeight(){return row *size;}
	CMapIO(void);
	CMapIO(LPCSTR fileMap);
	~CMapIO(void);
	void SetFileMap(LPCSTR val) { fileMap = val; }
	void LoadFileMap(LPCSTR fileMap);
	void LoadMap();
	void ReLoadMap(int posX);
	static bool SaveMap(list<CStaticObject* > listOb, string filePath);
	static string NextMap(string map);

	//------
	

};
#endif