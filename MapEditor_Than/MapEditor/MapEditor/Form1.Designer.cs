﻿namespace MapEditor
{
    partial class Form1
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pnGrid = new System.Windows.Forms.Panel();
            this.pbGridMap = new System.Windows.Forms.PictureBox();
            this.paButton = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.tbSize = new System.Windows.Forms.TextBox();
            this.Size = new System.Windows.Forms.Label();
            this.btCAll = new System.Windows.Forms.Button();
            this.btFRange = new System.Windows.Forms.Button();
            this.btCreate = new System.Windows.Forms.Button();
            this.tbWidth = new System.Windows.Forms.TextBox();
            this.tbHeight = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pnObjects = new System.Windows.Forms.Panel();
            this.rdScrewBomber_D = new System.Windows.Forms.RadioButton();
            this.rdScrewBomber = new System.Windows.Forms.RadioButton();
            this.rdBeak_r = new System.Windows.Forms.RadioButton();
            this.rdBlader = new System.Windows.Forms.RadioButton();
            this.rdOctopus_v = new System.Windows.Forms.RadioButton();
            this.rdOctopus = new System.Windows.Forms.RadioButton();
            this.rdMet = new System.Windows.Forms.RadioButton();
            this.rdLandIceberg_n = new System.Windows.Forms.RadioButton();
            this.rdLand_n = new System.Windows.Forms.RadioButton();
            this.rdLandWhite_n = new System.Windows.Forms.RadioButton();
            this.rdGusman = new System.Windows.Forms.RadioButton();
            this.rdCuman = new System.Windows.Forms.RadioButton();
            this.rdFlea = new System.Windows.Forms.RadioButton();
            this.rdBeak = new System.Windows.Forms.RadioButton();
            this.rdMoveMap = new System.Windows.Forms.RadioButton();
            this.rdLand1 = new System.Windows.Forms.RadioButton();
            this.rdLandIceberg = new System.Windows.Forms.RadioButton();
            this.rdLandWhite = new System.Windows.Forms.RadioButton();
            this.rdLand = new System.Windows.Forms.RadioButton();
            this.rdIceMan = new System.Windows.Forms.RadioButton();
            this.rdSpine = new System.Windows.Forms.RadioButton();
            this.rdLand1_n = new System.Windows.Forms.RadioButton();
            this.rdBigEye = new System.Windows.Forms.RadioButton();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.bgOpenFile = new System.Windows.Forms.OpenFileDialog();
            this.rdLadder5 = new System.Windows.Forms.RadioButton();
            this.rdLadder = new System.Windows.Forms.RadioButton();
            this.menuStrip1.SuspendLayout();
            this.pnGrid.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbGridMap)).BeginInit();
            this.paButton.SuspendLayout();
            this.pnObjects.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(827, 24);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.saveToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.openToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // pnGrid
            // 
            this.pnGrid.AutoScroll = true;
            this.pnGrid.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.pnGrid.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnGrid.Controls.Add(this.pbGridMap);
            this.pnGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnGrid.Location = new System.Drawing.Point(0, 0);
            this.pnGrid.Name = "pnGrid";
            this.pnGrid.Size = new System.Drawing.Size(421, 494);
            this.pnGrid.TabIndex = 0;
            // 
            // pbGridMap
            // 
            this.pbGridMap.BackColor = System.Drawing.SystemColors.ControlLight;
            this.pbGridMap.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbGridMap.Location = new System.Drawing.Point(0, 0);
            this.pbGridMap.Name = "pbGridMap";
            this.pbGridMap.Size = new System.Drawing.Size(318, 198);
            this.pbGridMap.TabIndex = 4;
            this.pbGridMap.TabStop = false;
            this.pbGridMap.Paint += new System.Windows.Forms.PaintEventHandler(this.pbGridMap_Paint);
            this.pbGridMap.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.pbGridMap_MouseDoubleClick);
            this.pbGridMap.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pbGridMap_MouseMove);
            this.pbGridMap.MouseEnter += new System.EventHandler(this.pbGridMap_MouseEnter);
            // 
            // paButton
            // 
            this.paButton.AutoScroll = true;
            this.paButton.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.paButton.Controls.Add(this.button1);
            this.paButton.Controls.Add(this.tbSize);
            this.paButton.Controls.Add(this.Size);
            this.paButton.Controls.Add(this.btCAll);
            this.paButton.Controls.Add(this.btFRange);
            this.paButton.Controls.Add(this.btCreate);
            this.paButton.Controls.Add(this.tbWidth);
            this.paButton.Controls.Add(this.tbHeight);
            this.paButton.Controls.Add(this.label3);
            this.paButton.Controls.Add(this.label1);
            this.paButton.Dock = System.Windows.Forms.DockStyle.Right;
            this.paButton.Location = new System.Drawing.Point(252, 0);
            this.paButton.Name = "paButton";
            this.paButton.Size = new System.Drawing.Size(146, 494);
            this.paButton.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(32, 380);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(78, 25);
            this.button1.TabIndex = 19;
            this.button1.Text = "Background";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.btBackground_Click);
            // 
            // tbSize
            // 
            this.tbSize.Enabled = false;
            this.tbSize.Location = new System.Drawing.Point(56, 95);
            this.tbSize.Name = "tbSize";
            this.tbSize.Size = new System.Drawing.Size(72, 20);
            this.tbSize.TabIndex = 18;
            this.tbSize.Text = "32";
            // 
            // Size
            // 
            this.Size.AutoSize = true;
            this.Size.Location = new System.Drawing.Point(13, 98);
            this.Size.Name = "Size";
            this.Size.Size = new System.Drawing.Size(28, 14);
            this.Size.TabIndex = 17;
            this.Size.Text = "Size";
            // 
            // btCAll
            // 
            this.btCAll.AutoSize = true;
            this.btCAll.Location = new System.Drawing.Point(32, 278);
            this.btCAll.Name = "btCAll";
            this.btCAll.Size = new System.Drawing.Size(74, 26);
            this.btCAll.TabIndex = 16;
            this.btCAll.Text = "Clear all";
            this.btCAll.UseVisualStyleBackColor = true;
            this.btCAll.Click += new System.EventHandler(this.btCAll_Click);
            // 
            // btFRange
            // 
            this.btFRange.AutoSize = true;
            this.btFRange.Location = new System.Drawing.Point(37, 221);
            this.btFRange.Name = "btFRange";
            this.btFRange.Size = new System.Drawing.Size(64, 26);
            this.btFRange.TabIndex = 14;
            this.btFRange.Text = "Fill range";
            this.btFRange.UseVisualStyleBackColor = true;
            this.btFRange.Click += new System.EventHandler(this.btFRange_Click);
            // 
            // btCreate
            // 
            this.btCreate.Location = new System.Drawing.Point(41, 167);
            this.btCreate.Name = "btCreate";
            this.btCreate.Size = new System.Drawing.Size(56, 25);
            this.btCreate.TabIndex = 13;
            this.btCreate.Text = "Create";
            this.btCreate.UseVisualStyleBackColor = true;
            this.btCreate.Click += new System.EventHandler(this.btCreate_Click);
            // 
            // tbWidth
            // 
            this.tbWidth.Location = new System.Drawing.Point(56, 20);
            this.tbWidth.Name = "tbWidth";
            this.tbWidth.Size = new System.Drawing.Size(72, 20);
            this.tbWidth.TabIndex = 0;
            this.tbWidth.Text = "128";
            // 
            // tbHeight
            // 
            this.tbHeight.Location = new System.Drawing.Point(56, 55);
            this.tbHeight.Name = "tbHeight";
            this.tbHeight.Size = new System.Drawing.Size(72, 20);
            this.tbHeight.TabIndex = 11;
            this.tbHeight.Text = "32";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 58);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 14);
            this.label3.TabIndex = 10;
            this.label3.Text = "Height";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 14);
            this.label1.TabIndex = 9;
            this.label1.Text = "Width";
            // 
            // pnObjects
            // 
            this.pnObjects.AutoScroll = true;
            this.pnObjects.Controls.Add(this.rdLadder);
            this.pnObjects.Controls.Add(this.rdLadder5);
            this.pnObjects.Controls.Add(this.rdScrewBomber_D);
            this.pnObjects.Controls.Add(this.rdScrewBomber);
            this.pnObjects.Controls.Add(this.rdBeak_r);
            this.pnObjects.Controls.Add(this.rdBlader);
            this.pnObjects.Controls.Add(this.rdOctopus_v);
            this.pnObjects.Controls.Add(this.rdOctopus);
            this.pnObjects.Controls.Add(this.rdMet);
            this.pnObjects.Controls.Add(this.rdLandIceberg_n);
            this.pnObjects.Controls.Add(this.rdLand_n);
            this.pnObjects.Controls.Add(this.rdLandWhite_n);
            this.pnObjects.Controls.Add(this.rdGusman);
            this.pnObjects.Controls.Add(this.rdCuman);
            this.pnObjects.Controls.Add(this.rdFlea);
            this.pnObjects.Controls.Add(this.rdBeak);
            this.pnObjects.Controls.Add(this.rdMoveMap);
            this.pnObjects.Controls.Add(this.rdLand1);
            this.pnObjects.Controls.Add(this.rdLandIceberg);
            this.pnObjects.Controls.Add(this.rdLandWhite);
            this.pnObjects.Controls.Add(this.rdLand);
            this.pnObjects.Controls.Add(this.rdIceMan);
            this.pnObjects.Controls.Add(this.rdSpine);
            this.pnObjects.Controls.Add(this.rdLand1_n);
            this.pnObjects.Controls.Add(this.rdBigEye);
            this.pnObjects.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnObjects.Location = new System.Drawing.Point(0, 0);
            this.pnObjects.Name = "pnObjects";
            this.pnObjects.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.pnObjects.Size = new System.Drawing.Size(252, 494);
            this.pnObjects.TabIndex = 1;
            this.pnObjects.MouseEnter += new System.EventHandler(this.pnObjects_MouseEnter);
            // 
            // rdScrewBomber_D
            // 
            this.rdScrewBomber_D.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdScrewBomber_D.FlatAppearance.BorderSize = 0;
            this.rdScrewBomber_D.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdScrewBomber_D.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdScrewBomber_D.Image = global::MapEditor.Properties.Resources.enemy_screwbomber__down;
            this.rdScrewBomber_D.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdScrewBomber_D.Location = new System.Drawing.Point(124, 1144);
            this.rdScrewBomber_D.Name = "rdScrewBomber_D";
            this.rdScrewBomber_D.Size = new System.Drawing.Size(95, 106);
            this.rdScrewBomber_D.TabIndex = 75;
            this.rdScrewBomber_D.Text = "Screw Bomber (down)";
            this.rdScrewBomber_D.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdScrewBomber_D.UseVisualStyleBackColor = true;
            // 
            // rdScrewBomber
            // 
            this.rdScrewBomber.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdScrewBomber.FlatAppearance.BorderSize = 0;
            this.rdScrewBomber.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdScrewBomber.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdScrewBomber.Image = global::MapEditor.Properties.Resources.enemy_screwbomber;
            this.rdScrewBomber.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdScrewBomber.Location = new System.Drawing.Point(11, 1143);
            this.rdScrewBomber.Name = "rdScrewBomber";
            this.rdScrewBomber.Size = new System.Drawing.Size(95, 106);
            this.rdScrewBomber.TabIndex = 73;
            this.rdScrewBomber.Text = "Screw Bomber";
            this.rdScrewBomber.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdScrewBomber.UseVisualStyleBackColor = true;
            // 
            // rdBeak_r
            // 
            this.rdBeak_r.AccessibleName = "_LAND1";
            this.rdBeak_r.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdBeak_r.FlatAppearance.BorderSize = 0;
            this.rdBeak_r.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdBeak_r.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdBeak_r.Image = global::MapEditor.Properties.Resources.enemy_break__right;
            this.rdBeak_r.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdBeak_r.Location = new System.Drawing.Point(128, 204);
            this.rdBeak_r.Name = "rdBeak_r";
            this.rdBeak_r.Size = new System.Drawing.Size(95, 100);
            this.rdBeak_r.TabIndex = 72;
            this.rdBeak_r.Text = "Beak (right)";
            this.rdBeak_r.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdBeak_r.UseVisualStyleBackColor = true;
            // 
            // rdBlader
            // 
            this.rdBlader.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdBlader.FlatAppearance.BorderSize = 0;
            this.rdBlader.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdBlader.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdBlader.Image = global::MapEditor.Properties.Resources.enemy_blader;
            this.rdBlader.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdBlader.Location = new System.Drawing.Point(128, 4);
            this.rdBlader.Name = "rdBlader";
            this.rdBlader.Size = new System.Drawing.Size(95, 93);
            this.rdBlader.TabIndex = 71;
            this.rdBlader.Text = "Blader";
            this.rdBlader.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdBlader.UseVisualStyleBackColor = true;
            // 
            // rdOctopus_v
            // 
            this.rdOctopus_v.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdOctopus_v.FlatAppearance.BorderSize = 0;
            this.rdOctopus_v.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdOctopus_v.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdOctopus_v.Image = global::MapEditor.Properties.Resources.octopus_up;
            this.rdOctopus_v.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdOctopus_v.Location = new System.Drawing.Point(124, 1031);
            this.rdOctopus_v.Name = "rdOctopus_v";
            this.rdOctopus_v.Size = new System.Drawing.Size(95, 95);
            this.rdOctopus_v.TabIndex = 70;
            this.rdOctopus_v.Text = "Octopus (vertical)";
            this.rdOctopus_v.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdOctopus_v.UseVisualStyleBackColor = true;
            // 
            // rdOctopus
            // 
            this.rdOctopus.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdOctopus.FlatAppearance.BorderSize = 0;
            this.rdOctopus.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdOctopus.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdOctopus.Image = global::MapEditor.Properties.Resources.octopus_left;
            this.rdOctopus.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdOctopus.Location = new System.Drawing.Point(-2, 1031);
            this.rdOctopus.Name = "rdOctopus";
            this.rdOctopus.Size = new System.Drawing.Size(95, 96);
            this.rdOctopus.TabIndex = 68;
            this.rdOctopus.Text = "Octopus";
            this.rdOctopus.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdOctopus.UseVisualStyleBackColor = true;
            // 
            // rdMet
            // 
            this.rdMet.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdMet.FlatAppearance.BorderSize = 0;
            this.rdMet.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdMet.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdMet.Image = global::MapEditor.Properties.Resources.enemy_met;
            this.rdMet.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdMet.Location = new System.Drawing.Point(14, 307);
            this.rdMet.Name = "rdMet";
            this.rdMet.Size = new System.Drawing.Size(95, 99);
            this.rdMet.TabIndex = 66;
            this.rdMet.Text = "Met";
            this.rdMet.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdMet.UseVisualStyleBackColor = true;
            // 
            // rdLandIceberg_n
            // 
            this.rdLandIceberg_n.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLandIceberg_n.FlatAppearance.BorderSize = 0;
            this.rdLandIceberg_n.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLandIceberg_n.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLandIceberg_n.Image = global::MapEditor.Properties.Resources.LandIceberg;
            this.rdLandIceberg_n.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLandIceberg_n.Location = new System.Drawing.Point(128, 824);
            this.rdLandIceberg_n.Name = "rdLandIceberg_n";
            this.rdLandIceberg_n.Size = new System.Drawing.Size(95, 95);
            this.rdLandIceberg_n.TabIndex = 54;
            this.rdLandIceberg_n.Text = "Land Iceberg (Not collision)";
            this.rdLandIceberg_n.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLandIceberg_n.UseVisualStyleBackColor = true;
            // 
            // rdLand_n
            // 
            this.rdLand_n.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLand_n.FlatAppearance.BorderSize = 0;
            this.rdLand_n.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLand_n.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLand_n.Image = global::MapEditor.Properties.Resources.land;
            this.rdLand_n.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLand_n.Location = new System.Drawing.Point(128, 620);
            this.rdLand_n.Name = "rdLand_n";
            this.rdLand_n.Size = new System.Drawing.Size(95, 95);
            this.rdLand_n.TabIndex = 52;
            this.rdLand_n.Text = "Land (not collision)";
            this.rdLand_n.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLand_n.UseVisualStyleBackColor = true;
            // 
            // rdLandWhite_n
            // 
            this.rdLandWhite_n.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLandWhite_n.FlatAppearance.BorderSize = 0;
            this.rdLandWhite_n.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLandWhite_n.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLandWhite_n.Image = global::MapEditor.Properties.Resources.landwhite;
            this.rdLandWhite_n.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLandWhite_n.Location = new System.Drawing.Point(128, 734);
            this.rdLandWhite_n.Name = "rdLandWhite_n";
            this.rdLandWhite_n.Size = new System.Drawing.Size(95, 83);
            this.rdLandWhite_n.TabIndex = 53;
            this.rdLandWhite_n.Text = "Land white(not collsion)";
            this.rdLandWhite_n.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLandWhite_n.UseVisualStyleBackColor = true;
            // 
            // rdGusman
            // 
            this.rdGusman.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdGusman.FlatAppearance.BorderSize = 0;
            this.rdGusman.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdGusman.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdGusman.Image = global::MapEditor.Properties.Resources.gutsman;
            this.rdGusman.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdGusman.Location = new System.Drawing.Point(128, 514);
            this.rdGusman.Name = "rdGusman";
            this.rdGusman.Size = new System.Drawing.Size(95, 99);
            this.rdGusman.TabIndex = 42;
            this.rdGusman.Text = "Guts man";
            this.rdGusman.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdGusman.UseVisualStyleBackColor = true;
            // 
            // rdCuman
            // 
            this.rdCuman.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdCuman.FlatAppearance.BorderSize = 0;
            this.rdCuman.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdCuman.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdCuman.Image = global::MapEditor.Properties.Resources.cutman;
            this.rdCuman.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdCuman.Location = new System.Drawing.Point(128, 408);
            this.rdCuman.Name = "rdCuman";
            this.rdCuman.Size = new System.Drawing.Size(95, 99);
            this.rdCuman.TabIndex = 41;
            this.rdCuman.Text = "CutMan";
            this.rdCuman.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdCuman.UseVisualStyleBackColor = true;
            // 
            // rdFlea
            // 
            this.rdFlea.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdFlea.FlatAppearance.BorderSize = 0;
            this.rdFlea.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdFlea.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdFlea.Image = global::MapEditor.Properties.Resources.enemy_flea;
            this.rdFlea.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdFlea.Location = new System.Drawing.Point(128, 307);
            this.rdFlea.Name = "rdFlea";
            this.rdFlea.Size = new System.Drawing.Size(95, 99);
            this.rdFlea.TabIndex = 40;
            this.rdFlea.Text = "Flea";
            this.rdFlea.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdFlea.UseVisualStyleBackColor = true;
            // 
            // rdBeak
            // 
            this.rdBeak.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdBeak.FlatAppearance.BorderSize = 0;
            this.rdBeak.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdBeak.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdBeak.Image = global::MapEditor.Properties.Resources.break_left;
            this.rdBeak.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdBeak.Location = new System.Drawing.Point(14, 205);
            this.rdBeak.Name = "rdBeak";
            this.rdBeak.Size = new System.Drawing.Size(95, 99);
            this.rdBeak.TabIndex = 39;
            this.rdBeak.Text = "Beak";
            this.rdBeak.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdBeak.UseVisualStyleBackColor = true;
            // 
            // rdMoveMap
            // 
            this.rdMoveMap.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdMoveMap.FlatAppearance.BorderSize = 0;
            this.rdMoveMap.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdMoveMap.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdMoveMap.Image = global::MapEditor.Properties.Resources.movemap;
            this.rdMoveMap.Location = new System.Drawing.Point(128, 98);
            this.rdMoveMap.Name = "rdMoveMap";
            this.rdMoveMap.Size = new System.Drawing.Size(95, 99);
            this.rdMoveMap.TabIndex = 38;
            this.rdMoveMap.Text = "Move map";
            this.rdMoveMap.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdMoveMap.UseVisualStyleBackColor = true;
            // 
            // rdLand1
            // 
            this.rdLand1.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLand1.FlatAppearance.BorderSize = 0;
            this.rdLand1.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLand1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLand1.Image = global::MapEditor.Properties.Resources.land1;
            this.rdLand1.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLand1.Location = new System.Drawing.Point(2, 929);
            this.rdLand1.Name = "rdLand1";
            this.rdLand1.Size = new System.Drawing.Size(95, 99);
            this.rdLand1.TabIndex = 37;
            this.rdLand1.Text = "Land 1";
            this.rdLand1.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLand1.UseVisualStyleBackColor = true;
            // 
            // rdLandIceberg
            // 
            this.rdLandIceberg.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLandIceberg.FlatAppearance.BorderSize = 0;
            this.rdLandIceberg.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLandIceberg.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLandIceberg.Image = global::MapEditor.Properties.Resources.LandIceberg;
            this.rdLandIceberg.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLandIceberg.Location = new System.Drawing.Point(2, 824);
            this.rdLandIceberg.Name = "rdLandIceberg";
            this.rdLandIceberg.Size = new System.Drawing.Size(95, 96);
            this.rdLandIceberg.TabIndex = 22;
            this.rdLandIceberg.Text = "LandIceberg";
            this.rdLandIceberg.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLandIceberg.UseVisualStyleBackColor = true;
            // 
            // rdLandWhite
            // 
            this.rdLandWhite.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLandWhite.FlatAppearance.BorderSize = 0;
            this.rdLandWhite.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLandWhite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLandWhite.Image = global::MapEditor.Properties.Resources.landwhite;
            this.rdLandWhite.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLandWhite.Location = new System.Drawing.Point(2, 728);
            this.rdLandWhite.Name = "rdLandWhite";
            this.rdLandWhite.Size = new System.Drawing.Size(95, 96);
            this.rdLandWhite.TabIndex = 21;
            this.rdLandWhite.Text = "Land White";
            this.rdLandWhite.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLandWhite.UseVisualStyleBackColor = true;
            // 
            // rdLand
            // 
            this.rdLand.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLand.Checked = true;
            this.rdLand.FlatAppearance.BorderSize = 0;
            this.rdLand.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLand.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLand.Image = global::MapEditor.Properties.Resources.land;
            this.rdLand.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLand.Location = new System.Drawing.Point(2, 619);
            this.rdLand.Name = "rdLand";
            this.rdLand.Size = new System.Drawing.Size(95, 96);
            this.rdLand.TabIndex = 20;
            this.rdLand.TabStop = true;
            this.rdLand.Text = "Land";
            this.rdLand.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLand.UseVisualStyleBackColor = true;
            // 
            // rdIceMan
            // 
            this.rdIceMan.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdIceMan.FlatAppearance.BorderSize = 0;
            this.rdIceMan.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdIceMan.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdIceMan.Image = global::MapEditor.Properties.Resources.iceman;
            this.rdIceMan.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdIceMan.Location = new System.Drawing.Point(2, 513);
            this.rdIceMan.Name = "rdIceMan";
            this.rdIceMan.Size = new System.Drawing.Size(95, 100);
            this.rdIceMan.TabIndex = 19;
            this.rdIceMan.Text = "iceman";
            this.rdIceMan.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdIceMan.UseVisualStyleBackColor = true;
            // 
            // rdSpine
            // 
            this.rdSpine.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdSpine.FlatAppearance.BorderSize = 0;
            this.rdSpine.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdSpine.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdSpine.Image = global::MapEditor.Properties.Resources.enemy_spine;
            this.rdSpine.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdSpine.Location = new System.Drawing.Point(2, 410);
            this.rdSpine.Name = "rdSpine";
            this.rdSpine.Size = new System.Drawing.Size(95, 100);
            this.rdSpine.TabIndex = 7;
            this.rdSpine.Text = "Spine";
            this.rdSpine.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdSpine.UseVisualStyleBackColor = true;
            // 
            // rdLand1_n
            // 
            this.rdLand1_n.AccessibleName = "_LAND1";
            this.rdLand1_n.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLand1_n.FlatAppearance.BorderSize = 0;
            this.rdLand1_n.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLand1_n.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLand1_n.Image = global::MapEditor.Properties.Resources.land1;
            this.rdLand1_n.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLand1_n.Location = new System.Drawing.Point(124, 929);
            this.rdLand1_n.Name = "rdLand1_n";
            this.rdLand1_n.Size = new System.Drawing.Size(95, 100);
            this.rdLand1_n.TabIndex = 6;
            this.rdLand1_n.Text = "Land1(Not collision)";
            this.rdLand1_n.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLand1_n.UseVisualStyleBackColor = true;
            // 
            // rdBigEye
            // 
            this.rdBigEye.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdBigEye.FlatAppearance.BorderSize = 0;
            this.rdBigEye.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdBigEye.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdBigEye.Image = global::MapEditor.Properties.Resources.enemy_bigeye;
            this.rdBigEye.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdBigEye.Location = new System.Drawing.Point(2, 3);
            this.rdBigEye.Name = "rdBigEye";
            this.rdBigEye.Size = new System.Drawing.Size(95, 93);
            this.rdBigEye.TabIndex = 4;
            this.rdBigEye.Text = "BigEye";
            this.rdBigEye.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdBigEye.UseVisualStyleBackColor = true;
            // 
            // splitContainer1
            // 
            this.splitContainer1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 24);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.pnObjects);
            this.splitContainer1.Panel1.Controls.Add(this.paButton);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.pnGrid);
            this.splitContainer1.Size = new System.Drawing.Size(827, 496);
            this.splitContainer1.SplitterDistance = 400;
            this.splitContainer1.TabIndex = 4;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // bgOpenFile
            // 
            this.bgOpenFile.FileName = "bgOpenFile";
            // 
            // rdLadder5
            // 
            this.rdLadder5.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLadder5.FlatAppearance.BorderSize = 0;
            this.rdLadder5.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLadder5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLadder5.Image = global::MapEditor.Properties.Resources.ladder;
            this.rdLadder5.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLadder5.Location = new System.Drawing.Point(124, 1264);
            this.rdLadder5.Name = "rdLadder5";
            this.rdLadder5.Size = new System.Drawing.Size(95, 106);
            this.rdLadder5.TabIndex = 76;
            this.rdLadder5.Text = "Ladder 5";
            this.rdLadder5.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLadder5.UseVisualStyleBackColor = true;
            this.rdLadder5.CheckedChanged += new System.EventHandler(this.rdLadder5_CheckedChanged);
            // 
            // rdLadder
            // 
            this.rdLadder.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdLadder.FlatAppearance.BorderSize = 0;
            this.rdLadder.FlatAppearance.CheckedBackColor = System.Drawing.SystemColors.Highlight;
            this.rdLadder.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdLadder.Image = global::MapEditor.Properties.Resources.ladder;
            this.rdLadder.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.rdLadder.Location = new System.Drawing.Point(11, 1264);
            this.rdLadder.Name = "rdLadder";
            this.rdLadder.Size = new System.Drawing.Size(95, 99);
            this.rdLadder.TabIndex = 77;
            this.rdLadder.Text = "Ladder";
            this.rdLadder.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.rdLadder.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(827, 520);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.menuStrip1);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MapEditor";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.pnGrid.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbGridMap)).EndInit();
            this.paButton.ResumeLayout(false);
            this.paButton.PerformLayout();
            this.pnObjects.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.Panel pnGrid;
        private System.Windows.Forms.PictureBox pbGridMap;
        private System.Windows.Forms.Panel paButton;
        private System.Windows.Forms.Button btCAll;
        private System.Windows.Forms.Button btFRange;
        private System.Windows.Forms.Button btCreate;
        private System.Windows.Forms.TextBox tbWidth;
        private System.Windows.Forms.TextBox tbHeight;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel pnObjects;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TextBox tbSize;
        private System.Windows.Forms.Label Size;
        private System.Windows.Forms.RadioButton rdLand1_n;
        private System.Windows.Forms.RadioButton rdBigEye;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.RadioButton rdSpine;
        private System.Windows.Forms.RadioButton rdLand;
        private System.Windows.Forms.RadioButton rdIceMan;
        private System.Windows.Forms.RadioButton rdLandIceberg;
        private System.Windows.Forms.RadioButton rdLandWhite;
        private System.Windows.Forms.RadioButton rdGusman;
        private System.Windows.Forms.RadioButton rdCuman;
        private System.Windows.Forms.RadioButton rdFlea;
        private System.Windows.Forms.RadioButton rdBeak;
        private System.Windows.Forms.RadioButton rdMoveMap;
        private System.Windows.Forms.RadioButton rdLand1;
        private System.Windows.Forms.RadioButton rdLandIceberg_n;
        private System.Windows.Forms.RadioButton rdLand_n;
        private System.Windows.Forms.RadioButton rdLandWhite_n;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.OpenFileDialog bgOpenFile;
        private System.Windows.Forms.RadioButton rdMet;
        private System.Windows.Forms.RadioButton rdOctopus_v;
        private System.Windows.Forms.RadioButton rdOctopus;
        private System.Windows.Forms.RadioButton rdBlader;
        private System.Windows.Forms.RadioButton rdBeak_r;
        private System.Windows.Forms.RadioButton rdScrewBomber_D;
        private System.Windows.Forms.RadioButton rdScrewBomber;
        private System.Windows.Forms.RadioButton rdLadder5;
        private System.Windows.Forms.RadioButton rdLadder;
    }
}

