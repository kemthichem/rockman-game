using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace MapEditer
{
    public partial class formEditor : Form
    {
        private int id;
        private List<cImage> listImage = new List<cImage>();
        private PictureBox pic;
        private bool isdraw;

        public formEditor()
        {
            InitializeComponent();
        }
        private void formEditor_Load(object sender, EventArgs e)
        {
            picMario.SizeMode = PictureBoxSizeMode.CenterImage;
            picGoomla.SizeMode = PictureBoxSizeMode.CenterImage;
            picRedMushroom.SizeMode = PictureBoxSizeMode.CenterImage;
            picBlueMushRoom.SizeMode = PictureBoxSizeMode.CenterImage;
            picSelected.SizeMode = PictureBoxSizeMode.CenterImage;
        }
        #region Click Picturebox
        private void picMario_Click(object sender, EventArgs e)
        {
            picSelected.Image = picMario.Image;
            tbX.Text = "0";
            tbY.Text = "0";
            tbID.Text = "1";
            id = 1;
        }
        private void picGoomla_Click(object sender, EventArgs e)
        {
            picSelected.Image = picGoomla.Image;
            tbX.Text = "0";
            tbY.Text = "0";
            tbID.Text = "2";
            id = 2;
        }
        private void picRedMushroom_Click(object sender, EventArgs e)
        {
            picSelected.Image = picRedMushroom.Image;
            tbX.Text = "0";
            tbY.Text = "0";
            tbID.Text = "3";
            id = 3;
        }
        private void picBludeMushRoom_Click(object sender, EventArgs e)
        {
            picSelected.Image = picBlueMushRoom.Image;
            tbX.Text = "0";
            tbY.Text = "0";
            tbID.Text = "4";
            id = 4;
        }
        #endregion
        private void pnView_MouseDown(object sender, MouseEventArgs e)
        {

            switch (id)
            {
                case 1:
                    {
                        pic = new PictureBox();
                        tbX.Text = e.X.ToString();
                        tbY.Text = e.Y.ToString();
                        tbID.Text = id.ToString();
                        Image temp = Image.FromFile("mario.png");
                        pic.Image = temp;
                        pic.Width = temp.Width;
                        pic.Height = temp.Height;
                        pic.Location = new Point(e.X, e.Y);
                        pnView.Controls.Add(pic);
                        cImage image = new cImage(id, e.X, e.Y, temp.Width, temp.Height);
                        listImage.Add(image);
                        break;
                    }
                case 2:
                    {
                        pic = new PictureBox();
                        tbX.Text = e.X.ToString();
                        tbY.Text = e.Y.ToString();
                        tbID.Text = id.ToString();
                        Image temp = Image.FromFile("goomla.png");
                        pic.Image = temp;
                        pic.Width = temp.Width;
                        pic.Height = temp.Height;
                        pic.Location = new Point(e.X, e.Y);
                        pnView.Controls.Add(pic);
                        cImage image = new cImage(id, e.X, e.Y, temp.Width, temp.Height);
                        listImage.Add(image);
                        break;
                    }
                case 3:
                    {
                        pic = new PictureBox();
                        tbX.Text = e.X.ToString();
                        tbY.Text = e.Y.ToString();
                        tbID.Text = id.ToString();
                        Image temp = Image.FromFile("red_mushroom.png");
                        pic.Image = temp;
                        pic.Width = temp.Width;
                        pic.Height = temp.Height;
                        pic.Location = new Point(e.X, e.Y);
                        pnView.Controls.Add(pic);
                        cImage image = new cImage(id, e.X, e.Y, temp.Width, temp.Height);
                        listImage.Add(image);
                        break;
                    }
                case 4:
                    {
                        pic = new PictureBox();
                        tbX.Text = e.X.ToString();
                        tbY.Text = e.Y.ToString();
                        tbID.Text = id.ToString();
                        Image temp = Image.FromFile("blue_mushroom.png");
                        pic.Image = temp;
                        pic.Width = temp.Width;
                        pic.Height = temp.Height;
                        pic.Location = new Point(e.X, e.Y);
                        pnView.Controls.Add(pic);
                        cImage image = new cImage(id, e.X, e.Y, temp.Width, temp.Height);
                        listImage.Add(image);
                        break;
                    }
            }
        }
        private void btSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.FileName = "map.txt";
            save.Filter = "Text File | *.txt";
            if (save.ShowDialog() == DialogResult.OK)
            {
                StreamWriter writer = new StreamWriter(save.OpenFile());
                writer.WriteLine(listImage.Count);
                for (int i = 0; i < listImage.Count; i++)
                {

                    writer.Write(listImage[i].id);
                    writer.Write(" ");
                    writer.Write(listImage[i].postX);
                    writer.Write(" ");
                    writer.Write(listImage[i].postY);
                    //writer.Write(" ");
                    //writer.Write(listImage[i].width);
                    //writer.Write(" ");
                    //writer.Write(listImage[i].height);
                    //writer.Write(" ");
                    writer.WriteLine("");

                }
                writer.Dispose();
                writer.Close();
            }


        }
        private void btLoad_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog.ShowDialog(); // Show the dialog.
            if (result == DialogResult.OK) // Test result.
            {
                string file = openFileDialog.FileName;
                try
                {
                    StreamReader reader = new StreamReader(file);
                    string strAllFile = reader.ReadToEnd();
                    string[] arrLines = strAllFile.Split(new char[] { '\n' });
                    char[] space = new char[] { ' ' };
                    int count = Int32.Parse(arrLines[0]);
                    string[] post = new string[] { };
                    for (int i = 1; i < count + 1; i++)
                    {
                        post = arrLines[i].Split(space);
                        if (Int32.Parse(post[0]) == 1)
                        {
                            pic = new PictureBox();
                            Image temp = Image.FromFile("mario.png");
                            pic.Image = temp;
                            pic.Width = temp.Width;
                            pic.Height = temp.Height;
                            pic.Location = new Point(Int32.Parse(post[1]), Int32.Parse(post[2]));
                            pnView.Controls.Add(pic);
                        }
                        else if (Int32.Parse(post[0]) == 2)
                        {
                            pic = new PictureBox();
                            Image temp = Image.FromFile("goomla.png");
                            pic.Image = temp;
                            pic.Width = temp.Width;
                            pic.Height = temp.Height;
                            pic.Location = new Point(Int32.Parse(post[1]), Int32.Parse(post[2]));
                            pnView.Controls.Add(pic);
                        }
                        else if (Int32.Parse(post[0]) == 3)
                        {
                            pic = new PictureBox();
                            Image temp = Image.FromFile("red_mushroom.png");
                            pic.Image = temp;
                            pic.Width = temp.Width;
                            pic.Height = temp.Height;
                            pic.Location = new Point(Int32.Parse(post[1]), Int32.Parse(post[2]));
                            pnView.Controls.Add(pic);
                        }
                        else if (Int32.Parse(post[0]) == 4)
                        {
                            pic = new PictureBox();
                            Image temp = Image.FromFile("blue_mushroom.png");
                            pic.Image = temp;
                            pic.Width = temp.Width;
                            pic.Height = temp.Height;
                            pic.Location = new Point(Int32.Parse(post[1]), Int32.Parse(post[2]));
                            pnView.Controls.Add(pic);
                        }
                    }
                }
                catch (IOException)
                {
                }
            }
        }
        private void btShowGrid_Click(object sender, EventArgs e)
        {
            isdraw = true;
            pnView.Refresh();
        }
        private void btClear_Click(object sender, EventArgs e)
        {
            isdraw = false;
            pnView.Refresh();
            pnView.Controls.Clear();
            tbID.ResetText();
            tbX.ResetText();
            tbY.ResetText();

        }
        private void btShowTree_Click(object sender, EventArgs e)
        {
            int maxwidth = 0, maxheight = 0;
            for (int i = 0; i < listImage.Count; i++)
            {
                if (listImage[i].postX + listImage[i].width > maxwidth)
                    maxwidth = listImage[i].postX + listImage[i].width;
                if (listImage[i].postY + listImage[i].height > maxheight)
                    maxheight = listImage[i].postY + listImage[i].height;
            }

            Node root = new Node(0, 0, 0, maxwidth, maxheight);
            for (int i = 0; i < listImage.Count; i++)
            {
                root.objects.Add(listImage[i]);
            }
            Buil(root);
        }
        private void btSaveTree_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.FileName = "quadtree.txt";
            save.Filter = "Text File | *.txt";
            if (save.ShowDialog() == DialogResult.OK)
            {
                StreamWriter writer = new StreamWriter(save.OpenFile());
                int maxwidth = 0, maxheight = 0;
                for (int i = 0; i < listImage.Count; i++)
                {
                    if (listImage[i].postX + listImage[i].width > maxwidth)
                        maxwidth = listImage[i].postX + listImage[i].width;
                    if (listImage[i].postY + listImage[i].height > maxheight)
                        maxheight = listImage[i].postY + listImage[i].height;
                }

                Node root = new Node(0, 0, 0, maxwidth, maxheight);
                for (int i = 0; i < listImage.Count; i++)
                {
                    root.objects.Add(listImage[i]);
                }
                Buil(root);
                SaveTree(root, writer);
                writer.Dispose();
                writer.Close();
            }
        }
        private void pnBackGround_Scroll(object sender, ScrollEventArgs e)
        {
            pnView.Width += 10;
        }
        private void pnView_Paint(object sender, PaintEventArgs e)
        {
            if (isdraw)
            {
                Graphics g = e.Graphics;
                for (int i = 0; i < 1000; i++)
                {
                    g.DrawLine(new Pen(Color.Red, 1), new Point(i * 50, -400), new Point(i * 50, 10000));
                    g.DrawLine(new Pen(Color.Red, 1), new Point(0, i * 50), new Point(10000, i * 50));
                }
                g.Dispose();
            }
        }
    
        #region function tree
        private void Buil(Node node)
        {
            int width = node.x2 - node.x1;
            int height = node.y2 - node.y1;
            Graphics g = this.pnView.CreateGraphics();
            g.DrawRectangle(new Pen(Color.Red, 3), node.x1, node.y1, width, height);
            int numobj = node.objects.Count;
            if (node.x2 - node.x1 > 100 && numobj > 1)
            {
                node.node_lt = new Node(node.id * 10 + 1, node.x1, node.y1, node.x1 + width / 2, node.y1 + height / 2);
                node.node_rt = new Node(node.id * 10 + 2, node.x1 + width / 2, node.y1, node.x1 + width, node.y1 + height / 2);
                node.node_lb = new Node(node.id * 10 + 3, node.x1, node.y1 + height / 2, node.x1 + width / 2, node.y1 + height);
                node.node_rb = new Node(node.id * 10 + 4, node.x1 + width / 2, node.y1 + height / 2, node.x2, node.y2);
                for (int i = 0; i < numobj; i++)
                {
                    if (Clip(node.node_lt, node.objects[i]) + Clip(node.node_rt, node.objects[i]) + Clip(node.node_lb, node.objects[i]) + Clip(node.node_rb, node.objects[i]) != 0)
                    {
                        node.objects.Remove(node.objects[i]);
                        i--;
                        numobj--;
                    }
                }
                Buil(node.node_lt);
                Buil(node.node_rt);
                Buil(node.node_lb);
                Buil(node.node_rb);
            }
        }
        private void SaveTree(Node node, StreamWriter f)
        {
            string s = node.serialize();
            f.WriteLine(s);
            if (node.node_lt != null) SaveTree(node.node_lt, f);
            if (node.node_rt != null) SaveTree(node.node_rt, f);
            if (node.node_lb != null) SaveTree(node.node_lb, f);
            if (node.node_rb != null) SaveTree(node.node_rb, f);
        }
        private int Clip(Node node, cImage image)
        {
            bool intersection = true;
            Point point = new Point(0, 0);
            int inwidth = 0;
            int inheight = 0;
            if (image.postX + image.width < node.x1 || image.postX > node.x2 || image.postY + image.height < node.y1 || image.postY > node.y2) //khong giao
            {
                intersection = false;
            }
            #region Cat trai
            else if (image.postX <= node.x1 && image.postX + image.width >= node.x1)
            {
                inwidth = image.postX + image.width - node.x1;
                if (image.postY <= node.y1)
                {
                    point.X = node.x1;
                    point.Y = node.y1;
                    if (image.postY + image.height > node.y2)//bao trai
                    {
                        inheight = node.y2 - node.y1;
                    }
                    else//goc trai tren
                    {
                        inheight = image.postY + image.height - node.y1;
                    }
                }
                else //if (image.postY > node.y1)
                {
                    point.X = node.x1;
                    point.Y = image.postY;
                    if (image.postY + image.height <= node.y2) //giua trai
                    {
                        inheight = image.height;
                    }
                    else //if (image.postY + image.height > node.y2) goc trai duoi
                    {
                        inheight = node.y2 - image.postY;
                    }
                }
            }
            #endregion

            #region Cat giua
            else if (image.postX >= node.x1)
            {
                if (image.postX + image.width <= node.x2)
                {
                    point.X = image.postX;
                    if (image.postY <= node.y1 && image.postY + image.height > node.y1)
                    {
                        point.Y = node.y1;
                        inwidth = image.width;
                        if (image.postY + image.height < node.y2) //giua tren
                        {
                            inheight = image.postY + image.height - node.y1;
                        }
                        else //if (image.postY + image.height >= node.y2) bao giua
                        {
                            inheight = node.y2 - node.y1;
                        }
                    }
                    else if (image.postY > node.y1)
                    {
                        point.Y = image.postY;
                        inwidth = image.width;
                        if (image.postY + image.height < node.y2) // giua
                        {
                            inheight = image.height;
                        }
                        else if (image.postY + image.height > node.y2) //giua duoi
                        {
                            inheight = node.y2 - image.postY;
                        }
                    }

                }

            #endregion

                #region Cat giua
                else //if (image.postX + image.width > node.x2)
                {
                    if (image.postY <= node.y1 && image.postY + image.height > node.y1)
                    {
                        point.X = image.postX;
                        point.Y = node.y1;
                        inwidth = node.x2 - image.postX;
                        if (image.postY + image.height < node.y2)//goc phai
                        {
                            inheight = image.postY + image.height - node.y1;
                        }
                        else //if (image.postY + image.height >= node.y2) bao phai
                        {
                            inheight = node.y2 - node.y1;
                        }
                    }
                    else if (image.postY > node.y1)
                    {
                        point.X = image.postX;
                        point.Y = image.postY;
                        inwidth = node.x2 - image.postX;
                        if (image.postY + image.height < node.y2)//giua phai
                        {
                            inheight = image.height;
                        }
                        else //if (image.postY + image.height >= node.y2) goc phai
                        {
                            inheight = node.y2 - image.postY;
                        }
                    }
                }
            }
                #endregion

            if (intersection)
            {
                image = new cImage(image.id, point.X, point.Y, inwidth, inheight);
                node.objects.Add(image);
                return 1;
            }
            return 0;
        }
        #endregion



    }
}
