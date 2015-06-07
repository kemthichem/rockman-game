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
        public Fill_Range(int height, List<String> nameObject)
            : this()
        {

            for (int i = 0; i < height; i++)
            {
                dmFrom.Items.Add(i);
                dmTo.Items.Add(i);
           }
            cbbNameOb.DataSource = nameObject;     
        }
        private void Fill_Range_Load(object sender, EventArgs e)
        {
           
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int from = int.Parse(dmFrom.Text.ToString());
            int to = int.Parse(dmTo.Text.ToString());
            string text = cbbNameOb.Text.ToString();
            Form1.AddRange(from, to, text);
            this.Close();
        }

    }
}
