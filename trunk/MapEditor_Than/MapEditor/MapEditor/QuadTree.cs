using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor
{
    class QuadTree
    {
        public QuadTree()
        {
        }
        public static int HeightQuadTree;
        public int Width, Height;
        public Node NodeRoot;
        public void AddObject(ObjectGame ob)
        {
            if (NodeRoot.Bound.Contains (ob.BoundInQuadTree))
                NodeRoot.AddObjectToNode(ob);
        }
        public List<ObjectGame> GetAllObject()
        {
            return null;
        }
        public void SetSizeQuadTree(Rectangle _rectMap)
        {
            int max = _rectMap.Width > _rectMap.Height ? _rectMap.Width : _rectMap.Height;

            int n = 0;
            while (Math.Pow(2, n) < max)
            {
                n++;
            }
            Width = Height = HeightQuadTree = (int)Math.Pow(2, n);
            CreateNodeRoot();
        }
        private void CreateNodeRoot()
        {
            Rectangle BoundRoot = new Rectangle(0, 0, Width, Height);

            NodeRoot = new Node(0, 0, BoundRoot, null);
        }

        public void WriteFile(StreamWriter writer)
        {
            NodeRoot.WriteFile(writer);
        }
        
    }
}
