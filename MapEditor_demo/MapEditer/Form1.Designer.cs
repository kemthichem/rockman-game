namespace MapEditer
{
    partial class formEditor
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(formEditor));
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tab_1 = new System.Windows.Forms.TabPage();
            this.picBlueMushRoom = new System.Windows.Forms.PictureBox();
            this.picRedMushroom = new System.Windows.Forms.PictureBox();
            this.picGoomla = new System.Windows.Forms.PictureBox();
            this.picMario = new System.Windows.Forms.PictureBox();
            this.tab_2 = new System.Windows.Forms.TabPage();
            this.tab_3 = new System.Windows.Forms.TabPage();
            this.groupBox = new System.Windows.Forms.GroupBox();
            this.tbID = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.tbY = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.picSelected = new System.Windows.Forms.PictureBox();
            this.tbX = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pnBackGround = new System.Windows.Forms.Panel();
            this.pnView = new System.Windows.Forms.Panel();
            this.btSave = new System.Windows.Forms.Button();
            this.btLoad = new System.Windows.Forms.Button();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.btShowGrid = new System.Windows.Forms.Button();
            this.btShowTree = new System.Windows.Forms.Button();
            this.btClear = new System.Windows.Forms.Button();
            this.btSaveTree = new System.Windows.Forms.Button();
            this.tabControl.SuspendLayout();
            this.tab_1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picBlueMushRoom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picRedMushroom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picGoomla)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picMario)).BeginInit();
            this.groupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picSelected)).BeginInit();
            this.pnBackGround.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tab_1);
            this.tabControl.Controls.Add(this.tab_2);
            this.tabControl.Controls.Add(this.tab_3);
            this.tabControl.Dock = System.Windows.Forms.DockStyle.Left;
            this.tabControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabControl.Location = new System.Drawing.Point(0, 0);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(184, 543);
            this.tabControl.TabIndex = 0;
            // 
            // tab_1
            // 
            this.tab_1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.tab_1.Controls.Add(this.picBlueMushRoom);
            this.tab_1.Controls.Add(this.picRedMushroom);
            this.tab_1.Controls.Add(this.picGoomla);
            this.tab_1.Controls.Add(this.picMario);
            this.tab_1.Location = new System.Drawing.Point(4, 25);
            this.tab_1.Name = "tab_1";
            this.tab_1.Padding = new System.Windows.Forms.Padding(3);
            this.tab_1.Size = new System.Drawing.Size(176, 514);
            this.tab_1.TabIndex = 0;
            this.tab_1.Text = "Item1";
            // 
            // picBlueMushRoom
            // 
            this.picBlueMushRoom.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.picBlueMushRoom.Image = global::MapEditer.Properties.Resources.blue_mushroom1;
            this.picBlueMushRoom.Location = new System.Drawing.Point(92, 74);
            this.picBlueMushRoom.Name = "picBlueMushRoom";
            this.picBlueMushRoom.Size = new System.Drawing.Size(80, 65);
            this.picBlueMushRoom.TabIndex = 4;
            this.picBlueMushRoom.TabStop = false;
            this.picBlueMushRoom.Click += new System.EventHandler(this.picBludeMushRoom_Click);
            // 
            // picRedMushroom
            // 
            this.picRedMushroom.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.picRedMushroom.Image = global::MapEditer.Properties.Resources.red_mushroom;
            this.picRedMushroom.Location = new System.Drawing.Point(3, 74);
            this.picRedMushroom.Name = "picRedMushroom";
            this.picRedMushroom.Size = new System.Drawing.Size(80, 65);
            this.picRedMushroom.TabIndex = 3;
            this.picRedMushroom.TabStop = false;
            this.picRedMushroom.Click += new System.EventHandler(this.picRedMushroom_Click);
            // 
            // picGoomla
            // 
            this.picGoomla.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.picGoomla.Image = global::MapEditer.Properties.Resources.goomla;
            this.picGoomla.Location = new System.Drawing.Point(92, 3);
            this.picGoomla.Name = "picGoomla";
            this.picGoomla.Size = new System.Drawing.Size(80, 65);
            this.picGoomla.TabIndex = 2;
            this.picGoomla.TabStop = false;
            this.picGoomla.Click += new System.EventHandler(this.picGoomla_Click);
            // 
            // picMario
            // 
            this.picMario.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.picMario.Image = global::MapEditer.Properties.Resources.mario;
            this.picMario.Location = new System.Drawing.Point(3, 3);
            this.picMario.Name = "picMario";
            this.picMario.Size = new System.Drawing.Size(80, 65);
            this.picMario.TabIndex = 1;
            this.picMario.TabStop = false;
            this.picMario.Click += new System.EventHandler(this.picMario_Click);
            // 
            // tab_2
            // 
            this.tab_2.Location = new System.Drawing.Point(4, 25);
            this.tab_2.Name = "tab_2";
            this.tab_2.Padding = new System.Windows.Forms.Padding(3);
            this.tab_2.Size = new System.Drawing.Size(176, 514);
            this.tab_2.TabIndex = 1;
            this.tab_2.Text = "Item 2";
            this.tab_2.UseVisualStyleBackColor = true;
            // 
            // tab_3
            // 
            this.tab_3.Location = new System.Drawing.Point(4, 25);
            this.tab_3.Name = "tab_3";
            this.tab_3.Padding = new System.Windows.Forms.Padding(3);
            this.tab_3.Size = new System.Drawing.Size(176, 514);
            this.tab_3.TabIndex = 2;
            this.tab_3.Text = "Item 3";
            this.tab_3.UseVisualStyleBackColor = true;
            // 
            // groupBox
            // 
            this.groupBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.groupBox.Controls.Add(this.tbID);
            this.groupBox.Controls.Add(this.label4);
            this.groupBox.Controls.Add(this.tbY);
            this.groupBox.Controls.Add(this.label3);
            this.groupBox.Controls.Add(this.picSelected);
            this.groupBox.Controls.Add(this.tbX);
            this.groupBox.Controls.Add(this.label2);
            this.groupBox.Controls.Add(this.label1);
            this.groupBox.Location = new System.Drawing.Point(186, 99);
            this.groupBox.Name = "groupBox";
            this.groupBox.Size = new System.Drawing.Size(147, 230);
            this.groupBox.TabIndex = 1;
            this.groupBox.TabStop = false;
            // 
            // tbID
            // 
            this.tbID.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbID.Location = new System.Drawing.Point(37, 114);
            this.tbID.Name = "tbID";
            this.tbID.Size = new System.Drawing.Size(103, 22);
            this.tbID.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(6, 117);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(21, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "ID";
            // 
            // tbY
            // 
            this.tbY.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbY.Location = new System.Drawing.Point(37, 197);
            this.tbY.Name = "tbY";
            this.tbY.Size = new System.Drawing.Size(103, 22);
            this.tbY.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(7, 200);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(20, 16);
            this.label3.TabIndex = 4;
            this.label3.Text = "Y:";
            // 
            // picSelected
            // 
            this.picSelected.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.picSelected.Location = new System.Drawing.Point(0, 9);
            this.picSelected.Name = "picSelected";
            this.picSelected.Size = new System.Drawing.Size(147, 68);
            this.picSelected.TabIndex = 0;
            this.picSelected.TabStop = false;
            // 
            // tbX
            // 
            this.tbX.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbX.Location = new System.Drawing.Point(38, 158);
            this.tbX.Name = "tbX";
            this.tbX.Size = new System.Drawing.Size(103, 22);
            this.tbX.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(7, 161);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(19, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "X:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(16, 80);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(103, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Selected image";
            // 
            // pnBackGround
            // 
            this.pnBackGround.AutoScroll = true;
            this.pnBackGround.Controls.Add(this.pnView);
            this.pnBackGround.Location = new System.Drawing.Point(333, 0);
            this.pnBackGround.Name = "pnBackGround";
            this.pnBackGround.Size = new System.Drawing.Size(705, 501);
            this.pnBackGround.TabIndex = 2;
            this.pnBackGround.Scroll += new System.Windows.Forms.ScrollEventHandler(this.pnBackGround_Scroll);
            // 
            // pnView
            // 
            this.pnView.AutoScroll = true;
            this.pnView.AutoSize = true;
            this.pnView.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.pnView.Location = new System.Drawing.Point(0, 0);
            this.pnView.Name = "pnView";
            this.pnView.Size = new System.Drawing.Size(754, 563);
            this.pnView.TabIndex = 0;
            this.pnView.Paint += new System.Windows.Forms.PaintEventHandler(this.pnView_Paint);
            this.pnView.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pnView_MouseDown);
            // 
            // btSave
            // 
            this.btSave.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btSave.Location = new System.Drawing.Point(223, 368);
            this.btSave.Name = "btSave";
            this.btSave.Size = new System.Drawing.Size(82, 27);
            this.btSave.TabIndex = 3;
            this.btSave.Text = "Save map";
            this.btSave.UseVisualStyleBackColor = true;
            this.btSave.Click += new System.EventHandler(this.btSave_Click);
            // 
            // btLoad
            // 
            this.btLoad.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btLoad.Location = new System.Drawing.Point(223, 474);
            this.btLoad.Name = "btLoad";
            this.btLoad.Size = new System.Drawing.Size(82, 27);
            this.btLoad.TabIndex = 4;
            this.btLoad.Text = "Load";
            this.btLoad.UseVisualStyleBackColor = true;
            this.btLoad.Click += new System.EventHandler(this.btLoad_Click);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "map";
            // 
            // btShowGrid
            // 
            this.btShowGrid.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btShowGrid.Location = new System.Drawing.Point(579, 507);
            this.btShowGrid.Name = "btShowGrid";
            this.btShowGrid.Size = new System.Drawing.Size(82, 27);
            this.btShowGrid.TabIndex = 5;
            this.btShowGrid.Text = "Show Grid";
            this.btShowGrid.UseVisualStyleBackColor = true;
            this.btShowGrid.Click += new System.EventHandler(this.btShowGrid_Click);
            // 
            // btShowTree
            // 
            this.btShowTree.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btShowTree.Location = new System.Drawing.Point(688, 507);
            this.btShowTree.Name = "btShowTree";
            this.btShowTree.Size = new System.Drawing.Size(82, 27);
            this.btShowTree.TabIndex = 6;
            this.btShowTree.Text = "Show Tree";
            this.btShowTree.UseVisualStyleBackColor = true;
            this.btShowTree.Click += new System.EventHandler(this.btShowTree_Click);
            // 
            // btClear
            // 
            this.btClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btClear.Location = new System.Drawing.Point(797, 507);
            this.btClear.Name = "btClear";
            this.btClear.Size = new System.Drawing.Size(82, 27);
            this.btClear.TabIndex = 7;
            this.btClear.Text = "Clear";
            this.btClear.UseVisualStyleBackColor = true;
            this.btClear.Click += new System.EventHandler(this.btClear_Click);
            // 
            // btSaveTree
            // 
            this.btSaveTree.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btSaveTree.Location = new System.Drawing.Point(224, 419);
            this.btSaveTree.Name = "btSaveTree";
            this.btSaveTree.Size = new System.Drawing.Size(81, 27);
            this.btSaveTree.TabIndex = 8;
            this.btSaveTree.Text = "SaveTree";
            this.btSaveTree.UseVisualStyleBackColor = true;
            this.btSaveTree.Click += new System.EventHandler(this.btSaveTree_Click);
            // 
            // formEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1038, 543);
            this.Controls.Add(this.btSaveTree);
            this.Controls.Add(this.btClear);
            this.Controls.Add(this.btShowTree);
            this.Controls.Add(this.btShowGrid);
            this.Controls.Add(this.btLoad);
            this.Controls.Add(this.btSave);
            this.Controls.Add(this.pnBackGround);
            this.Controls.Add(this.groupBox);
            this.Controls.Add(this.tabControl);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "formEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Map Editor";
            this.Load += new System.EventHandler(this.formEditor_Load);
            this.tabControl.ResumeLayout(false);
            this.tab_1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picBlueMushRoom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picRedMushroom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picGoomla)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picMario)).EndInit();
            this.groupBox.ResumeLayout(false);
            this.groupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picSelected)).EndInit();
            this.pnBackGround.ResumeLayout(false);
            this.pnBackGround.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tab_1;
        private System.Windows.Forms.TabPage tab_2;
        private System.Windows.Forms.TabPage tab_3;
        private System.Windows.Forms.PictureBox picSelected;
        private System.Windows.Forms.PictureBox picGoomla;
        private System.Windows.Forms.PictureBox picMario;
        private System.Windows.Forms.GroupBox groupBox;
        private System.Windows.Forms.PictureBox picBlueMushRoom;
        private System.Windows.Forms.PictureBox picRedMushroom;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbY;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbX;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tbID;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel pnBackGround;
        private System.Windows.Forms.Panel pnView;
        private System.Windows.Forms.Button btSave;
        private System.Windows.Forms.Button btLoad;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.Button btShowGrid;
        private System.Windows.Forms.Button btShowTree;
        private System.Windows.Forms.Button btClear;
        private System.Windows.Forms.Button btSaveTree;
    }
}

