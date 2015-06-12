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
        public static int HeightOfMap;
        public static int SizeHeightMap;
        int size;
        int id;
        string textTypeTemp;
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
            BgFilePath = "Resources/background1.png";
            background = Image.FromFile(BgFilePath);
            ScrewImage = Image.FromFile(Application.StartupPath + "\\Resources\\enemy\\enemy_screwbomber.png");
            Land1Image = Image.FromFile(Application.StartupPath + "\\Resources\\ground\\Land1.png");
            MoveMapImage = Image.FromFile(Application.StartupPath + "\\Resources\\item\\movemap.png");
            BigEyeImage = Image.FromFile(Application.StartupPath + "\\Resources\\enemy\\enemy_bigeye.png");
            mush = Image.FromFile(Application.StartupPath + "\\Resources\\mush.png");
            mush1 = Image.FromFile(Application.StartupPath + "\\Resources\\mush1.png");
            mush2 = Image.FromFile(Application.StartupPath + "\\Resources\\mush2.png");
            mushlife = Image.FromFile(Application.StartupPath + "\\Resources\\mushlife.png");
            mushlife1 = Image.FromFile(Application.StartupPath + "\\Resources\\mushlife1.png");
            mushlife2 = Image.FromFile(Application.StartupPath + "\\Resources\\mushlife2.png");
            flag = Image.FromFile(Application.StartupPath + "\\Resources\\flag.png");
            house = Image.FromFile(Application.StartupPath + "\\Resources\\house.png");
            star = Image.FromFile(Application.StartupPath + "\\Resources\\star.png");
            turtle = Image.FromFile(Application.StartupPath + "\\Resources\\turtle.png");
            eato = Image.FromFile(Application.StartupPath + "\\Resources\\eato.png");
            enemy = Image.FromFile(Application.StartupPath + "\\Resources\\enemy.png");
            land1 = Image.FromFile(Application.StartupPath + "\\Resources\\land1.png");
            land2 = Image.FromFile(Application.StartupPath + "\\Resources\\land2.png");
            block1 = Image.FromFile(Application.StartupPath + "\\Resources\\block1.png");
            coin = Image.FromFile(Application.StartupPath + "\\Resources\\coin.png");
            coin1 = Image.FromFile(Application.StartupPath + "\\Resources\\coin1.png");
            coin1c = Image.FromFile(Application.StartupPath + "\\Resources\\coin1c.png");
            coin10c = Image.FromFile(Application.StartupPath + "\\Resources\\coin10c.png");
            bushbig = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\bushbig.png");
            pine = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\pine.png");
            cloud2 = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\cloud2.png");
            sign = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\sign.png");
            ///\\\\  [10\\1\\2013 TheRise]
            castus1 = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\castus1.png");
            tree = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\tree.png");
            bushsmall = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\bushsmall.png");
            crass = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\crass.png");
            bud = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\bud.png");
            cloud1 = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\cloud1.png");
            cloud3 = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\cloud3.png");
            castus2 = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\castus2.png");
            hill = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\hill.png");
            castus3 = Image.FromFile(Application.StartupPath + "\\Resources\\Scenery\\castus3.png");
            block2 = Image.FromFile(Application.StartupPath + "\\Resources\\block2.png");
            block3 = Image.FromFile(Application.StartupPath + "\\Resources\\block3.png");
            block4 = Image.FromFile(Application.StartupPath + "\\Resources\\block4.png");
            block5 = Image.FromFile(Application.StartupPath + "\\Resources\\block5.png");
            mario = Image.FromFile(Application.StartupPath + "\\Resources\\mario.png");

           
        }

        private void LoadTypeObject()
        {
            rdBigEye.AccessibleName = ObjectType.BIGEYE.ToString();
            rdMoveMap.AccessibleName = ObjectType.MOVEMAP.ToString();
            rdScrewBomber.AccessibleName = ObjectType.SCREW_BOMBER.ToString();
            rdLand1.AccessibleName = ObjectType.LAND1.ToString();
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
                    if (c.Enabled)
                    {
                        c.Click += pnObjects_Controls_Click;
                        nameObjects.Add(c.AccessibleName);
                    }
                }
              
            }

            
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
                g.DrawString((i).ToString(), font, brush, new PointF(size + i * size + size / 2 - 5, (numHeight + 1) * size + size / 2));
                g.DrawLine(pen, new Point(size + i * size, size), new Point(size + i * size, (numHeight + 1) * size));
                if (i == numWidth - 1)//draw final line
                {
                    i++;
                    g.DrawLine(pen, new Point(size + i * size, size), new Point(size + i * size, (numHeight + 1) * size));
                    break;
                }
            }
            for (int i = numHeight-1; i >= 0; --i)
            {
                g.DrawString((i).ToString(), font, brush, new PointF(size / 2, (numHeight - i) * size + size / 2));
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
            size = Convert.ToInt32(tbSize.Text.ToString());
            HeightOfMap = (numHeight) * size;
            SizeHeightMap = numHeight;
            RectGrid = new Rectangle(size, size, numWidth * size, numHeight * size);
            Tree.SetSizeQuadTree(RectGrid);
            pbGridMap.SetBounds(0, 0, numWidth * size + 2 * size, numHeight * size + 2 * size);
            pbGridMap.Update();
            pnGrid.VerticalScroll.Value = pnGrid.VerticalScroll.Maximum;
        }
        private void btCAll_Click(object sender, EventArgs e)
        {
            Tree = null;
            Tree = new QuadTree();
            listContents.Clear();
            pbGridMap.Invalidate();
            btCreate.PerformClick();

            ObjectGame.ListIdJustDeleted.Clear();
            ObjectGame.CurrentId = 0;
        }
        private void btFRange_Click(object sender, EventArgs e)
        {
            Form f = new Fill_Range(numWidth, numHeight, nameObjects, controlSelected.AccessibleName);
            f.ShowDialog();
        }
        //------event pbGridMap----------
        private void pbGridMap_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {

                Point p = new Point(e.Location.X - 32, e.Location.Y - 32);
                int index = IndexObject(p);
                if (index != -1)
                {
                    ObjectGame.ListIdJustDeleted.Add(listContents[index].Id);
                    listContents.RemoveAt(index);                    
                }
            }

            else
                if (e.Button == MouseButtons.Left)
                {
                    if (RectGrid.Contains(e.Location))
                    {
                        if (ObjectGame.ListIdJustDeleted.Count > 0)
                        {
                            id = ObjectGame.ListIdJustDeleted[0];
                            ObjectGame.ListIdJustDeleted.RemoveAt(0);
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
       
        private int IndexObject(Point p)
        {
            int index = listContents.FindIndex(delegate(ObjectGame ob)
            {
                return ob.Bound.Contains(p);
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
                writer.Write(item.PosToSave.X + " ");
                writer.Write(item.PosToSave.Y + " ");
                writer.Write("\n");
            }
            
           
            writer.Write("<End>");
            writer.Dispose();
            writer.Close();
        }
        private void ReadFile(StreamReader reader)
        {
            string line;
            String[] arrString;
            line = reader.ReadLine();
            arrString = line.Split(new char[] { ' ', '\t', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

            size = 32;
            numWidth = Int32.Parse(arrString[0]) / size;
            numHeight = Int32.Parse(arrString[1]) / size;
            HeightOfMap = numHeight * size;

            while ((line = reader.ReadLine()) != null && line != "<End>")
            {
                arrString = line.Split(new char[] { ' ', '\t', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
                int mapId = Int32.Parse(arrString[0]);
                string mapTypeStr = arrString[1];
                ObjectType typeMap = (ObjectType)Enum.Parse(typeof(ObjectType), mapTypeStr);
                int mapX = Int32.Parse(arrString[2]) + 32;
                int mapY = HeightOfMap - Int32.Parse(arrString[3]) + size;

                ObjectGame ob = new ObjectGame(new Point(mapX, mapY), mapId, typeMap);
                listContents.Add(ob);
            }

            reader.Dispose();
            reader.Close();
            
            pbGridMap.Invalidate();
            tbHeight.Text = numHeight.ToString();
            tbWidth.Text = numWidth.ToString();
            btCreate.PerformClick();
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
            //    if (i == 7) { continue; }
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
            //        if (id == 0) continue;
            //        ObjectGame ob = new ObjectGame(new Point(j * size + size, i * size + size), id);
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
            //    MessageBox.Show("Find not background: " + ex);
            //}
            //pbGridMap.Invalidate();
            //tbHeight.Text = height.ToString();
            //tbWidth.Text = width.ToString();
            //tbTime.Text = time.ToString();
            //tbLevel.Text = level.ToString();
            //btCreate.PerformClick();
         }
        //---------add range
        public static void AddRange(int fromR, int toR, int fromC, int toC, string name)
        {
            int id; 
            ObjectType _type = (ObjectType)Enum.Parse(typeof(ObjectType), name);

            int widthType = 0;
            int heightType = 0;
            Image image = null;
            ObjectGame.SetKind(_type, false, ref widthType, ref heightType, ref image);
            Point currentPosObject = new Point(0,0);

            for (int i = fromR; i < toR ; i++)
            {
                currentPosObject.X = 0;
                currentPosObject.Y = 0;
                for (int j = fromC; j < toC && currentPosObject.X < toC * 32; j++)
                {
                    if (ObjectGame.ListIdJustDeleted.Count > 0)
                    {
                        id = ObjectGame.ListIdJustDeleted[0];
                        ObjectGame.ListIdJustDeleted.RemoveAt(0);
                    }
                    else
                        id = ++ObjectGame.CurrentId;

                    ObjectGame ob = new ObjectGame(new Point(j * widthType + 32, (SizeHeightMap - i) * 32 ), id, _type);
                    currentPosObject = ob.Pos;
                    listContents.Add(ob);
                }
            }
        }
        private void btBackground_Click(object sender, EventArgs e)
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

        private void pbGridMap_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            ObjectGame ob = listContents.Find(delegate(ObjectGame _ob)
            {
                Point p = new Point(e.Location.X - 32, e.Location.Y - 32);
                return _ob.Bound.Contains(p);
            });

            if (/*e.Button == MouseButtons.Middle &&*/ ob != null)
            {
                textTypeTemp = ob.TypeOb.ToString();
                ContextMenu cm = new ContextMenu();
                var item = new MenuItem("Get Type");
                item.Click += GetId;
                cm.MenuItems.Add(item);
                cm.Show(pbGridMap, e.Location);
            }
        }
        private void GetId(object sender, EventArgs e)
        {
            foreach (Control c in pnObjects.Controls)
            {
                if (c is RadioButton)
                    if (c.AccessibleName == textTypeTemp)
                    {
                        c.Select();
                        break;
                    }
            }
        }
     }
}