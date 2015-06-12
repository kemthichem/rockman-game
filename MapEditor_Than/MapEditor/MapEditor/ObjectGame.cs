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
        LAND,
        LAND1,
        LANDWHITE,
        LANDICEBERG,
        ROCKMAN = 0,
        LADDER,
        BIGEYE,
        BLADER,
        CUTMAN,
        ICEMAN,
        SCREW_BOMBER,
        OCTOPUS,
        BEAK,
        FLEA,
        MOVEMAP,
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

        public Point PosInQuadTree
        {
            get { return new Point(pos.X, pos.Y + (QuadTree.HeightQuadTree - Form1.HeightOfMap)); }
        }

        public Point PosToSave
        {
            get { return new Point(pos.X, Form1.HeightOfMap - pos.Y);}
        }

        private int width, height;
        //-----------
        public ObjectGame(Point p, int _id, ObjectType type)
        {
            Id = _id;
            pos.X = p.X - 32;
            pos.Y = p.Y - 32;
            TypeOb = type;
            SetKind(type, true, ref width, ref height, ref image);
            Bound = new Rectangle(pos, new Size(width, height));
            BoundInQuadTree = new Rectangle(PosInQuadTree, new Size(width, height));
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
        public static void SetKind(ObjectType kind, bool isGetImage,  ref int width, ref int height, ref Image image)
        {
            switch (kind)
            {
                case ObjectType.SCENERY:
                    break;
                case ObjectType.LAND:
                    break;
                case ObjectType.LAND1:
                    width = 64;
                    height = 32;
                    if (isGetImage)
                        image = Form1.Land1Image;
                    break;
                case ObjectType.LANDWHITE:
                    break;
                case ObjectType.LANDICEBERG:
                    break;
                case ObjectType.ROCKMAN:
                    break;
                case ObjectType.LADDER:
                    break;
                case ObjectType.BIGEYE:
                    width = 65;
                    height = 97;
                    if (isGetImage)
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
                    if (isGetImage)
                        image = Form1.ScrewImage;
                    break;
                case ObjectType.OCTOPUS:
                    break;
                case ObjectType.BEAK:
                    break;
                case ObjectType.FLEA:
                    break;
                case ObjectType.MOVEMAP:
                    width = 32;
                    height = 1;
                    if (isGetImage)
                        image = Form1.MoveMapImage;
                    break;
                case ObjectType.BULLET:
                    break;
                case ObjectType.ITEM:
                    break;
                default:
                    break;
            }
        }

        public Rectangle BoundInQuadTree;
    }
}
