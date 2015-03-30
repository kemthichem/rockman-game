#include "QuadTreeNode.h"
bool compSortObject (CStaticObject* first, CStaticObject* second){
	bool isPri = (first->rectagle.bottom>second->rectagle.bottom);
	//if(!isPri)
	//isPri = (first->rectagle.left<second->rectagle.left);
	return isPri;
}
CQuadTreeNode::CQuadTreeNode(void)
{

}
CQuadTreeNode::	CQuadTreeNode(CusRect _rect,CQuadTreeNode * root, int level)
{
	this->rect = _rect;
	this->root = root;
	this->level = level;
}
CQuadTreeNode::~CQuadTreeNode(void)
{
}
void CQuadTreeNode::CreateSubNode()
{
	if(rect.width<32||rect.height<30)
		return;
	LONG haftWidth = rect.width/2;
	LONG haftHeight = rect.height/2;

	listNode.push_back( new CQuadTreeNode(CusRect(rect.left, rect.top,haftWidth, haftHeight),this, this->level+1));
	listNode.push_back(new CQuadTreeNode(CusRect(rect.left+haftWidth, rect.top,haftWidth, haftHeight),this, this->level+1));
	listNode.push_back(new CQuadTreeNode(CusRect(rect.left, rect.top+haftHeight,haftWidth, haftHeight),this, this->level+1));
	listNode.push_back(new CQuadTreeNode(CusRect(rect.left+haftWidth, rect.top+haftHeight,haftWidth, haftHeight),this, this->level+1));
}
int CQuadTreeNode::CountObject()
{
	int count = 0;
	for(CQuadTreeNode* node : listNode)
		count+=node->CountObject();
	count += this->listObjects.size();
	return count;
}
void CQuadTreeNode::AddObject( CStaticObject *object )
{
	object->checked = false;
	if(!rect.Contains(object->rectagle))
		return;
	if(CountObject()==0&&listNode.size()==0)
		CreateSubNode();

	for (CQuadTreeNode* node :listNode)
	{

		if(node->rect.Contains(object->rectagle))
		{
			node->AddObject(object);
			return;
		}
	}
	this->listObjects.push_back(object);
}
void CQuadTreeNode::AddListObject( list<CStaticObject *> _listObject )
{
	for (CStaticObject* ob:_listObject)
	{
		this->AddObject(ob);
	}
}
list<CStaticObject*> CQuadTreeNode::ListObjectInRect( CusRect _rect, bool updated )
{
	list<CStaticObject*> resuft;// = new list<CStaticObject*>();
	for(CStaticObject* object : listObjects)
	{
		if(_rect.IntersectWith(object->rectagle))//add các object thuoc node đang xét intersect vs srect
		{
			resuft.push_back(object);
		}
	}
	///
	for(CQuadTreeNode* node: listNode)
	{
		if(node->listNode.size()==0)
			continue;
		if(node->rect.Contains(_rect))//case 1: if bounds of node contains screct, đệ quy vào bên trong, thoát khỏi vòng lặp
		{
			{
				list<CStaticObject*> tempList =node->ListObjectInRect(_rect);
				resuft.insert(resuft.end(), tempList.begin(), tempList.end());
			}
			//resuft.merge(node->ListObjectInScreen(_rect));
			break;
		}
		if(_rect.Contains(node->rect))//case 2: nếu screct chứa bounds của node đang xét, thêm tất cả các đối tượng thuộc node đó vào result, continute
		{
			{
				list<CStaticObject*> tempList =node->SubTreeObject(updated);
				resuft.insert(resuft.end(), tempList.begin(), tempList.end());
			}
			//resuft.merge(node->SubTreeObject());
			//node->SubTreeObject();
			continue;
		}
		if(_rect.IntersectWith(node->rect))//case 3: lúc này 2 trường hợp trên đã ko xảy ra, đệ quy
		{
			list<CStaticObject*> tempList =node->ListObjectInRect(_rect);
			resuft.insert(resuft.end(), tempList.begin(), tempList.end());
		}

	}
	return resuft;
};
list<CStaticObject*> CQuadTreeNode::SubTreeObject(bool updated)
{
	list<CStaticObject*> resuft;
	for(CQuadTreeNode* node : listNode)
	{
		list<CStaticObject*> tempList =node->SubTreeObject();
		resuft.insert(resuft.end(), tempList.begin(), tempList.end());
	}
	resuft.insert(resuft.end(), listObjects.begin(), listObjects.end());
	if(updated)
	{
		list<CStaticObject*>::iterator it = listObjects.begin();
		while (it!=listObjects.end())
		{
			(*it)->checked = true;
			it++;
		}
	}
	return resuft;
}
bool CQuadTreeNode::Check( CusRect rectOld, CusRect _rect)
{

	//list<CStaticObject*> listInScreen = marioGame->listObjectInScreen;
	//for(CStaticObject * object : listInScreen)
	//{
	//	if(object->rectagle.Equals(rectOld))
	//		continue;
	//	if(object->rectagle.IntersectWith(_rect))
	//		return true;
	//}
	return false;
}
void CQuadTreeNode::DeleteObject( CusRect _rect )
{

	list<CStaticObject*>::iterator it= listObjects.begin();
	int n = listObjects.size();
	for (int i = 0; i < n; i++)
	{
		if((*it)->id >=0||(*it)->id ==-10)//chi xet cac doi tuong montion va chua duoc update.
		{
			if((*it)->checked||!(*it)->life)//neu qua update ma bi thay doi, se xoa doi tuong do
			{
				it = listObjects.erase(it);
			}
			else//nguoc lai neu ko thay doi se duoc giu lai
				++it;
		}
		else
		{
			++it;
		}
	}
	//--đệ quy
	if(!listNode.empty())
	{
		for(CQuadTreeNode* node: listNode)
		{
			if(node->rect.Contains(_rect))
			{
				node->DeleteObject(_rect);
				return;
			}
			if(node->rect.IntersectWith(_rect))
			{
				CusRect r = node->rect.IntersectRect(_rect);
				node->DeleteObject(r);
			}

		}
	}
}
void CQuadTreeNode::Update( CusRect _rect, DWORD deltaTime )
{
	list<CStaticObject*>::iterator it= listObjects.begin();
	int n = listObjects.size();
		for (int i = 0; i < n; i++)
		{
			if((*it)->id >=0||(*it)->id ==-10)//&&(*it)->id !=0)// && !(*it)->checked)//chi xet cac doi tuong montion va chua duoc update.
			{
				//if((*it)->id!=0)//mario đã được update phía trên rồi, ko update nữa
				(*it)->Update(marioGame->quadTree->root, deltaTime);
			}
				++it;
		}

					//---đệ quy
		if(!listNode.empty())
		{
			for(CQuadTreeNode* node: listNode)
			{
				if(node->rect.Contains(_rect))
				{
					node->Update(_rect,deltaTime);
					return;
				}
				if(node->rect.IntersectWith(_rect))
				{
					CusRect r = node->rect.IntersectRect(_rect);
					node->Update(r, deltaTime);
				}

			}
		}
		///----------
	}