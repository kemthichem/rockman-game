#include "MapIO.h"

CMapIO::CMapIO( void )
{

}

CMapIO::CMapIO( LPCSTR fileMap )
{
	size = 50;
	this->fileMap = fileMap;
	LoadFileMap(fileMap);
}

CMapIO::~CMapIO(void)
{
	for(int i=0; i<row; i++) 
		delete[] arrMap[i]; 
	delete[] arrMap;
}

void CMapIO::LoadFileMap( LPCSTR fileMap )
{
	ifstream map (fileMap);
	if(! map.is_open())
	{
		MessageBox(NULL, "Not found file map", "Errors",NULL);
		return;
	}
	else {
		map>>row;	
		map>>column;	
		arrMap = new int*[row];
		for(int i = 0; i<row;i++)
		{
			arrMap[i] = new int[column];
		}
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				map>>arrMap[i][j];
			}
		}
		map.close();
	}
}

void CMapIO::LoadMap()
{
	for(int i=0; i<row; i++) 
	{ 
		for(int j=0; j<column; j++) 
		{
			AddObject(arrMap[i][j],j,i);
		}
	} 
}

void CMapIO::AddObject( int id,int i, int j )
{
	if(id==0) return;
	D3DXVECTOR3 pos = D3DXVECTOR3(i*50,j*50,0);
	switch (id)
	{
		#pragma region Add Enemies
	case 1:
		marioGame->listObjects.push_back(new CEnemy(pos));	
		break;
	case 2:
		marioGame->listObjects.push_back(new CTurtle(pos));	
		break;
	case 3:
		marioGame->listObjects.push_back(new CEato(pos));	
		break;
#pragma endregion Add Enemies
		#pragma region Add Items

	case 11:
		marioGame->listObjects.push_back(new CCoin(pos));	
		break;
	case 12:
		marioGame->listObjects.push_back(new CMushLife(pos));	
		break;
	case 13:
		marioGame->listObjects.push_back(new CMush(pos));	
		break;
	case 21:
		marioGame->listObjects.push_back(new CCoin(pos,1));	
		break;
	case 22:
		marioGame->listObjects.push_back(new CCoin(pos,2));	
		break;
	case 23:
		marioGame->listObjects.push_back(new CCoin1(pos));	
		break;
	case 24:
		marioGame->listObjects.push_back(new CCoin1(pos,10));	
		break;
	case 25:
		marioGame->listObjects.push_back(new CMushLife(pos,1));	
		break;
	case 26:
		marioGame->listObjects.push_back(new CMushLife(pos,2));	
		break;
	case 27:
		marioGame->listObjects.push_back(new CMush(pos,1));	
		break;
	case 28:
		marioGame->listObjects.push_back(new CMush(pos,2));	
		break;
	case 29:
		marioGame->listObjects.push_back(new CStar(pos));	
		break;
#pragma endregion Add Items
		#pragma region Add Blocks
	case -1:
		marioGame->listObjects.push_back(new CPipeHor(pos,1));	
		break;
	case -2:
		marioGame->listObjects.push_back(new CPipeHor(pos,2));	
		break;
	case -3:
		marioGame->listObjects.push_back(new CPipeVer(pos,1));	
		break;
	case -4:
		marioGame->listObjects.push_back(new CPipeVer(pos,2));	
		break;
	case -5:
		marioGame->listObjects.push_back(new CPipeVer(pos,3));	
		break;
	case -6:
		marioGame->listObjects.push_back(new CPipeVer(pos,4));	
		break;
	case -7:
		marioGame->listObjects.push_back(new CPipe1(pos,1));	
		break;
	case -8:
		marioGame->listObjects.push_back(new CPipe1(pos,2));	
		break;
	case -9:
		marioGame->listObjects.push_back(new CPipe1(pos,3));	
		break;
	case -10:
		marioGame->listObjects.push_back(new CBrick(pos));	
		break;
	case -11:
		marioGame->listObjects.push_back(new CBlock(pos,1));	
		break;
	case -12:
		marioGame->listObjects.push_back(new CBlock(pos,2));	
		break;
	case -13:
		marioGame->listObjects.push_back(new CBlock(pos,3));	
		break;
	case -14:
		marioGame->listObjects.push_back(new CBlock(pos,4));	
		break;
	case -15:
		marioGame->listObjects.push_back(new CBlock(pos,5));	
		break;
	case -20:
		marioGame->listObjects.push_back(new CLand(pos,1));	
		break;
	case -21:
		marioGame->listObjects.push_back(new CLand(pos,2));	
		break;
	case -25:
		marioGame->listObjects.push_back(new CFlag(pos));	
		break;
	case -26:
		marioGame->listObjects.push_back(new CHouse(pos));	
		break;
#pragma endregion Add Blocks
		#pragma region Add Scenery
	case -31:
		marioGame->listObjects.push_back(new CScenery(pos));	
		break;
	case -32:
		marioGame->listObjects.push_back(new CScenery(pos,1));	
		break;
	case -33:
		marioGame->listObjects.push_back(new CScenery(pos,2));	
		break;
	case -34:
		marioGame->listObjects.push_back(new CScenery(pos,3));	
		break;
	case -35:
		marioGame->listObjects.push_back(new CScenery(pos,4));	
		break;
	case -36:
		marioGame->listObjects.push_back(new CScenery(pos,5));	
		break;
	case -37:
		marioGame->listObjects.push_back(new CScenery(pos,6));	
		break;
	case -38:
		marioGame->listObjects.push_back(new CScenery(pos,7));	
		break;
	case -39:
		marioGame->listObjects.push_back(new CScenery(pos,8));	
		break;
	case -40:
		marioGame->listObjects.push_back(new CScenery(pos,9));	
		break;
	case -41:
		marioGame->listObjects.push_back(new CScenery(pos,10));	
		break;
	case -42:
		marioGame->listObjects.push_back(new CScenery(pos,11));	
		break;
	case -43:
		marioGame->listObjects.push_back(new CScenery(pos,12));	
		break;
	case -44:
		marioGame->listObjects.push_back(new CScenery(pos,13));	
		break;
#pragma endregion Add Scenery
	default:
		break;
	}
}