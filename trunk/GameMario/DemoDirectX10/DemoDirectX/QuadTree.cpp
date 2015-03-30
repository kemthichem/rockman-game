#include "QuadTree.h"


CQuadTree::CQuadTree(void)
{
	RECT  _rect;
	_rect.top = 0;
	_rect.left = 0;
	_rect.right = 6400;
	_rect.bottom = 1600;
	rectangle = CusRect(_rect);
	root = new CQuadTreeNode(rectangle,0);

}

CQuadTree::CQuadTree( LONG widht, LONG height )
{
	RECT r;
	r.top = 0;
	r.left = 0;
	r.bottom = height;
	r.right = widht;
	rectangle = CusRect(r);
	root = new CQuadTreeNode(rectangle);
}


CQuadTree::~CQuadTree(void)
{
}

void CQuadTree::AddObject( CStaticObject *object )
{

	root->AddObject(object);

}

list<CStaticObject*> CQuadTree::ListObjectInRect( CusRect screenRect )
{
	return root->ListObjectInRect(screenRect,false);
}

void CQuadTree::DeleteObject( CStaticObject* object )
{
	//root->DeleteObject(object );
}

void CQuadTree::Render()
{
	list<CStaticObject*> list1 = marioGame->listObjectInScreen;
	list<CStaticObject*> list2 = marioGame->listAnimation;
	for (CStaticObject* ob:list1)
	{
		if(ob->id==23)
			int k = 0;
		ob->Render();
	}
	for (CStaticObject* ob:list2)
	{
		ob->Render();
	}
}

void CQuadTree::Update( DWORD deltaTime )
{
	//marioGame->mario->Update1(marioGame->quadTree->root,deltaTime);//tách riêng mario ra update trước, dùng hàm update 1 riêng
	root->Update(marioGame->rectScreen,deltaTime);
	root->DeleteObject(marioGame->rectScreen);
}

void CQuadTree::AddListObject( list<CStaticObject*> _listObject )
{
	root->AddListObject(_listObject);
}

LONG CQuadTree::GetHeight()
{
	return this->rectangle.height;
}

LONG CQuadTree::GetWidth()
{
	return this->rectangle.width;
}
