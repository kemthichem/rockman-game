﻿#include "Sprite.h"


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
	m_SizeSprite.x = (_sizeTexture.x - _posSrc.x) / _countCol;
	m_SizeSprite.y = (_sizeTexture.y - _posSrc.y) / _countRow;

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

void CSprite::OneOf(int indexStart, int indexEnd)
{
	if (m_CurrentIndex < indexStart || m_CurrentIndex > indexEnd)
	{
		m_CurrentIndex = indexStart;
	}
}
void CSprite::NextOf(float _time, int indexStart, int indexEnd)
{
	if(m_CurrentIndex < indexStart)
		m_CurrentIndex = indexStart;
	m_TimeWait += _time;
	if(m_TimeWait >= TIME_PER_ANIMATION)  
	{		
		m_CurrentIndex++;
		if (m_CurrentIndex > indexEnd)
		{
			m_CurrentIndex = indexStart;
		}
		m_TimeWait=0;
	}
}
void CSprite::Render(LPD3DXSPRITE _spriteHandler,CCamera *_camera, D3DXVECTOR3 _pos, bool _isTurnLeft)
{
	if (_camera) {
		D3DXMATRIX matrixTransform;
		D3DXMatrixIdentity(&matrixTransform);
		D3DXMatrixTransformation2D(&matrixTransform, &D3DXVECTOR2(_pos.x, _pos.y), 0.0f, &D3DXVECTOR2(1.f, -1.f),NULL, 0.f, NULL);
		D3DXMatrixMultiply(&matrixTransform,&matrixTransform, &_camera->GetMatrixCamera());

		if (_isTurnLeft) {
			//flip sprite when move left
			D3DXMATRIX matrixFlip;
			D3DXVECTOR2 trans(2*(_pos.x - _camera->GetPosCamera().x ) + this->GetWidthRectSprite(), 0);
			D3DXMatrixTransformation2D(&matrixFlip
				,NULL//center of sprite
				,0.0f
				,new D3DXVECTOR2(-1,1)//flip Ox
				,NULL
				,0
				,&trans//distance transform
				);

			D3DXMatrixMultiply(&matrixTransform, &matrixTransform, &matrixFlip);
		}

		_spriteHandler->SetTransform(&matrixTransform);
	}

	RECT srect;
	srect.left = (m_CurrentIndex % m_CountPerRow) * (m_SizeSprite.x) + m_PosSrc.x + m_OffsetLeftTop.x;
	srect.top = (m_CurrentIndex / m_CountPerRow)*(m_SizeSprite.y) + m_PosSrc.y + m_OffsetLeftTop.y;
	srect.right = srect.left + m_SizeSprite.x - m_OffsetRightBottom.x - m_OffsetLeftTop.x;
	srect.bottom = srect.top + m_SizeSprite.y - m_OffsetRightBottom.y - m_OffsetLeftTop.y;

	_spriteHandler->Draw(
		m_Texture,
		&srect,
		NULL,
		&_pos,
		D3DCOLOR_XRGB(255,255,255)
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

void CSprite::Draw(LPD3DXSPRITE _spHandle, RECT _rectDraw, D3DX_RESIZE _styleResize)
{
	RECT rSrc;
	SIZE sSrc = { m_SizeSprite.x - m_OffsetRightBottom.x - m_OffsetLeftTop.x, m_SizeSprite.y - m_OffsetRightBottom.y - m_OffsetLeftTop.y};
	rSrc.left = (m_CurrentIndex % m_CountPerRow) * (m_SizeSprite.x) + m_PosSrc.x + m_OffsetLeftTop.x;
	rSrc.top = (m_CurrentIndex / m_CountPerRow)*(m_SizeSprite.y) + m_PosSrc.y + m_OffsetLeftTop.y;
	rSrc.right = rSrc.left + sSrc.cx;
	rSrc.bottom = rSrc.top + sSrc.cy;

	D3DXMATRIX matrixTransform;
	D3DXMatrixIdentity(&matrixTransform);
	if (_styleResize & D3DX_RESIZE_FILL) {
		
		SIZE sDst = { abs(_rectDraw.left - _rectDraw.right), abs(_rectDraw.top - _rectDraw.bottom) };
		D3DXVECTOR2 pScaling((float)sDst.cx / sSrc.cx, (float)sDst.cy / sSrc.cy);
		D3DXMatrixScaling(&matrixTransform, ceil(pScaling.x), ceil(pScaling.y), 0);
	}
	_spHandle->SetTransform(&matrixTransform);

	D3DXVECTOR3 posDraw(_rectDraw.left, _rectDraw.top, 0);
	_spHandle->Draw(
		m_Texture,
		&rSrc,
		NULL,
		&posDraw,
		D3DCOLOR_XRGB(255,255,255)
		);
}

