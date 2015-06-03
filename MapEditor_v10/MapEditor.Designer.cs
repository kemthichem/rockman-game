namespace MapEditor_v10
{
    partial class MapEditor
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
            this.menuGame = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveTreeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.PnContain = new System.Windows.Forms.Panel();
            this.ptbContain = new System.Windows.Forms.PictureBox();
            this.TabBackGround = new System.Windows.Forms.TabControl();
            this.BackGround = new System.Windows.Forms.TabPage();
            this.btWatcher = new System.Windows.Forms.Button();
            this.btTacklefire = new System.Windows.Forms.Button();
            this.btSupercutter = new System.Windows.Forms.Button();
            this.btSpine = new System.Windows.Forms.Button();
            this.btSniperjoe = new System.Windows.Forms.Button();
            this.btScrewbomber = new System.Windows.Forms.Button();
            this.btPicketman = new System.Windows.Forms.Button();
            this.btPeng = new System.Windows.Forms.Button();
            this.btOctopusbattery = new System.Windows.Forms.Button();
            this.btMet = new System.Windows.Forms.Button();
            this.btKillerbullet = new System.Windows.Forms.Button();
            this.btFootholder = new System.Windows.Forms.Button();
            this.btFlyingshell = new System.Windows.Forms.Button();
            this.btFlea = new System.Windows.Forms.Button();
            this.btCrazyrazy = new System.Windows.Forms.Button();
            this.btBreak = new System.Windows.Forms.Button();
            this.btBomb = new System.Windows.Forms.Button();
            this.btBlader = new System.Windows.Forms.Button();
            this.btBigeye = new System.Windows.Forms.Button();
            this.ObjectGame = new System.Windows.Forms.TabPage();
            this.btGroundTrap = new System.Windows.Forms.Button();
            this.btGroundhiddenbrick = new System.Windows.Forms.Button();
            this.btGroundBrick = new System.Windows.Forms.Button();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.DrawRect = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.btLand = new System.Windows.Forms.Button();
            this.btLand1 = new System.Windows.Forms.Button();
            this.btLandWhite = new System.Windows.Forms.Button();
            this.btLadder = new System.Windows.Forms.Button();
            this.menuGame.SuspendLayout();
            this.PnContain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptbContain)).BeginInit();
            this.TabBackGround.SuspendLayout();
            this.BackGround.SuspendLayout();
            this.ObjectGame.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuGame
            // 
            this.menuGame.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuGame.Location = new System.Drawing.Point(0, 0);
            this.menuGame.Name = "menuGame";
            this.menuGame.Size = new System.Drawing.Size(1029, 24);
            this.menuGame.TabIndex = 3;
            this.menuGame.Text = "menuGame";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.loadToolStripMenuItem,
            this.saveTreeToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(120, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(120, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(120, 22);
            this.loadToolStripMenuItem.Text = "Load";
            this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
            // 
            // saveTreeToolStripMenuItem
            // 
            this.saveTreeToolStripMenuItem.Name = "saveTreeToolStripMenuItem";
            this.saveTreeToolStripMenuItem.Size = new System.Drawing.Size(120, 22);
            this.saveTreeToolStripMenuItem.Text = "SaveTree";
            // 
            // PnContain
            // 
            this.PnContain.AutoScroll = true;
            this.PnContain.Controls.Add(this.ptbContain);
            this.PnContain.Location = new System.Drawing.Point(12, 38);
            this.PnContain.Name = "PnContain";
            this.PnContain.Size = new System.Drawing.Size(1005, 318);
            this.PnContain.TabIndex = 4;
            // 
            // ptbContain
            // 
            this.ptbContain.BackColor = System.Drawing.Color.White;
            this.ptbContain.Location = new System.Drawing.Point(0, 0);
            this.ptbContain.Name = "ptbContain";
            this.ptbContain.Size = new System.Drawing.Size(15003, 2000);
            this.ptbContain.TabIndex = 0;
            this.ptbContain.TabStop = false;
            this.ptbContain.Click += new System.EventHandler(this.ptbContain_Click);
            this.ptbContain.Paint += new System.Windows.Forms.PaintEventHandler(this.ptbContain_Paint);
            this.ptbContain.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ptbContain_MouseDown);
            this.ptbContain.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ptbContain_MouseMove);
            this.ptbContain.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ptbContain_MouseUp);
            // 
            // TabBackGround
            // 
            this.TabBackGround.Controls.Add(this.BackGround);
            this.TabBackGround.Controls.Add(this.ObjectGame);
            this.TabBackGround.Controls.Add(this.tabPage1);
            this.TabBackGround.Location = new System.Drawing.Point(12, 365);
            this.TabBackGround.Name = "TabBackGround";
            this.TabBackGround.SelectedIndex = 0;
            this.TabBackGround.Size = new System.Drawing.Size(675, 157);
            this.TabBackGround.TabIndex = 6;
            this.TabBackGround.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TabBackGround_KeyDown);
            // 
            // BackGround
            // 
            this.BackGround.BackColor = System.Drawing.Color.Silver;
            this.BackGround.Controls.Add(this.btWatcher);
            this.BackGround.Controls.Add(this.btTacklefire);
            this.BackGround.Controls.Add(this.btSupercutter);
            this.BackGround.Controls.Add(this.btSpine);
            this.BackGround.Controls.Add(this.btSniperjoe);
            this.BackGround.Controls.Add(this.btScrewbomber);
            this.BackGround.Controls.Add(this.btPicketman);
            this.BackGround.Controls.Add(this.btPeng);
            this.BackGround.Controls.Add(this.btOctopusbattery);
            this.BackGround.Controls.Add(this.btMet);
            this.BackGround.Controls.Add(this.btKillerbullet);
            this.BackGround.Controls.Add(this.btFootholder);
            this.BackGround.Controls.Add(this.btFlyingshell);
            this.BackGround.Controls.Add(this.btFlea);
            this.BackGround.Controls.Add(this.btCrazyrazy);
            this.BackGround.Controls.Add(this.btBreak);
            this.BackGround.Controls.Add(this.btBomb);
            this.BackGround.Controls.Add(this.btBlader);
            this.BackGround.Controls.Add(this.btBigeye);
            this.BackGround.Location = new System.Drawing.Point(4, 22);
            this.BackGround.Name = "BackGround";
            this.BackGround.Padding = new System.Windows.Forms.Padding(3);
            this.BackGround.Size = new System.Drawing.Size(667, 131);
            this.BackGround.TabIndex = 0;
            this.BackGround.Text = "Enemy";
            // 
            // btWatcher
            // 
            this.btWatcher.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btWatcher.BackgroundImage")));
            this.btWatcher.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btWatcher.Location = new System.Drawing.Point(426, 66);
            this.btWatcher.Name = "btWatcher";
            this.btWatcher.Size = new System.Drawing.Size(54, 54);
            this.btWatcher.TabIndex = 6;
            this.btWatcher.UseVisualStyleBackColor = true;
            this.btWatcher.Click += new System.EventHandler(this.btWatcher_Click);
            // 
            // btTacklefire
            // 
            this.btTacklefire.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btTacklefire.BackgroundImage")));
            this.btTacklefire.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btTacklefire.Location = new System.Drawing.Point(366, 66);
            this.btTacklefire.Name = "btTacklefire";
            this.btTacklefire.Size = new System.Drawing.Size(54, 54);
            this.btTacklefire.TabIndex = 6;
            this.btTacklefire.UseVisualStyleBackColor = true;
            this.btTacklefire.Click += new System.EventHandler(this.btTacklefire_Click);
            // 
            // btSupercutter
            // 
            this.btSupercutter.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btSupercutter.BackgroundImage")));
            this.btSupercutter.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btSupercutter.Location = new System.Drawing.Point(306, 66);
            this.btSupercutter.Name = "btSupercutter";
            this.btSupercutter.Size = new System.Drawing.Size(54, 54);
            this.btSupercutter.TabIndex = 6;
            this.btSupercutter.UseVisualStyleBackColor = true;
            this.btSupercutter.Click += new System.EventHandler(this.btSupercutter_Click);
            // 
            // btSpine
            // 
            this.btSpine.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btSpine.BackgroundImage")));
            this.btSpine.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btSpine.Location = new System.Drawing.Point(246, 66);
            this.btSpine.Name = "btSpine";
            this.btSpine.Size = new System.Drawing.Size(54, 54);
            this.btSpine.TabIndex = 6;
            this.btSpine.UseVisualStyleBackColor = true;
            this.btSpine.Click += new System.EventHandler(this.btSpine_Click);
            // 
            // btSniperjoe
            // 
            this.btSniperjoe.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btSniperjoe.BackgroundImage")));
            this.btSniperjoe.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btSniperjoe.Location = new System.Drawing.Point(186, 66);
            this.btSniperjoe.Name = "btSniperjoe";
            this.btSniperjoe.Size = new System.Drawing.Size(54, 54);
            this.btSniperjoe.TabIndex = 6;
            this.btSniperjoe.UseVisualStyleBackColor = true;
            this.btSniperjoe.Click += new System.EventHandler(this.btSniperjoe_Click);
            // 
            // btScrewbomber
            // 
            this.btScrewbomber.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btScrewbomber.BackgroundImage")));
            this.btScrewbomber.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btScrewbomber.Location = new System.Drawing.Point(126, 66);
            this.btScrewbomber.Name = "btScrewbomber";
            this.btScrewbomber.Size = new System.Drawing.Size(54, 54);
            this.btScrewbomber.TabIndex = 6;
            this.btScrewbomber.UseVisualStyleBackColor = true;
            this.btScrewbomber.Click += new System.EventHandler(this.btScrewbomber_Click);
            // 
            // btPicketman
            // 
            this.btPicketman.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btPicketman.BackgroundImage")));
            this.btPicketman.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btPicketman.Location = new System.Drawing.Point(66, 66);
            this.btPicketman.Name = "btPicketman";
            this.btPicketman.Size = new System.Drawing.Size(54, 54);
            this.btPicketman.TabIndex = 6;
            this.btPicketman.UseVisualStyleBackColor = true;
            this.btPicketman.Click += new System.EventHandler(this.btPicketman_Click);
            // 
            // btPeng
            // 
            this.btPeng.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btPeng.BackgroundImage")));
            this.btPeng.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btPeng.Location = new System.Drawing.Point(6, 66);
            this.btPeng.Name = "btPeng";
            this.btPeng.Size = new System.Drawing.Size(54, 54);
            this.btPeng.TabIndex = 6;
            this.btPeng.UseVisualStyleBackColor = true;
            this.btPeng.Click += new System.EventHandler(this.btPeng_Click);
            // 
            // btOctopusbattery
            // 
            this.btOctopusbattery.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btOctopusbattery.BackgroundImage")));
            this.btOctopusbattery.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btOctopusbattery.Location = new System.Drawing.Point(606, 6);
            this.btOctopusbattery.Name = "btOctopusbattery";
            this.btOctopusbattery.Size = new System.Drawing.Size(54, 54);
            this.btOctopusbattery.TabIndex = 6;
            this.btOctopusbattery.UseVisualStyleBackColor = true;
            this.btOctopusbattery.Click += new System.EventHandler(this.btOctopusbattery_Click);
            // 
            // btMet
            // 
            this.btMet.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btMet.BackgroundImage")));
            this.btMet.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btMet.Location = new System.Drawing.Point(546, 6);
            this.btMet.Name = "btMet";
            this.btMet.Size = new System.Drawing.Size(54, 54);
            this.btMet.TabIndex = 6;
            this.btMet.UseVisualStyleBackColor = true;
            this.btMet.Click += new System.EventHandler(this.btMet_Click);
            // 
            // btKillerbullet
            // 
            this.btKillerbullet.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btKillerbullet.BackgroundImage")));
            this.btKillerbullet.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btKillerbullet.Location = new System.Drawing.Point(486, 6);
            this.btKillerbullet.Name = "btKillerbullet";
            this.btKillerbullet.Size = new System.Drawing.Size(54, 54);
            this.btKillerbullet.TabIndex = 6;
            this.btKillerbullet.UseVisualStyleBackColor = true;
            this.btKillerbullet.Click += new System.EventHandler(this.btKillerbullet_Click);
            // 
            // btFootholder
            // 
            this.btFootholder.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btFootholder.BackgroundImage")));
            this.btFootholder.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btFootholder.Location = new System.Drawing.Point(426, 6);
            this.btFootholder.Name = "btFootholder";
            this.btFootholder.Size = new System.Drawing.Size(54, 54);
            this.btFootholder.TabIndex = 6;
            this.btFootholder.UseVisualStyleBackColor = true;
            this.btFootholder.Click += new System.EventHandler(this.btFootholder_Click);
            // 
            // btFlyingshell
            // 
            this.btFlyingshell.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btFlyingshell.BackgroundImage")));
            this.btFlyingshell.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btFlyingshell.Location = new System.Drawing.Point(366, 6);
            this.btFlyingshell.Name = "btFlyingshell";
            this.btFlyingshell.Size = new System.Drawing.Size(54, 54);
            this.btFlyingshell.TabIndex = 6;
            this.btFlyingshell.UseVisualStyleBackColor = true;
            this.btFlyingshell.Click += new System.EventHandler(this.btFlyingshell_Click);
            // 
            // btFlea
            // 
            this.btFlea.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btFlea.BackgroundImage")));
            this.btFlea.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btFlea.Location = new System.Drawing.Point(306, 6);
            this.btFlea.Name = "btFlea";
            this.btFlea.Size = new System.Drawing.Size(54, 54);
            this.btFlea.TabIndex = 6;
            this.btFlea.UseVisualStyleBackColor = true;
            this.btFlea.Click += new System.EventHandler(this.btFlea_Click);
            // 
            // btCrazyrazy
            // 
            this.btCrazyrazy.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btCrazyrazy.BackgroundImage")));
            this.btCrazyrazy.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btCrazyrazy.Location = new System.Drawing.Point(246, 6);
            this.btCrazyrazy.Name = "btCrazyrazy";
            this.btCrazyrazy.Size = new System.Drawing.Size(54, 54);
            this.btCrazyrazy.TabIndex = 6;
            this.btCrazyrazy.UseVisualStyleBackColor = true;
            this.btCrazyrazy.Click += new System.EventHandler(this.btCrazyrazy_Click);
            // 
            // btBreak
            // 
            this.btBreak.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btBreak.BackgroundImage")));
            this.btBreak.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btBreak.Location = new System.Drawing.Point(186, 6);
            this.btBreak.Name = "btBreak";
            this.btBreak.Size = new System.Drawing.Size(54, 54);
            this.btBreak.TabIndex = 6;
            this.btBreak.UseVisualStyleBackColor = true;
            this.btBreak.Click += new System.EventHandler(this.btBreak_Click);
            // 
            // btBomb
            // 
            this.btBomb.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btBomb.BackgroundImage")));
            this.btBomb.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btBomb.Location = new System.Drawing.Point(126, 6);
            this.btBomb.Name = "btBomb";
            this.btBomb.Size = new System.Drawing.Size(54, 54);
            this.btBomb.TabIndex = 6;
            this.btBomb.UseVisualStyleBackColor = true;
            this.btBomb.Click += new System.EventHandler(this.btBomb_Click);
            // 
            // btBlader
            // 
            this.btBlader.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btBlader.BackgroundImage")));
            this.btBlader.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btBlader.Location = new System.Drawing.Point(66, 6);
            this.btBlader.Name = "btBlader";
            this.btBlader.Size = new System.Drawing.Size(54, 54);
            this.btBlader.TabIndex = 6;
            this.btBlader.UseVisualStyleBackColor = true;
            this.btBlader.Click += new System.EventHandler(this.btBlader_Click);
            // 
            // btBigeye
            // 
            this.btBigeye.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btBigeye.BackgroundImage")));
            this.btBigeye.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btBigeye.Location = new System.Drawing.Point(6, 6);
            this.btBigeye.Name = "btBigeye";
            this.btBigeye.Size = new System.Drawing.Size(54, 54);
            this.btBigeye.TabIndex = 6;
            this.btBigeye.UseVisualStyleBackColor = true;
            this.btBigeye.Click += new System.EventHandler(this.btBigeye_Click);
            // 
            // ObjectGame
            // 
            this.ObjectGame.BackColor = System.Drawing.Color.Silver;
            this.ObjectGame.Controls.Add(this.btLadder);
            this.ObjectGame.Controls.Add(this.btLandWhite);
            this.ObjectGame.Controls.Add(this.btLand1);
            this.ObjectGame.Controls.Add(this.btLand);
            this.ObjectGame.Controls.Add(this.btGroundTrap);
            this.ObjectGame.Controls.Add(this.btGroundhiddenbrick);
            this.ObjectGame.Controls.Add(this.btGroundBrick);
            this.ObjectGame.Location = new System.Drawing.Point(4, 22);
            this.ObjectGame.Name = "ObjectGame";
            this.ObjectGame.Padding = new System.Windows.Forms.Padding(3);
            this.ObjectGame.Size = new System.Drawing.Size(667, 131);
            this.ObjectGame.TabIndex = 1;
            this.ObjectGame.Text = "Ground";
            // 
            // btGroundTrap
            // 
            this.btGroundTrap.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btGroundTrap.BackgroundImage")));
            this.btGroundTrap.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btGroundTrap.Location = new System.Drawing.Point(126, 8);
            this.btGroundTrap.Name = "btGroundTrap";
            this.btGroundTrap.Size = new System.Drawing.Size(54, 54);
            this.btGroundTrap.TabIndex = 0;
            this.btGroundTrap.UseVisualStyleBackColor = true;
            this.btGroundTrap.Click += new System.EventHandler(this.btGroundTrap_Click);
            // 
            // btGroundhiddenbrick
            // 
            this.btGroundhiddenbrick.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btGroundhiddenbrick.BackgroundImage")));
            this.btGroundhiddenbrick.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btGroundhiddenbrick.Location = new System.Drawing.Point(66, 8);
            this.btGroundhiddenbrick.Name = "btGroundhiddenbrick";
            this.btGroundhiddenbrick.Size = new System.Drawing.Size(54, 54);
            this.btGroundhiddenbrick.TabIndex = 0;
            this.btGroundhiddenbrick.UseVisualStyleBackColor = true;
            this.btGroundhiddenbrick.Click += new System.EventHandler(this.btGroundhiddenbrick_Click);
            // 
            // btGroundBrick
            // 
            this.btGroundBrick.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btGroundBrick.BackgroundImage")));
            this.btGroundBrick.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btGroundBrick.Location = new System.Drawing.Point(6, 8);
            this.btGroundBrick.Name = "btGroundBrick";
            this.btGroundBrick.Size = new System.Drawing.Size(54, 54);
            this.btGroundBrick.TabIndex = 0;
            this.btGroundBrick.UseVisualStyleBackColor = true;
            this.btGroundBrick.Click += new System.EventHandler(this.btGroundBrick_Click);
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.Silver;
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(667, 131);
            this.tabPage1.TabIndex = 2;
            this.tabPage1.Text = "ObjectGame";
            // 
            // DrawRect
            // 
            this.DrawRect.Location = new System.Drawing.Point(693, 387);
            this.DrawRect.Name = "DrawRect";
            this.DrawRect.Size = new System.Drawing.Size(82, 23);
            this.DrawRect.TabIndex = 7;
            this.DrawRect.Text = "Draw Rectangle";
            this.DrawRect.UseVisualStyleBackColor = true;
            this.DrawRect.Click += new System.EventHandler(this.DrawRect_Click);
            this.DrawRect.KeyDown += new System.Windows.Forms.KeyEventHandler(this.DrawRect_KeyDown);
            // 
            // button11
            // 
            this.button11.Location = new System.Drawing.Point(693, 416);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(82, 23);
            this.button11.TabIndex = 8;
            this.button11.Text = "View Tree";
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.button11_Click);
            this.button11.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button11_KeyDown);
            // 
            // btLand
            // 
            this.btLand.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btLand.BackgroundImage")));
            this.btLand.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btLand.Location = new System.Drawing.Point(186, 8);
            this.btLand.Name = "btLand";
            this.btLand.Size = new System.Drawing.Size(54, 54);
            this.btLand.TabIndex = 0;
            this.btLand.UseVisualStyleBackColor = true;
            this.btLand.Click += new System.EventHandler(this.btLand_Click);
            // 
            // btLand1
            // 
            this.btLand1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btLand1.BackgroundImage")));
            this.btLand1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btLand1.Location = new System.Drawing.Point(246, 8);
            this.btLand1.Name = "btLand1";
            this.btLand1.Size = new System.Drawing.Size(54, 54);
            this.btLand1.TabIndex = 0;
            this.btLand1.UseVisualStyleBackColor = true;
            this.btLand1.Click += new System.EventHandler(this.btLand1_Click);
            // 
            // btLandWhite
            // 
            this.btLandWhite.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btLandWhite.BackgroundImage")));
            this.btLandWhite.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btLandWhite.Location = new System.Drawing.Point(306, 8);
            this.btLandWhite.Name = "btLandWhite";
            this.btLandWhite.Size = new System.Drawing.Size(54, 54);
            this.btLandWhite.TabIndex = 0;
            this.btLandWhite.UseVisualStyleBackColor = true;
            this.btLandWhite.Click += new System.EventHandler(this.btLandWhite_Click);
            // 
            // btLadder
            // 
            this.btLadder.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btLadder.BackgroundImage")));
            this.btLadder.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btLadder.Location = new System.Drawing.Point(366, 8);
            this.btLadder.Name = "btLadder";
            this.btLadder.Size = new System.Drawing.Size(54, 54);
            this.btLadder.TabIndex = 0;
            this.btLadder.UseVisualStyleBackColor = true;
            this.btLadder.Click += new System.EventHandler(this.btLadder_Click);
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1029, 529);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.DrawRect);
            this.Controls.Add(this.TabBackGround);
            this.Controls.Add(this.PnContain);
            this.Controls.Add(this.menuGame);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuGame;
            this.MaximizeBox = false;
            this.Name = "MapEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Map_Editor";
            this.Load += new System.EventHandler(this.MapEditor_Load);
            this.menuGame.ResumeLayout(false);
            this.menuGame.PerformLayout();
            this.PnContain.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ptbContain)).EndInit();
            this.TabBackGround.ResumeLayout(false);
            this.BackGround.ResumeLayout(false);
            this.ObjectGame.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuGame;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.Panel PnContain;
        private System.Windows.Forms.PictureBox ptbContain;
        private System.Windows.Forms.TabControl TabBackGround;
        private System.Windows.Forms.TabPage ObjectGame;
        private System.Windows.Forms.TabPage BackGround;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveTreeToolStripMenuItem;
        private System.Windows.Forms.Button DrawRect;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button btBigeye;
        private System.Windows.Forms.Button btFlea;
        private System.Windows.Forms.Button btCrazyrazy;
        private System.Windows.Forms.Button btBreak;
        private System.Windows.Forms.Button btBomb;
        private System.Windows.Forms.Button btBlader;
        private System.Windows.Forms.Button btOctopusbattery;
        private System.Windows.Forms.Button btMet;
        private System.Windows.Forms.Button btKillerbullet;
        private System.Windows.Forms.Button btFootholder;
        private System.Windows.Forms.Button btFlyingshell;
        private System.Windows.Forms.Button btWatcher;
        private System.Windows.Forms.Button btTacklefire;
        private System.Windows.Forms.Button btSupercutter;
        private System.Windows.Forms.Button btSpine;
        private System.Windows.Forms.Button btSniperjoe;
        private System.Windows.Forms.Button btScrewbomber;
        private System.Windows.Forms.Button btPicketman;
        private System.Windows.Forms.Button btPeng;
        private System.Windows.Forms.Button btGroundBrick;
        private System.Windows.Forms.Button btGroundTrap;
        private System.Windows.Forms.Button btGroundhiddenbrick;
        private System.Windows.Forms.Button btLadder;
        private System.Windows.Forms.Button btLandWhite;
        private System.Windows.Forms.Button btLand1;
        private System.Windows.Forms.Button btLand;
    }
}

