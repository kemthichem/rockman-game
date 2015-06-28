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
        Rectangle RectGrid;
        Control controlSelected;
        //------
        private List<String> nameObjects;
        private static List<ObjectGame> listContents;

        //------
        QuadTree Tree;
        Fill_Range f;


        private Image background;

        public Form1()
        {
            InitializeComponent();
        }
        private void LoadResources()
        {
            background = global::MapEditor.Properties.Resources.background1;
        }

        private void LoadTypeObject()
        {
            /*Blocks*/
            rdMoveMap.AccessibleName = ObjectType.MOVEMAP.ToString();
            rdLand1.AccessibleName = ObjectType.LAND1.ToString();
            rdLand2.AccessibleName = ObjectType.LAND2.ToString();
            rdLand1_n.AccessibleName = ObjectType._LAND1.ToString();
            rdLand.AccessibleName = ObjectType.LAND.ToString();
            rdLand_n.AccessibleName = ObjectType.LAND5.ToString();
            rdLandWhite.AccessibleName = ObjectType.LANDWHITE.ToString();
            rdLandWhite_n.AccessibleName = ObjectType.LAND4.ToString();
            rdLandIceberg.AccessibleName = ObjectType.LANDICEBERG.ToString();
            rdLandIceberg_n.AccessibleName = ObjectType.LAND3.ToString();
            rdLadder.AccessibleName = ObjectType.LADDER10.ToString();
            rdLadder5.AccessibleName = ObjectType.LADDER5.ToString();
            rdLadder2.AccessibleName = ObjectType.LADDER2.ToString();
            rdLadder6.AccessibleName = ObjectType.LADDER6.ToString();
            rdLadder7.AccessibleName = ObjectType.LADDER7.ToString();
            rdLadder4.AccessibleName = ObjectType.LADDER4.ToString();

            /*Enemies*/
            rdBeak.AccessibleName = ObjectType.BEAK.ToString();
            rdBeak_r.AccessibleName = ObjectType.BEAK_R.ToString();
            rdOctopus.AccessibleName = ObjectType.OCTOPUS.ToString();
            rdOctopus_v.AccessibleName = ObjectType.OCTOPUS_D.ToString();
            rdBlader.AccessibleName = ObjectType.BLADER.ToString();
            rdMet.AccessibleName = ObjectType.MET.ToString();
            rdFlea.AccessibleName = ObjectType.FLEA.ToString();
            rdSpine.AccessibleName = ObjectType.SPINE.ToString();
            rdBigEye.AccessibleName = ObjectType.BIGEYE.ToString();
            rdScrewBomber.AccessibleName = ObjectType.SCREW_BOMBER.ToString();
            rdScrewBomber_D.AccessibleName = ObjectType.SCREW_BOMBER_D.ToString();

            /*Boss*/
            rdCuman.AccessibleName = ObjectType.CUTMAN.ToString();
            rdGusman.AccessibleName = ObjectType.GUTSMAN.ToString();
            rdIceMan.AccessibleName = ObjectType.ICEMAN.ToString();

            /*Gutsman*/
            rdDa.AccessibleName = ObjectType.BLOCKCAMERA.ToString();
            rdDaynoi.AccessibleName = ObjectType.DAYNOI.ToString();
            rdDuong.AccessibleName = ObjectType.DUONG.ToString();
            rdLoxo.AccessibleName = ObjectType.LOXO.ToString();
            rdMay.AccessibleName = ObjectType.MAY.ToString();
            rdMuiNhon.AccessibleName = ObjectType.MUINHON.ToString();
            rdNen.AccessibleName = ObjectType.NEN.ToString();
            rdNui.AccessibleName = ObjectType.NUI.ToString();
            rdNui1.AccessibleName = ObjectType.NUI1.ToString();
            rdRao.AccessibleName = ObjectType.RAO.ToString();
            rdTuong.AccessibleName = ObjectType.TUONG.ToString();
            rdTuongNho.AccessibleName = ObjectType.TUONGNHO.ToString();
            rdTuongPhai.AccessibleName = ObjectType.TUONGPHAI.ToString();
            rdTuongTrai.AccessibleName = ObjectType.TUONGTRAI.ToString();
            rdTruc.AccessibleName = ObjectType.TRUC.ToString();
            rdTrucTrai.AccessibleName = ObjectType.TRUCTRAI.ToString();
            rdTrucPhai.AccessibleName = ObjectType.TRUCPHAI.ToString();
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

            pbGridMap.Width = numWidth * size + 2 * size;
            pbGridMap.Height = numHeight * size + 2 * size;
            
            pbGridMap.Update();
            pnGrid.VerticalScroll.Value = pnGrid.VerticalScroll.Maximum;
        }
        private void btCAll_Click(object sender, EventArgs e)
        {
            f = null;
            Tree = null;
            Tree = new QuadTree();
            listContents.Clear();
            pbGridMap.Invalidate();
            btCreate.PerformClick();
        }

        //-----------Fill range
        private void btFRange_Click(object sender, EventArgs e)
        {
            if (f == null)
            {
                f = new Fill_Range(numWidth, numHeight, nameObjects);
                f.FormClosed += f_FormClosed;
            }
            f.SetObjectNameSelect(controlSelected.AccessibleName);
            f.ShowDialog();

        }

        void f_FormClosed(object sender, FormClosedEventArgs e)
        {
            pbGridMap.Invalidate();
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
                    listContents.RemoveAt(index);                    
                }
            }

            else
                if (e.Button == MouseButtons.Left)
                {
                    if (RectGrid.Contains(e.Location))
                    {
                        ObjectGame ob = null;
                        Point p = new Point(e.Location.X - 32, e.Location.Y - 32);
                        int index = IndexObject(p);
                        if (index != -1)
                        {
                            ob = listContents[index];
                        }
                        if (ob == null || (ob != null && ob.TypeOb != TypeCurrent))
                        {
                            ObjectGame _ob = new ObjectGame(e.Location, TypeCurrent);
                            listContents.Add(_ob);
                        }
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

            if (listContents.Count == 0) {
                btCAll.PerformClick();
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
                    //Add id to object in list objects
                    for (int i = 0; i < listContents.Count; i++)
                    {
                        listContents[i].SetId(i + 1);
                    }


                    StreamWriter writer = new StreamWriter(myStream);
                    WriteFile(writer);
                    myStream.Close();

                    string str = saveFileDialog1.FileName.Replace(".txt", "Tree.txt");
                    StreamWriter wr = new StreamWriter(str);
                    Tree.WriteFile(wr);
                    wr.Write("<End>");
                    wr.Dispose();
                    wr.Close();
                }
            }
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
            btCAll.PerformClick();
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

                ObjectGame ob = new ObjectGame(new Point(mapX, mapY), typeMap);
                listContents.Add(ob);
            }

            reader.Dispose();
            reader.Close();
            
            pbGridMap.Invalidate();
            tbHeight.Text = numHeight.ToString();
            tbWidth.Text = numWidth.ToString();
            btCreate.PerformClick();
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
            int nextXObject;
            if (toR <= fromR) toR = fromR;
            if (toC <= fromC) toC = fromC + 1;


            for (int i = fromR; i <= toR ; i++)
            {
                nextXObject = 0;
                for (int j = fromC; j < toC && nextXObject < toC * 32; j++)
                {
                    ObjectGame ob = new ObjectGame(new Point(fromC * 32 + (j - fromC) * widthType + 32, (SizeHeightMap - i) * 32 ), _type);
                    listContents.Add(ob);
                    nextXObject = ob.Pos.X + widthType;
                   
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

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
           
        }

        private void pnObjects_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
           
        }

     }
}