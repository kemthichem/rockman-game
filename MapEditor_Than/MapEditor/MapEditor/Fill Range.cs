using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class Fill_Range : Form
    {
        public Fill_Range()
        {
            InitializeComponent();
        }
        public Fill_Range(int width, int height, List<String> nameObject): this()
        {
            for (int i = 0; i < height; i++)
            {
                cbRowFrom.Items.Add(i);
                cbRowTo.Items.Add(i);
            }

            cbRowFrom.SelectedIndex = 0;
            cbRowTo.SelectedIndex = 1;

            for (int i = 0; i < width; i++)
            {
                cbColumnFrom.Items.Add(i);
                cbColumnTo.Items.Add(i);
            }
            cbColumnFrom.SelectedIndex = 0;
            cbColumnTo.SelectedIndex = width - 1;

            cbbNameOb.DataSource = nameObject;
            
        }

        public void SetObjectNameSelect(string name)
        {
            cbbNameOb.SelectedItem = name;
        } 

        private void Fill_Range_Load(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {
            int fromR = int.Parse(cbRowFrom.Text.ToString());
            int toR = int.Parse(cbRowTo.Text.ToString());
            int fromC = int.Parse(cbColumnFrom.Text.ToString());
            int toC = int.Parse(cbColumnTo.Text.ToString());
            string text = cbbNameOb.Text.ToString();
            Form1.AddRange(
                fromR, toR, fromC, toC, text);
            this.Close();
        }

    }
}
