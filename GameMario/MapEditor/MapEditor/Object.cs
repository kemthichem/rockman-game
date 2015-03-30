using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace MapEditor
{
    class ObjectGame
    {
        private Image image;
        private int id;
        private Point pos;
        public Point Pos
        {
            get { return pos; }
        }
        public int Id
        {
            get { return id; }
        }
        private int width, height;
        //-----------
        public ObjectGame(Point p, int _id)
        {
            id = _id;
            pos.X = 50 * (p.X / 50);
            pos.Y = 50 * (p.Y / 50);
            SetKind(_id);
        }
        public void Draw(Graphics g)
        {
            if(image!=null)
            g.DrawImage(image, new Rectangle(pos, new Size(width, height)));
        }
        public static int GetIdFromText(String text)
        {
            int re = -10;
            text = text.Trim();
            text = text.Split('(')[1];
            text = text.Split(')')[0];
            try { re = Convert.ToInt32(text); }
            catch { }
            return re;
        }
        private void SetKind(int kind)
        {
            switch (kind)
            {
                #region enemies

                case 2:
                     width = 50; height = 50;
                    image = Form1.enemy;                  
                    break;
                case 1:
                    width = 50; height = 70;
                    image = Form1.turtle;
                    break;
                case 3:
                    width = 50; height = 50;
                    image = Form1.eato;
                    break;
                #endregion
                #region Items

                case 11:
                    width = 50; height = 50;
                    image = Form1.coin;   
                    break;
                case 12:
                    width = 50; height = 50;
                    image = Form1.mushlife;
                    break;
                case 13:
                    width = 50; height = 50;
                    image = Form1.mush;
                    break;
                case 21:
                     width = 50; height = 50;
                    image = Form1.coin1;
                    break;
                case 22:                    
                     width = 50; height = 50;
                    image = Form1.coin1;
                    break;
                case 23:                    
                     width = 50; height = 50;
                    image = Form1.coin1c;
                    break;
                case 24:                
                     width = 50; height = 50;
                    image = Form1.coin10c;
                    break;
                case 25:
                    width = 50; height = 50;
                    image = Form1.mushlife1;
                    break;
                case 26:
                    width = 50; height = 50;
                    image = Form1.mushlife2;
                    break;
                case 27:
                    width = 50; height = 50;
                    image = Form1.mush1;
                    break;
                case 28:
                    width = 50; height = 50;
                    image = Form1.mush2;
                    break;
                case 29:
                    width = 50; height = 50;
                    image = Form1.star;
                    break;
                #endregion
                #region Blocks

                case -1:
                    width = 200; height = 100;
                    image = Form1.pipeHor;
                    break;
                case -2:
                    width = 2000; height = 100;
                    image = Form1.pipeHor;
                    break;
                case -3:
                    width = 100; height = 200;
                    image = Form1.pipeVer;
                    break;
                case -4:
                    width = 100; height = 350;
                    image = Form1.pipeVer;
                    break;
                case -5:
                    width = 100; height = 700;
                    image = Form1.pipeVer;
                    break;
                case -6:
                     width = 100; height = 1000;
                    image = Form1.pipeVer;
                    break;
                case -7:
                    width = 100; height = 200;
                    image = Form1.pipe1;
                    break;
                case -8:
                     width = 100; height = 350;
                    image = Form1.pipe1;
                    break;
                case -9:
                     width = 100; height = 750;
                    image = Form1.pipe1;
                    break;
                case -10:
                    width = height = 50;
                    image = Form1.brick;
                    break;
                case -11:
                     width = 50; height = 50;
                    image = Form1.block1;
                    break;
                case -12:
                    width = 50; height = 50;
                    image = Form1.block2;
                    break;
                case -13:
                    width = 50; height = 50;
                    image = Form1.block3;
                    break;
                case -14:
                    width = 50; height = 50;
                    image = Form1.block4;
                    break;
                case -15:
                    width = 50; height = 50;
                    image = Form1.block5;
                    break;
                case -20:
                     width = 150; height = 100;
                    image = Form1.land1;
                    break;
                case -21:
                     width = 150; height = 100;
                    image = Form1.land2;
                    break;
                case -25:
                    width = 20; height = 350;
                    image = Form1.flag;
                    break;
                case -26:
                    width = 400+117; height = 400;
                    image = Form1.house;
                    break;
                //--
                #endregion
                #region Scenery
                case -31:
                    height = 150; width = 300;
                    image = Form1.bushbig;
                    break;
                case -32:
                     width = 150;height =200 ;
                    image = Form1.castus1;
                    break;
                case -33:
                     width = 270;height =250/3 ;
                    image = Form1.bushsmall;
                    break;
                case -34:
                      width = 100;height =271 ;
                    image = Form1.tree;
                    break;
                case -35:
                      width = 110;height =100 ;
                    image = Form1.crass;
                    break;
                case -36:
                    height = 250; width = 200;
                    image = Form1.pine;
                    break;
                case -37:
                      width = 100;height =100 ;
                    image = Form1.bud;
                    break;
                case -38:
                      width = 200;height =100 ;
                    image = Form1.cloud1;
                    break;
                case -39:
                    height =  width = 100;
                    image = Form1.sign;
                    break;
                case -40:
                    height = 100; width = 150;
                    image = Form1.cloud2;
                    break;
                case -41:
                      width = 400;height =250 ;
                    image = Form1.cloud3;
                    break;
                case -42:
                      width = 200;height =250 ;
                    image = Form1.castus2;
                    break;
                case -43:
                      width = 300;height =250 ;
                    image = Form1.hill;
                    break;
                case -44:
                    width = 800;height =250 ;
                    image = Form1.castus3;
                    break;
                #endregion
                case 100:
                      width = 50; height = 60;
                    image = Form1.mario;   
                    break;
                default:
                    break;
            }
        }

    }
}
