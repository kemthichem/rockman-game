#include "SceneryTile.h"
#include "Define.h"

CSceneryTile::CSceneryTile(LPDIRECT3DTEXTURE9 _texture, int **arrayMapTitle, int _row, int _col, int _countTile)
{
	m_ArrayMapTile = arrayMapTitle;

	//calculate row and column of bitmap map
	int row, col = 0;
	int i = 0;
	while ((double)_countTile > pow((float)i, 2))
	{
		col = ++i;
		row = _countTile / col + ((_countTile % col) == 0 ? 0 : 1);
	}

	//set row and column of bitmap
	m_RowBitmap = row;
	m_ColBitmap = col;
	m_Sprite = new CSprite(_texture, D3DXVECTOR2(m_ColBitmap * SIZE_OF_TILE, m_RowBitmap * SIZE_OF_TILE), m_ColBitmap, m_RowBitmap);

	//set row and column to tile array
	m_RowArray = _row;
	m_ColArray = _col;

	m_PStart.x = 0;
	m_PStart.y = 0;
	m_PEnd.x = m_ColArray * SIZE_OF_TILE;
	m_PEnd.y = m_RowArray * SIZE_OF_TILE;

}

CSceneryTile::CSceneryTile()
{
	//set row and column of bitmap
	m_RowBitmap = 0;
	m_ColBitmap = 0;

	//set row and column to tile array
	m_RowArray = 0;
	m_ColArray = 0;

	m_PStart.x = 0;
	m_PStart.y = 0;
	m_PEnd.x = m_ColArray * SIZE_OF_TILE;
	m_PEnd.y = m_RowArray * SIZE_OF_TILE;
}


CSceneryTile::~CSceneryTile(void)
{
	//delete sprite
	if (m_Sprite) {
		delete m_Sprite;
	}

	//delete array tile
	for (int i = 0; i < m_RowArray; i++)
	{
		delete []m_ArrayMapTile[i];
	}
	delete[] m_ArrayMapTile;
}

void CSceneryTile::Render(LPD3DXSPRITE _spriteHandle, CCamera *_camera)
{
	int rowFrom = m_PEnd.y / SIZE_OF_TILE;
	rowFrom = rowFrom > m_RowArray ? 0 : rowFrom;
	int rowTo = m_PStart.y / SIZE_OF_TILE + 1;
	rowTo = rowTo > m_RowArray ? m_RowArray : rowTo;

	int colFrom = m_PStart.x / SIZE_OF_TILE;
	colFrom = colFrom > m_ColArray ? 0 : colFrom;
	int colTo = m_PEnd.x / SIZE_OF_TILE + 1;
	colTo = colTo > m_ColArray ? m_ColArray: colTo;

	for (int r = rowFrom; r < rowTo; r++)
	{
		for (int c = colFrom; c < colTo; c++)
		{
			if (-1 != m_ArrayMapTile[r][c]) {
				m_Sprite->IndexOf(m_ArrayMapTile[r][c]);

				D3DXVECTOR3 pos(c * SIZE_OF_TILE, (m_RowArray - r) * SIZE_OF_TILE, DEPTH_SCENERY);
				m_Sprite->Render(_spriteHandle, _camera, pos, false);
			}
		}
	}
}

void CSceneryTile::Update(RECT _rectToRender)
{
	m_PStart.x = _rectToRender.left;
	m_PStart.y = _rectToRender.top;
	m_PEnd.x = _rectToRender.right;
	m_PEnd.y = _rectToRender.bottom;
}
