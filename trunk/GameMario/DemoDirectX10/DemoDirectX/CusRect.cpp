#include "CusRect.h"

CusRect::CusRect()
{
	rect.top = 0;
	rect.left = 0;
	rect.right = 32;
	rect.bottom = 30;
	Init();
}

CusRect::CusRect( RECT _rect )
{
	rect = _rect;
	Init();
}

CusRect::CusRect(LONG _left, LONG _top, LONG _width, LONG _height)
{
	rect.top = _top;
	rect.left = _left;
	rect.right = _left+_width;
	rect.bottom = _top+_height;
	//--
	Init();
}

CusRect::CusRect( CusRect oldRect, float vx, float vy )
{
	//CusRect(oldRect.left+ vx, oldRect.top +vy, oldRect.width, oldRect.height);
	rect.top =oldRect.top +(LONG)vy;
	rect.left = oldRect.left+ vx;
	rect.right = rect.left+oldRect.width;
	rect.bottom = rect.top+ oldRect.height;
	Init();
}

CusRect::~CusRect()
{
}

bool CusRect::Contains( CusRect rectangle )
{
	if(rect.top>rectangle.top|| rect.left>rectangle.left|| rect.right<rectangle.right|| rect.bottom<rectangle.bottom)
		return false;
	return true;
}
CusRect CusRect::OverRect(CusRect _rect )
{
	RECT r; 
	r.left = this->left<_rect.left? this->left:_rect.left;
	r.top =  this->top<_rect.top? this->top:_rect.top;
	r.right =  this->right>_rect.right? this->right:_rect.right;
	r.bottom =  this->bottom>_rect.bottom? this->bottom:_rect.bottom;
	CusRect resuft = CusRect(r);
	return resuft;
}
void CusRect::Init()
{
	top = rect.top;
	left = rect.left;
	right = rect.right;
	bottom = rect.bottom;
	width = right - left;
	height = bottom - top;
}

bool CusRect::IntersectWith( CusRect _rect )
{
	if(rect.top> _rect.bottom|| rect.bottom<_rect.top|| rect.left> _rect.right|| rect.right< _rect.left)
		return false;
	return true;
}

CusRect CusRect::IntersectRect( CusRect _rect )
{
	CusRect r = CusRect();
	r.top = (rect.top>_rect.top)? rect.top:_rect.top;
	r.bottom = (rect.bottom<_rect.bottom)? rect.bottom:_rect.bottom;
	r.left = (rect.left>_rect.left)? rect.left:_rect.left;
	r.right = (rect.right<_rect.right)? rect.right:_rect.right;
	return r;
}

void CusRect::UpdateRect( LONG x, LONG y )
{
	//CusRect(x, y, width, height);
	rect.top = y; 
	rect.bottom = y+height;
	rect.left = x;
	rect.right = x+width;
	Init();
}

void CusRect::UpdateRect( LONG x, LONG y,LONG _width, LONG _height)
{
	rect.top = y; 
	rect.bottom = y+_height;
	rect.left = x;
	rect.right = x+_width;
	Init();
}

bool CusRect::Equals( CusRect _rect )
{
	if(rect.top==_rect.top && rect.bottom==_rect.bottom && 
		rect.right==_rect.right&&rect.left==_rect.left)
		return true;
	return false;
}

D3DXVECTOR3 CusRect::PosMidle()
{
	return D3DXVECTOR3( float(left+ width/2),top+ float(height/2),0);
}

bool CusRect::IsIntersectHorizotal( CusRect oldRect,float vx, float vy )
{
	if(InterSect(oldRect, vx, vy) == 1)
		return true;
	return false;
}

bool CusRect::IsIntersectVertical( CusRect oldRect, float vx, float vy  )
{
	if(InterSect(oldRect, vx, vy) == 2)
		return true;
	return false;
}

bool CusRect::IsIntersectTop( CusRect oldRect, float vx, float vy )
{
	if(InterSect(oldRect, vx, vy) == 1)
	return false;
	if(vy>0)
		return false;
	if(vy<0)
		return true;
}

