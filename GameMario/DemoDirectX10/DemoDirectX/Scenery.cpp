#include "Scenery.h"


CScenery::CScenery(void)
{
}

CScenery::CScenery( D3DXVECTOR3 _pos,int kind)
{
	id = -31-kind;
	pos = _pos;	
	spriteHandle = marioGame->GetSpriteHandle();
	SetKind(kind);
}

CScenery::~CScenery(void)
{
	delete sprite;
}

void CScenery::Render()
{
	
	sprite->Render(pos.x, pos.y,0,1);
}

void CScenery::Update( CQuadTreeNode* root,DWORD t )
{
		
}

void CScenery::SetKind( int kind )
{
	int wImage, hImage;
	int nWidth, nHeight;
	if(kind==0)
	{
		wImage = 300;
		hImage =150;
		nHeight = nWidth = 1;
		sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
		sprite->IndexOf(0);
	}
	else 
		if(kind==1)
		{
			wImage = 450;
			hImage =200;
			nWidth = 3;
			nHeight = 1;
			sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
			sprite->IndexOf(2);
		}
		else
			if(kind == 2)
			{
				wImage = 270;
				hImage =250;
				nWidth = 1;
				nHeight = 3;
				sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
				sprite->IndexOf(2);
			}
			else
				if(kind == 3)
				{
					wImage = 700;
					hImage =271;
					nWidth = 7;
					nHeight = 1;
					sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
					sprite->IndexOf(6);
				}
				else
					if(kind == 4)
					{
						wImage = 600;
						hImage =300;
						nWidth = 3;
						nHeight = 3;
						sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
						sprite->IndexOf(8);
					}
					else
						if(kind == 5)
						{
							wImage = 200;
							hImage =500;
							nWidth = 1;
							nHeight = 2;
							sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
							sprite->IndexOf(1);
						}
						else
							if(kind == 6)
							{
								wImage = 300;
								hImage =400;
								nWidth = 3;
								nHeight = 4;
								sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
								sprite->IndexOf(11);
							}
							else
								if(kind == 7)
								{
									wImage = 600;
									hImage =400;
									nWidth = 3;
									nHeight = 4;
									sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
									sprite->IndexOf(11);
								}
								else
									if(kind == 8)
									{
										wImage = 300;
										hImage =500;
										nWidth = 3;
										nHeight = 5;
										sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
										sprite->IndexOf(14);
									}
									else
										if(kind == 9)
										{
											wImage = 600;
											hImage =500;
											nWidth = 3;
											nHeight = 5;
											sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
											sprite->IndexOf(14);
										}
										else
											if(kind == 10)
											{
												wImage = 400;
												hImage =750;
												nWidth = 1;
												nHeight = 3;
												sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
												sprite->IndexOf(2);
											}
											else
												if(kind == 11)
												{
													wImage = 600;
													hImage =750;
													nWidth = 3;
													nHeight = 3;
													sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
													sprite->IndexOf(8);
												}
												else
													if(kind == 12)
													{
														wImage = 900;
														hImage =750;
														nWidth = 3;
														nHeight = 3;
														sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
														sprite->IndexOf(8);
													}
													else
														if(kind == 13)
														{
															wImage = 800;
															hImage =1000;
															nWidth = 1;
															nHeight = 4;
															sprite = new CSprite(marioGame->spriteScenery,wImage,hImage,nWidth,nHeight);
															sprite->IndexOf(3);
														}
	rectagle =  CusRect(pos.x, pos.y, sprite->widthOfSprite, sprite->heightOfSprite);

}
