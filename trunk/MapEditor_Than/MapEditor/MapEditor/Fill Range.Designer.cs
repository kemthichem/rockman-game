namespace MapEditor
{
    partial class Fill_Range
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.cbbNameOb = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.cbRowFrom = new System.Windows.Forms.ComboBox();
            this.cbRowTo = new System.Windows.Forms.ComboBox();
            this.cbColumnFrom = new System.Windows.Forms.ComboBox();
            this.cbColumnTo = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Row";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 113);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(38, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Object";
            // 
            // cbbNameOb
            // 
            this.cbbNameOb.FormattingEnabled = true;
            this.cbbNameOb.Location = new System.Drawing.Point(82, 110);
            this.cbbNameOb.Name = "cbbNameOb";
            this.cbbNameOb.Size = new System.Drawing.Size(121, 21);
            this.cbbNameOb.TabIndex = 5;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(82, 155);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 6;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 73);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(42, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Column";
            // 
            // cbRowFrom
            // 
            this.cbRowFrom.FormattingEnabled = true;
            this.cbRowFrom.Location = new System.Drawing.Point(80, 25);
            this.cbRowFrom.Name = "cbRowFrom";
            this.cbRowFrom.Size = new System.Drawing.Size(64, 21);
            this.cbRowFrom.TabIndex = 9;
            // 
            // cbRowTo
            // 
            this.cbRowTo.FormattingEnabled = true;
            this.cbRowTo.Location = new System.Drawing.Point(172, 25);
            this.cbRowTo.Name = "cbRowTo";
            this.cbRowTo.Size = new System.Drawing.Size(64, 21);
            this.cbRowTo.TabIndex = 10;
            // 
            // cbColumnFrom
            // 
            this.cbColumnFrom.FormattingEnabled = true;
            this.cbColumnFrom.Location = new System.Drawing.Point(80, 69);
            this.cbColumnFrom.Name = "cbColumnFrom";
            this.cbColumnFrom.Size = new System.Drawing.Size(64, 21);
            this.cbColumnFrom.TabIndex = 11;
            // 
            // cbColumnTo
            // 
            this.cbColumnTo.FormattingEnabled = true;
            this.cbColumnTo.Location = new System.Drawing.Point(172, 69);
            this.cbColumnTo.Name = "cbColumnTo";
            this.cbColumnTo.Size = new System.Drawing.Size(64, 21);
            this.cbColumnTo.TabIndex = 12;
            // 
            // Fill_Range
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(277, 231);
            this.Controls.Add(this.cbColumnTo);
            this.Controls.Add(this.cbColumnFrom);
            this.Controls.Add(this.cbRowTo);
            this.Controls.Add(this.cbRowFrom);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.cbbNameOb);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Fill_Range";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Fill_Range";
            this.Load += new System.EventHandler(this.Fill_Range_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cbbNameOb;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbRowFrom;
        private System.Windows.Forms.ComboBox cbRowTo;
        private System.Windows.Forms.ComboBox cbColumnFrom;
        private System.Windows.Forms.ComboBox cbColumnTo;
    }
}