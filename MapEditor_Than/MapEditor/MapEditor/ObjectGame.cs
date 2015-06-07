using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace MapEditor
{
    enum ObjectType
    {
        SCENERY = -10,
        LANDTYPE,
        LAND1TYPE,
        LANDWHITE,
        LANDICEBERG,
        ROCKMANTYPE = 0,
        LADDERTYPE,
        BIGEYETYPE,
        BLADER,
        CUTMAN,
        ICEMAN,
        SCREW_BOMBER,
        OCTOPUS,
        BEAK,
        FLEA,
        MOVEMAPTYPE,
        BULLET,
        ITEM
    };

    class ObjectGame
    {
        public int Id; //Auto increase
        public ObjectType TypeOb;
        public static List<int> ListIdJustDeleted = new List<int>();
        public static int CurrentId = 0;
        private Image image;
        public Rectangle Bound;
        private Point pos;
        public Point Pos
        {
            get { return pos; }
        }

        private int width, height;
        //-----------
        public ObjectGame(Point p, int _id, ObjectType type)
        {
            Id = _id;
            pos.X = p.X - 32;
            pos.Y = p.Y - 32;
            TypeOb = type;
            //pos.X = 50 * (p.X / 50);
            //pos.Y = 50 * (p.Y / 50);
            SetKind(type);
        }
        public void Draw(Graphics g)
        {
            if(image!=null)
                g.DrawImage(image, new Rectangle(Point.Add (pos, new Size(32,32)), new Size(width, height)));
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
        private void SetKind(ObjectType kind)
        {
            switch (kind)
            {
                case ObjectType.SCENERY:
                    break;
                case ObjectType.LANDTYPE:
                    break;
                case ObjectType.LAND1TYPE:
                    width = 64;
                    height = 32;
                    image = Form1.Land1Image;
                    break;
                case ObjectType.LANDWHITE:
                    break;
                case ObjectType.LANDICEBERG:
                    break;
                case ObjectType.ROCKMANTYPE:
                    break;
                case ObjectType.LADDERTYPE:
                    break;
                case ObjectType.BIGEYETYPE:
                    width = 65;
                    height = 97;
                    image = Form1.BigEyeImage;
                    break;
                case ObjectType.BLADER:
                    break;
                case ObjectType.CUTMAN:
                    break;
                case ObjectType.ICEMAN:
                    break;
                case ObjectType.SCREW_BOMBER:
                     width = 35;
                    height = 35;
                    image = Form1.ScrewImage;
                    break;
                case ObjectType.OCTOPUS:
                    break;
                case ObjectType.BEAK:
                    break;
                case ObjectType.FLEA:
                    break;
                case ObjectType.MOVEMAPTYPE:
                     width = 32;
                    height = 1;
                    image = Form1.MoveMapImage;
                    break;
                case ObjectType.BULLET:
                    break;
                case ObjectType.ITEM:
                    break;
                default:
                    break;
            }
            Bound = new Rectangle(pos, new Size(width, height));
        }
    }
}
