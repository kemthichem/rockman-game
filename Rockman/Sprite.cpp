#include "Sprite.h"

#define  TIME_PER_ANIMATION (3.0f)


CSprite::CSprite(void)
{
}
CSprite::CSprite(LPDIRECT3DTEXTURE9 _texture, D3DXVECTOR2 _sizeTexture, int _countCol, int _countRow,
				 D3DXVECTOR2 _posSrc,
				 D3DXVECTOR2 _offsetLeftTop,
				 D3DXVECTOR2 _offsetRightBottom )
{
	m_Texture = _texture;
	m_CountSprite = _countRow * _countCol;
	m_CountPerRow = _countCol;
	m_PosSrc = _posSrc;
	m_SizeSprite.x = (_sizeTexture.x - _posSrc.x)/ _countCol;
	m_SizeSprite.y = (_sizeTexture.y - _posSrc.y)/_countRow;

	m_OffsetLeftTop = _offsetLeftTop;
	m_OffsetRightBottom = _offsetRightBottom;

	m_CurrentIndex = 0;
	m_TimeWait = 0;
}
void CSprite::Next(float _time)
{
	m_TimeWait += _time;
	if(m_TimeWait >= TIME_PER_ANIMATION)  //Chờ đến khi quá thời gian quy định thì chuyển frame kế tiếp
	{
		//	index = (index + count-1)% count;
		m_CurrentIndex = (m_CurrentIndex +1) % m_CountSprite;
		m_TimeWait = 0;
	}
}
void CSprite::IndexOf(int _index)
{
	m_CurrentIndex = _index;
}
void CSprite::NextOf(float _time, int indexStart, int indexEnd)
{
	if(m_CurrentIndex<indexStart)
		m_CurrentIndex = indexStart;
	m_TimeWait += _time;
	if(m_TimeWait >= TIME_PER_ANIMATION)  
	{		
		m_CurrentIndex++;
		if (m_CurrentIndex>indexEnd)
		{
			m_CurrentIndex = indexStart;
		}
		m_TimeWait=0;
	}
}
void CSprite::Render(LPD3DXSPRITE _spriteHandler, D3DXVECTOR3 _pos, int _dir)
{
	RECT srect;
	srect.left = (m_CurrentIndex % m_CountPerRow)*(m_SizeSprite.x) + m_PosSrc.x + m_OffsetLeftTop.x;
	srect.top = (m_CurrentIndex / m_CountPerRow)*(m_SizeSprite.y) + m_PosSrc.y + m_OffsetLeftTop.y;
	srect.right = srect.left + m_SizeSprite.x - m_OffsetRightBottom.x - m_OffsetLeftTop.x;
	srect.bottom = srect.top + m_SizeSprite.y - m_OffsetRightBottom.y - m_OffsetLeftTop.y;

	_spriteHandler->Draw(
		m_Texture,
		&srect,
		NULL,
		&_pos,
		D3DCOLOR_XRGB(0,255,255)
		);
}

void CSprite::NextAt(float _time, int index1, int index2)
{
	if(index1 == index2)
	{
		m_CurrentIndex = index1;
		return;
	}
	else if(m_CurrentIndex < index1)
		m_CurrentIndex = index1;
	m_TimeWait += _time;
	if(m_TimeWait >= TIME_PER_ANIMATION)  //Chờ đến khi quá thời gian quy định thì chuyển framekế tiếp
	{
		if(m_CurrentIndex == index1)
			m_CurrentIndex = index2;
		else
			m_CurrentIndex = index1;
		m_TimeWait = 0;
	}
}
CSprite::~CSprite(void)
{
}

int CSprite::GetHeightRectSprite()
{
	return m_SizeSprite.y - m_OffsetRightBottom.y - m_OffsetLeftTop.y;
}

int CSprite::GetWidthRectSprite()
{
	return m_SizeSprite.x - m_OffsetRightBottom.x - m_OffsetLeftTop.x;
}

