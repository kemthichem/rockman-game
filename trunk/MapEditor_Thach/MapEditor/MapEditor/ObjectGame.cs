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
        _LAND,
        LAND1,
        LAND2,
        _LAND1,
        LAND3,
        LANDWHITE,
        LANDICEBERG,
        _LANDWHITE,
        _LANDICEBERG,
        ROCKMAN = 0,
        LADDER10,
        LADDER5,
        LADDER6,
        LADDER2,
        LADDER7,
        LADDER4,
        BIGEYE,
        BLADER,
        MET,
        SCREW_BOMBER,
        SCREW_BOMBER_D,
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
        ITEM,
        //***FOR GUTSMAN MAP***//
        DA,
        DAYNOI,
        DUONG,
        LOXO,
        MAY,
        MUINHON,
        NEN,
        NUI,
        NUI1,
        RAO,
        TUONG,
        TUONGNHO,
        TUONGPHAI,
        TUONGTRAI,
        TRUC,
        TRUCTRAI,
        TRUCPHAI
    };

    class ObjectGame
    {
        public int Id;
        public ObjectType TypeOb;
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
        public ObjectGame(Point p, ObjectType type)
        {
            Id = -1;
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
                case ObjectType._LAND:
                    width = 128;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.land;
                    break;
                case ObjectType.LAND1:
                    width = 32;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.land2;
                    break;
                case ObjectType.LAND2:
                    width = 32;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.land2_1;
                    break;              
                case ObjectType._LAND1:
                    width = 64;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.land1;
                    break;
                case ObjectType.LANDWHITE:

                case ObjectType._LANDWHITE:
                    width = 96;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.landwhite;
                    break;

                case ObjectType.LANDICEBERG:
                                        width = 64;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.LandIceberg;
                    break;
                case ObjectType.LAND3:
                    width = 64;
                    height = 64;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.land3;
                    break;
                case ObjectType.ROCKMAN:
                    break;
                case ObjectType.LADDER10:
                    width = 32;
                    height = 320;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.ladder_full;
                    break;
                case ObjectType.LADDER5:
                    width = 32;
                    height = 160;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.ladder_full;
                    break;
                case ObjectType.LADDER6:
                    width = 32;
                    height = 192;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.ladder_full;
                    break;
                case ObjectType.LADDER2:
                    width = 32;
                    height = 64;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.ladder_full;
                    break;
                case ObjectType.LADDER4:
                    width = 32;
                    height = 128;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.ladder_full;
                    break;
                case ObjectType.LADDER7:
                    width = 32;
                    height = 224;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.ladder_full;
                    break;
                case ObjectType.BIGEYE:
                    width = 65;
                    height = 97;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_bigeye;
                    break;
                case ObjectType.BLADER:
                    width = 35;
                    height = 45;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_blader;
                    break;
                case ObjectType.MET:
                    width = 40;
                    height = 30;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_met;
                    break;
                case ObjectType.SCREW_BOMBER:
                    width = 35;
                    height = 35;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_screwbomber;
                    break;
                case ObjectType.SCREW_BOMBER_D:
                    width = 35;
                    height = 35;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_screwbomber__down;
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
                     width = 32;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.octopus_left;
                    break;
                case ObjectType.OCTOPUS_D:
                    width = 32;
                    height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.octopus_up;
                    break;
                case ObjectType.BEAK:
                    width = 30;
                    height = 35;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.break_left;
                    break;
                case ObjectType.BEAK_R:
                    width = 30;
                    height = 35;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.enemy_break__right;
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
                //***FOR GUTSMAN***//
                case ObjectType.DA:
                    width = 50;
                    height = 50;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.DA;
                    break;
                case ObjectType.DAYNOI:
                    width = 26;
                    height = 4;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.DAYNOI;
                    break;
                case ObjectType.DUONG:
                     width = 64;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.DUONG;
                    break;
                case ObjectType.LOXO:
                     width = 32;
                     height = 176;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.LOXO;
                    break;
                case ObjectType.MAY:
                     width = 64;
                     height = 120;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.MAY;
                    break;
                case ObjectType.MUINHON:
                     width = 32;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.MUINHON;
                    break;
                case ObjectType.NEN:
                     width = 64;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.NEN;
                    break;
                case ObjectType.NUI:
                     width = 32;
                     height = 88;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.NUI;
                    break;
                case ObjectType.NUI1:
                     width = 370;
                     height = 186;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.NUI1;
                    break;
                case ObjectType.RAO:
                     width = 180;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.RAO;
                    break;
                case ObjectType.TUONG:
                     width = 32;
                     height = 160;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TUONG;
                    break;
                case ObjectType.TUONGNHO:
                     width = 32;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TUONGNHO;
                    break;
                case ObjectType.TUONGPHAI:
                     width = 32;
                     height = 280;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TUONGPHAI;
                    break;
                case ObjectType.TUONGTRAI:
                     width = 32;
                     height = 280;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TUONGTRAI;
                    break;
                case ObjectType.TRUC:
                     width = 64;
                     height = 12;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TRUC;
                    break;
                case ObjectType.TRUCTRAI:
                     width = 128;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TRUC_TRAI;
                    break;
                case ObjectType.TRUCPHAI:
                     width = 64;
                     height = 32;
                    if (isGetImage)
                        image = global::MapEditor.Properties.Resources.TRUCPHAI;
                    break;
                default:
                    break;
            }
        }
        public void SetId(int _id)
        {
            Id = _id;
        }
        public Rectangle BoundInQuadTree;
    }
}
