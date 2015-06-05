using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace MapEditer
{
    class cImage
    {
        public int  id;
        public int postX;
        public int postY;
        public int width;
        public int height;
        public cImage(int _id, int _postX, int _postY, int _width, int _height)
        { 
            id = _id;      
            postX = _postX;
            postY = _postY;
            width = _width;
            height = _height;
        }
    }
}