bool CusRect::IsIntersectBottom( CusRect oldRect, float vx, float vy)
{

	if(InterSect(oldRect, vx, vy) == 1)
		return false;
	if(vy>0)
		return false;
	if(vy<0)
		return true;
}

int CusRect::InterSect( CusRect oldRect, float vx, float vy )
{
	float x0,y0,x1, y1;
	float X,Y;
	if(vx!=0&&vy!=0)//--nếu vx khác 0 mới xét va chạm theo phương ngang
	{
	float dirX =1;float dirY = 1;
	float interX, interY;
	if(vx<0){x0 = oldRect.left;X = this->right;}
	else if(vx>0){x0 = oldRect.right;X = this->left;dirX = -1;}

	if(vy<0){y0 = oldRect.top; Y = this->bottom;}
	else if(vy>0){y0 = oldRect.bottom; Y = this->top;dirY = -1;}

	x1 = x0+ vx;
	y1 = y0 +vy;

	interY = (vy/vx)* (X-x0) + y0;
	interX = (vx/vy)* (Y-y0) + x0;
	///----xét giao điểm`

	if (this->top< interY && interY<= this->bottom&& vy*y0<=vy*interY&& vy*Y<=vy*y1 ) {return HRZT;}
	else
	{
		float temp = (dirY/2)*oldRect.height;
		interY += temp;
		y0 += temp;
		y1 += temp;
		if(this->top< interY && interY<= this->bottom&& vy*y0<=vy*interY&& vy*Y<=vy*y1){return HRZT;}
		else
		{
			temp = (dirY/2)*oldRect.height;
			interY += temp;
			y0 += temp;
			y1 += temp;
			if(this->top<= interY && interY<= this->bottom&& vy*y0<=vy*interY&& vy*interY<=vy*y1)
			{return HRZT;}
			else
			{
				temp = (-dirY*3/4)*oldRect.height;
				interY += temp;
				y0 += temp;
				y1 += temp;
				if(this->top<= interY && interY<= this->bottom&& vy*y0<=vy*interY&& vy*interY<=vy*y1)
				{return HRZT;}
				else
				{
					temp = (dirY/2)*oldRect.height;
					interY += temp;
					y0 += temp;
					y1 += temp;
					if(this->top<= interY && interY<= this->bottom&& vy*y0<=vy*interY&& vy*interY<=vy*y1)
					{return HRZT;}

				}

			}

		}

	}
	if (this->left< interX && interX< this->right&& vx*x0 <=vx*interX && vx*interX<=vx*x1) {return VRTC;}
	else
	{
		float temp =  (dirX/2)*oldRect.width;
		interX += temp;
		x0 += temp;
		x1 += temp;
		if (this->left< interX && interX< this->right&&vx*x0 <=vx*interX && vx*interX<=vx*x1) {return VRTC;}
		else{
			float temp =  (dirX/2)*oldRect.width;
			interX += temp;
			x0 += temp;
			x1 += temp;
			if (this->left< interX && interX< this->right&&vx*x0 <=vx*interX && vx*interX<=vx*x1) {return VRTC;}
		}
	}
	}
	else
		if(vx==0&&vy==0)
			return 0;
	else
	if(vx ==0)
	{
		if(oldRect.left>this->right||oldRect.right<this->left)//trường hợp nằm ngoài
			return 0;
		if(vy <0)
		{
			y1 = oldRect.bottom;
			y0 = y1+vy- oldRect.height;		
		}
		else if(vy>0)
		{
			y0 = oldRect.top;
			y1 = y0+vy+ oldRect.height;
		}
		if((y0<=this->top&&this->top<=y1)||(y0<=this->bottom&&this->bottom<=y1)||this->top<y0&&y0<this->bottom)
			return VRTC;
	}
	else
		if(vy ==0)
		{
			if(oldRect.bottom<this->top||oldRect.top>this->bottom)
				return 0;
			if(vx <0)
			{
				x1 = oldRect.right;
				x0 = x1+vx- oldRect.width;		
			}
			else if(vx>0)
			{
				x0 = oldRect.left;
				x1 = x0+vx+ oldRect.width;
			}
			if((x0<=this->left&&this->left<=x1)||(x0<=this->right&&this->right<=x1))
				return HRZT;
		}

	return 0;
}


