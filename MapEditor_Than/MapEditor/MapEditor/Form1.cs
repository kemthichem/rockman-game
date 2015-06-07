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

namespace MapEditor
{
    public partial class Form1 : Form
    {
        int numWidth;
        int numHeight;
        static int HeightPictureBox;
        int size;
        int id, idTemp;
        ObjectType TypeCurrent;
        string BgFilePath;
        Rectangle RectGrid;
        Control controlSelected;
        //------
        private List<String> nameObjects;
        private static List<ObjectGame> listContents;

        //------
        QuadTree Tree;


        #region Recource Image
        private Image background;
        public static Image ScrewImage;

        //--
        public static Image BigEyeImage;
        public static Image MoveMapImage;
        public static Image Land1Image;
        public static Image mush;
        public static Image mush1;
        public static Image mush2;
        public static Image mushlife;
        public static Image mushlife1;
        public static Image mushlife2;
        public static Image flag;
        public static Image house;
        public static Image star;
        public static Image turtle;
        public static Image eato;
        public static Image enemy;
        public static Image land1;
        public static Image land2;
        public static Image block1;
        public static Image coin;
        public static Image coin1;
        public static Image coin1c;
        public static Image coin10c;
        public static Image bushbig;
        public static Image pine;
        public static Image cloud2;
        public static Image sign;
        public static Image block2;
        public static Image block3;
        public static Image block4;
        public static Image block5;
        //  [10/1/2013 TheRise]
        public static Image castus1;
        public static Image tree;
        public static Image bushsmall;
        public static Image crass;
        public static Image bud;
        public static Image cloud1;
        public static Image cloud3;
        public static Image castus2;
        public static Image hill;
        public static Image castus3;
        public static Image mario;
      
        #endregion

        public Form1()
        {
            InitializeComponent();
        }
        private void LoadResources()
        {
            BgFilePath = "Resource/background1.png";
            background = Image.FromFile(BgFilePath);
            ScrewImage = Image.FromFile("Resources/enemy/enemy_screwbomber.png");
            Land1Image = Image.FromFile("Resources/ground/Land1.png");
            MoveMapImage = Image.FromFile("Resources/item/movemap.png");
            BigEyeImage = Image.FromFile("Resources/enemy/enemy_bigeye.png");
            mush = Image.FromFile("Resources/mush.png");
            mush1 = Image.FromFile("Resources/mush1.png");
            mush2 = Image.FromFile("Resources/mush2.png");
            mushlife = Image.FromFile("Resources/mushlife.png");
            mushlife1 = Image.FromFile("Resources/mushlife1.png");
            mushlife2 = Image.FromFile("Resources/mushlife2.png");
            flag = Image.FromFile("Resources/flag.png");
            house = Image.FromFile("Resources/house.png");
            star = Image.FromFile("Resources/star.png");
            turtle = Image.FromFile("Resources/turtle.png");
            eato = Image.FromFile("Resources/eato.png");
            enemy = Image.FromFile("Resources/enemy.png");
            land1 = Image.FromFile("Resources/land1.png");
            land2 = Image.FromFile("Resources/land2.png");
            block1 = Image.FromFile("Resources/block1.png");
            coin = Image.FromFile("Resources/coin.png");
            coin1 = Image.FromFile("Resources/coin1.png");
            coin1c = Image.FromFile("Resources/coin1c.png");
            coin10c = Image.FromFile("Resources/coin10c.png");
            bushbig = Image.FromFile("Resources/Scenery/bushbig.png");
            pine = Image.FromFile("Resources/Scenery/pine.png");
            cloud2 = Image.FromFile("Resources/Scenery/cloud2.png");
            sign = Image.FromFile("Resources/Scenery/sign.png");
            //  [10/1/2013 TheRise]
            castus1 = Image.FromFile("Resources/Scenery/castus1.png");
            tree = Image.FromFile("Resources/Scenery/tree.png");
            bushsmall = Image.FromFile("Resources/Scenery/bushsmall.png");
            crass = Image.FromFile("Resources/Scenery/crass.png");
            bud = Image.FromFile("Resources/Scenery/bud.png");
            cloud1 = Image.FromFile("Resources/Scenery/cloud1.png");
            cloud3 = Image.FromFile("Resources/Scenery/cloud3.png");
            castus2 = Image.FromFile("Resources/Scenery/castus2.png");
            hill = Image.FromFile("Resources/Scenery/hill.png");
            castus3 = Image.FromFile("Resources/Scenery/castus3.png");
            block2 = Image.FromFile("Resources/block2.png");
            block3 = Image.FromFile("Resources/block3.png");
            block4 = Image.FromFile("Resources/block4.png");
            block5 = Image.FromFile("Resources/block5.png");
            mario = Image.FromFile("Resources/mario.png");

           
        }

