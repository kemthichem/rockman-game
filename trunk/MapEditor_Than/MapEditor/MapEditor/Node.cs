using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor
{
    class Node
    {
        public Node(int _level, int _id, Rectangle _rect, Node _parent)
        {
            Level = _level;
            Id = _id;
            Bound = _rect;
            Parent = _parent;

            Width = Bound.Right - Bound.Left;
            Height = Bound.Bottom - Bound.Top;
            ListObject = new List<ObjectGame>();
        }
        public int Level;
        public int Id;
        public Rectangle Bound;
        public List<ObjectGame> ListObject;
        private int Width, Height;

        public Node Parent, LeftTop, RightTop, LeftBottom, RightBottom;

        public void AddObjectToNode(ObjectGame ob)
        {
            if(!Bound.IntersectsWith(ob.BoundInQuadTree))
		        return;
            if (LeftTop == null && Width > 512)
                CreateSubNode();
            if (LeftTop != null)
            {
                //Loop in child Node
                if (CanAddToNode(LeftTop, ob) ||
                    CanAddToNode(RightTop, ob) ||
                    CanAddToNode(LeftBottom, ob) ||
                    CanAddToNode(RightBottom, ob))
                    return;
                //else
                //{
                //    if (LeftBottom.ListObject.Count == 0)
                //        LeftBottom = null;
                //    if (LeftTop.ListObject.Count == 0)
                //        LeftTop = null;
                //    if (RightTop.ListObject.Count == 0)
                //        RightTop = null;
                //    if (RightBottom.ListObject.Count == 0)
                //        RightBottom = null;
                //}
            }

	        ListObject.Add(ob);
        }

        private bool CanAddToNode(Node _node, ObjectGame ob)
        {
            if (_node.Bound.IntersectsWith(ob.BoundInQuadTree))
            {
                _node.AddObjectToNode(ob);
                return true;
            }
            return false;
        }

        private void CreateSubNode()
        {

            {
                Rectangle rect = new Rectangle(Bound.Left, Bound.Top, Width / 2, Height / 2);
                int id = Id*4 + 1;
                LeftTop = new Node(Level + 1, id, rect, this);
            }

            {
                Rectangle rect = new Rectangle(Bound.Left + Width/2, Bound.Top, Width / 2, Height / 2);
                int id = Id * 4 + 2;
                RightTop = new Node(Level + 1, id, rect, this);
            }

            {
                Rectangle rect = new Rectangle(Bound.Left, Bound.Top + Height/2, Width / 2, Height / 2);
                int id = Id * 4 + 3;
                LeftBottom = new Node(Level + 1, id, rect, this);
            }

            {
                Rectangle rect = new Rectangle(Bound.Left + Width/2, Bound.Top + Height/2, Width / 2, Height / 2);
                int id = Id * 4 + 4;
                RightBottom = new Node(Level + 1, id, rect, this);
            }
            
        }


        public void WriteFile(System.IO.StreamWriter writer)
        {
            writer.Write(Id + " ");
            writer.Write( Bound.Left + " ");
            writer.Write(QuadTree.HeightQuadTree - Bound.Top + " ");
            writer.Write(Bound.Right + " ");
            writer.Write(QuadTree.HeightQuadTree - Bound.Bottom + " ");

            foreach (ObjectGame item in ListObject)
            {
                writer.Write(item.Id + " ");
            }
            writer.Write("\r\n");

            if (LeftTop != null)
            {
                LeftTop.WriteFile(writer);
                RightTop.WriteFile(writer);
                LeftBottom.WriteFile(writer);
                RightBottom.WriteFile(writer);
            }

        }
    }
}
