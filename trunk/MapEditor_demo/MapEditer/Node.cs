using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;
namespace MapEditer
{
    class Node
    {
        public List<cImage> objects;
        public Node node_lt;
        public Node node_rt;
        public Node node_lb;
        public Node node_rb;
        public int x1, y1, x2, y2;
        public int id;
        public Node(int ID, int X1, int Y1, int X2, int Y2)
        {
            objects = new List<cImage>();
            this.id = ID;
            this.x1 = X1;
            this.y1 = Y1;
            this.x2 = X2;
            this.y2 = Y2;
        }
        public string serialize()
        {
                string s =id.ToString() + " " + x1.ToString() + " " + y1.ToString() + " " + x2.ToString() + " " + y2.ToString() + " ";
                for(int i = 0; i < objects.Count; i++)
                    s += objects[i].id.ToString()+ " ";
                return s;
        }

    }
}