        private void LoadTypeObject()
        {
            rdBigEye.AccessibleName = ObjectType.BIGEYETYPE.ToString();
            rdMoveMap.AccessibleName = ObjectType.MOVEMAPTYPE.ToString();
            rdScrewBomber.AccessibleName = ObjectType.SCREW_BOMBER.ToString();
            rdLand1.AccessibleName = ObjectType.LAND1TYPE.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Create quadtree
            Tree = new QuadTree();

            LoadResources();
            LoadTypeObject();
            listContents = new List<ObjectGame>();
            nameObjects = new List<string>();
            controlSelected = pnObjects.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);
            //id = ObjectGame.GetIdFromText(controlSelected.Text.ToString());
            AddpnObjectsControlsClick();
            btCreate.PerformClick();
            ///---------
            foreach (Control c in pnObjects.Controls)
            {
                if (c is RadioButton)
                {
                    c.Click += pnObjects_Controls_Click;
                    nameObjects.Add(c.Text.ToString());
                }
              
            }

            pnGrid.VerticalScroll.Value = pnGrid.VerticalScroll.Maximum;
        }
        private void pbGridMap_Paint(object sender, PaintEventArgs e)
        {
            Font font = new Font(this.Font, FontStyle.Bold);
            Brush brush = new SolidBrush(Color.Red);
            Pen pen = new Pen(Color.Blue);
            Graphics g = e.Graphics;
            g.DrawImage(background, RectGrid);
            #region DrawGrid
            for (int i = 0; i < numWidth; i++)
            {
                g.DrawString(i.ToString(), font, brush, new PointF(size + i * size + size / 2 - 5, (numHeight + 1) * size + size / 2));
                g.DrawLine(pen, new Point(size + i * size, size), new Point(size + i * size, (numHeight + 1) * size));
                if (i == numWidth - 1)//draw final line
                {
                    i++;
                    g.DrawLine(pen, new Point(size + i * size, size), new Point(size + i * size, (numHeight + 1) * size));
                    break;
                }
            }
            for (int i = numHeight; i > 0; --i)
            {
                g.DrawString(i.ToString(), font, brush, new PointF(size / 2, size + (numHeight - i) * size + size / 2));
                g.DrawLine(pen, new Point(size, size + i * size), new Point((numWidth + 1) * size, size + i * size));
                //if (i == numHeight - 1)//draw final line
                //{
                //    i++;
                //    g.DrawLine(pen, new Point(size, size + i * size), new Point((numWidth + 1) * size, size + i * size));
                //    break;
                //}
            }
            #endregion
            ///--------------------
            if (listContents != null)
            {
                foreach (ObjectGame ob in listContents)
                {
                    if (ob != null)
                        ob.Draw(g);
                }
            }
        }
        //-----------pnOjects------------------------------
        void AddpnObjectsControlsClick()
        {
            foreach (Control c in pnObjects.Controls)
            {
                if (c is RadioButton)
                    c.Click += pnObjects_Controls_Click;
                c.MouseEnter += pnObjects_MouseEnter;
            }
        }
        void pnObjects_Controls_Click(object sender, EventArgs e)
        {
            controlSelected = pnObjects.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);
            if (controlSelected.Enabled)
                TypeCurrent = (ObjectType)Enum.Parse(typeof(ObjectType), controlSelected.AccessibleName);

        }
        private void pnObjects_MouseEnter(object sender, EventArgs e)
        {
            pnObjects.Focus();
        }
        //-----event button-----

        public static int GetHeightPb() {
            
            return 1;
        }

        private void btCreate_Click(object sender, EventArgs e)
        {
            pbGridMap.Refresh();
            numWidth = Convert.ToInt32(tbWidth.Text.ToString());
            numHeight = Convert.ToInt32(tbHeight.Text.ToString());
            HeightPictureBox = (numHeight + 2) *size;
            size = Convert.ToInt32(tbSize.Text.ToString());
            RectGrid = new Rectangle(size, size, numWidth * size, numHeight * size);
            Tree.SetSizeQuadTree(RectGrid);
            pbGridMap.SetBounds(0, 0, numWidth * size + 2 * size, numHeight * size + 2 * size);
            pbGridMap.Update();
        }
        private void btCAll_Click(object sender, EventArgs e)
        {

            if (listContents.Count == 0) return;
            DialogResult re = MessageBox.Show("Are you sure?", "Wanning", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (re == DialogResult.OK)
            {
                listContents.Clear();
                pbGridMap.Invalidate();
            }
        }
        private void btFRange_Click(object sender, EventArgs e)
        {
            Form f = new Fill_Range(numHeight, nameObjects);
            f.ShowDialog();
        }
        //------event pbGridMap----------
        private void pbGridMap_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                //ObjectGame ob = new ObjectGame(e.Location, id);
                //int index = IndexObject(ob.Pos);
                //if (index != -1)
                //    listContents.RemoveAt(index);
            }

            else
                if (e.Button == MouseButtons.Left)
                {
                    if (RectGrid.Contains(e.Location))
                    {
                        if (ObjectGame.ListIdJustDeleted.Count > 0)
                        {
                            id = ObjectGame.ListIdJustDeleted.IndexOf(0);
                        }
                        else
                            id = ++ObjectGame.CurrentId;
                        ObjectGame ob = new ObjectGame(e.Location, id, TypeCurrent);
                        if (IndexObject(ob.Pos) == -1)
                            listContents.Add(ob);
                    }
                }
            pbGridMap.Invalidate();
        }

        private void AddObjectsToQuadTree()
        {
            for (int i = 0; i < listContents.Count; i++)
            {
                Tree.AddObject(listContents[i]);
            }
        }

        private void pbGridMap_MouseEnter(object sender, EventArgs e)
        {
            pnGrid.Focus();
        }
        private void btERange_Click(object sender, EventArgs e)
        {

        }
        private void GetId(object sender, EventArgs e)
        {
            foreach (Control c in pnObjects.Controls)
            {
                if (c is RadioButton)
                    if (ObjectGame.GetIdFromText(c.Text.ToString()) == idTemp)
                    {
                        c.Select();
                        break;
                    }
            }
        }
        private void pbGridMap_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            ObjectGame ob;
            ob = listContents.Find(delegate(ObjectGame _ob)
            {
                Rectangle r = new Rectangle(_ob.Pos, new Size(size, size));
                return r.Contains(e.Location);
            });
            if (/*e.Button == MouseButtons.Middle &&*/ ob != null)
            {
                idTemp = ob.Id;
                ContextMenu cm = new ContextMenu();
                var item = new MenuItem("Get Id");
                item.Click += GetId;
                cm.MenuItems.Add(item);
                cm.Show(pbGridMap, e.Location);
            }
        }       
        private int IndexObject(Point p)
        {
            int index = listContents.FindIndex(delegate(ObjectGame ob)
            {
                return (ob.Pos.X == p.X && ob.Pos.Y == p.Y);
              //  return true;
            });
            return index;
        }
        //----------open, save
        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddObjectsToQuadTree();
            Stream myStream;
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "Txt files (*.txt)|*.txt";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = saveFileDialog1.OpenFile()) != null)
                {
                    StreamWriter writer = new StreamWriter(myStream);
                    WriteFile(writer);
                    
                    myStream.Close();
                }
            }
            string str = saveFileDialog1.FileName.Replace(".txt", "Tree.txt");
            StreamWriter wr = new StreamWriter(str);
            Tree.WriteFile(wr);
            wr.Write("<End>");
            wr.Dispose();
            wr.Close();
        }
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "txt files (*.txt)|*.txt";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            StreamReader reader = new StreamReader(myStream);
                            ReadFile(reader);
                            myStream.Close();
                            
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("File map is shit!: " + ex.Message);
                }
            }
           
        }  
        private void WriteFile(StreamWriter writer)
        {
            writer.Write(numWidth * 32 + " ");
            writer.Write(numHeight * 32 + "\n");

            foreach (ObjectGame item in listContents)
            {
                writer.Write(item.Id + " ");
                writer.Write(item.TypeOb.ToString() + " ");
                writer.Write(item.Pos.X + " ");
                writer.Write(item.Pos.Y + " ");
                writer.Write("\n");
            }
            
           
            writer.Write("<End>");
            writer.Dispose();
            writer.Close();
        }
        private void ReadFile(StreamReader reader)
        {
           String strMap = reader.ReadToEnd();
            reader.Dispose();
            reader.Close();
            AddListFromArray(strMap);
        }
        private int[,] CreateArrayFromList() {

            int col =  numWidth;
            int row = numHeight;

            int[,] arr = new int[row, col];
            foreach (ObjectGame ob in listContents)
            {
               arr[(ob.Pos.Y-size)/size,(ob.Pos.X-size)/size] = ob.Id;
            }

            return arr;
        
        }
        private void AddListFromArray(String strMap)
        {
         
            //String[] arrString = strMap.Split(new char[] { ' ', '\t', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            
            //int[] values = new int[arrString.Length];
            //for (int i = 0; i < arrString.Length; i++)
            //{
            //    if (i == 7){continue;}
            //    values[i] = int.Parse(arrString[i]);
            //}
            //width = values[1];
            //height = values[0];
            //time = values[2];
            //level = values[6];
             
            //listContents.Clear();
            //for (int i = 0; i < height; i++)
            //{
            //    for (int j = 0; j < width; j++)
            //    {
            //        int id = values[i * width + j + 8];
            //        if(id==0) continue;
            //        ObjectGame ob = new ObjectGame(new Point(j*size+size, i*size+size),id);
            //        listContents.Add(ob);
            //    }
            //}
            //try
            //{
            //    background = Image.FromFile(arrString[7]);
            //    BgFilePath = arrString[7];
            //}
            //catch (System.Exception ex)
            //{
            //    MessageBox.Show("Find not background: "+ex);
            //}
            //pbGridMap.Invalidate();
            //tbHeight.Text = height.ToString();
            //tbWidth.Text = width.ToString();
            //tbTime.Text = time.ToString();
            //tbLevel.Text = level.ToString();
            //btCreate.PerformClick();
         }
        //---------add range
        public static void AddRange(int from, int to, string name)
        {
            //int id = ObjectGame.GetIdFromText(name);
            //for (int i = from; i < to; i++)
            //{
            //    for (int j = 0; j < _width; j++)
            //    {
            //        ObjectGame ob = new ObjectGame(new Point(j * 50+50, i * 50+50), id);
            //       listContents.Add(ob);
            //    }
            //}
        }
        private void button1_Click(object sender, EventArgs e)
        {
            string FullFilePath = "";
            OpenFileDialog bgOpenFile = new OpenFileDialog();
            bgOpenFile.Filter = "Png files (*.png)|*.png";
            bgOpenFile.FilterIndex = 1;
            bgOpenFile.RestoreDirectory = true;

            if (bgOpenFile.ShowDialog() == DialogResult.OK)
            {
                FullFilePath = bgOpenFile.FileName;
                string[] filePath = FullFilePath.Split('\\');
                int n = filePath.Length;
                BgFilePath = filePath[n - 2] + "\\" + filePath[n - 1];
                background = Image.FromFile(BgFilePath);
                pbGridMap.Invalidate();
            }
        }

     }
}