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
        _LAND1,
        LANDWHITE,
        LANDICEBERG,
        ROCKMAN = 0,
        LADDER,
        BIGEYE,
        BLADER,
        MET,
        SCREW_BOMBER,
        OCTOPUS,
        OCTOPUS_D,
        BEAK,
        BEAK_R,
        FLEA,
        SPINE,
        MOVEMAP,
        CUTMAN,
        GUTSMAN,
        ICEMAN,
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
                        image = global::MapEditor.Properties.Resources.land13;
                    break;
                case ObjectType._LAND1:
                    width = 64;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.land13;
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
                        image = global::MapEditor.Properties.Resources.enemy_bigeye;
                    break;
                case ObjectType.BLADER:
                    break;
                case ObjectType.MET:
                    width = 40;
                    height = 30;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_met;
                    break;
                case ObjectType.FLEA:
                    width = 32;
                    height = 38;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_flea;
                    break;
                case ObjectType.SPINE:
                    width = 32;
                    height = 18;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_spine;
                    break;
                case ObjectType.OCTOPUS:
                    break;
                case ObjectType.BEAK:
                    width = 30;
                    height = 35;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.break_left;
                    break;
                case ObjectType.MOVEMAP:
                    width = 32;
                    height = 1;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.movemap;
                    break;

                //***********BOSS***************//
                case ObjectType.CUTMAN:
                    width = 48;
                    height = 65;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.cutman;
                    break;
                case ObjectType.ICEMAN:
                    width = 56;
                    height = 60;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.iceman;
                    break;
                case ObjectType.GUTSMAN:
                    width = 70;
                    height = 70;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.gutsman;
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
