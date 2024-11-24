namespace BFS_Graph_App
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
            this.lblEdges = new System.Windows.Forms.Label();
            this.txtEdges = new System.Windows.Forms.TextBox();
            this.lstEdges = new System.Windows.Forms.ListBox();
            this.btnAddEdge = new System.Windows.Forms.Button();
            this.btnBFS = new System.Windows.Forms.Button();
            this.txtStartVertex = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.rtbResult = new System.Windows.Forms.RichTextBox();
            this.txtEdgeU = new System.Windows.Forms.TextBox();
            this.txtEdgeV = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label9 = new System.Windows.Forms.Label();
            this.cleardata = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.txtoutput = new System.Windows.Forms.TextBox();
            this.button4 = new System.Windows.Forms.Button();
            this.checkEmpty = new System.Windows.Forms.Button();
            this.pop = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.txtinput = new System.Windows.Forms.TextBox();
            this.lstQueue = new System.Windows.Forms.ListBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblEdges
            // 
            this.lblEdges.AutoSize = true;
            this.lblEdges.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lblEdges.Location = new System.Drawing.Point(41, 95);
            this.lblEdges.Name = "lblEdges";
            this.lblEdges.Size = new System.Drawing.Size(155, 29);
            this.lblEdges.TabIndex = 2;
            this.lblEdges.Text = "nhập số cạnh";
            this.lblEdges.Click += new System.EventHandler(this.lblEdges_Click);
            // 
            // txtEdges
            // 
            this.txtEdges.BackColor = System.Drawing.Color.WhiteSmoke;
            this.txtEdges.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txtEdges.Location = new System.Drawing.Point(276, 92);
            this.txtEdges.Name = "txtEdges";
            this.txtEdges.Size = new System.Drawing.Size(136, 34);
            this.txtEdges.TabIndex = 1;
            this.txtEdges.TextChanged += new System.EventHandler(this.txtEdges_TextChanged);
            // 
            // lstEdges
            // 
            this.lstEdges.BackColor = System.Drawing.Color.WhiteSmoke;
            this.lstEdges.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lstEdges.FormattingEnabled = true;
            this.lstEdges.HorizontalScrollbar = true;
            this.lstEdges.ItemHeight = 29;
            this.lstEdges.Location = new System.Drawing.Point(475, 162);
            this.lstEdges.Name = "lstEdges";
            this.lstEdges.Size = new System.Drawing.Size(156, 410);
            this.lstEdges.TabIndex = 14;
            this.lstEdges.SelectedIndexChanged += new System.EventHandler(this.lstEdges_SelectedIndexChanged);
            // 
            // btnAddEdge
            // 
            this.btnAddEdge.AutoSize = true;
            this.btnAddEdge.BackColor = System.Drawing.Color.LightSlateGray;
            this.btnAddEdge.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btnAddEdge.ForeColor = System.Drawing.Color.Black;
            this.btnAddEdge.Location = new System.Drawing.Point(34, 401);
            this.btnAddEdge.Name = "btnAddEdge";
            this.btnAddEdge.Size = new System.Drawing.Size(147, 75);
            this.btnAddEdge.TabIndex = 5;
            this.btnAddEdge.Text = "Thêm cạnh";
            this.btnAddEdge.UseVisualStyleBackColor = false;
            this.btnAddEdge.Click += new System.EventHandler(this.btnAddEdge_Click);
            // 
            // btnBFS
            // 
            this.btnBFS.AutoSize = true;
            this.btnBFS.BackColor = System.Drawing.Color.LightSlateGray;
            this.btnBFS.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btnBFS.Location = new System.Drawing.Point(221, 401);
            this.btnBFS.Name = "btnBFS";
            this.btnBFS.Size = new System.Drawing.Size(143, 75);
            this.btnBFS.TabIndex = 6;
            this.btnBFS.Text = "Duyệt BFS";
            this.btnBFS.UseVisualStyleBackColor = false;
            this.btnBFS.Click += new System.EventHandler(this.btnBFS_Click);
            // 
            // txtStartVertex
            // 
            this.txtStartVertex.BackColor = System.Drawing.Color.WhiteSmoke;
            this.txtStartVertex.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txtStartVertex.Location = new System.Drawing.Point(276, 299);
            this.txtStartVertex.Name = "txtStartVertex";
            this.txtStartVertex.Size = new System.Drawing.Size(136, 34);
            this.txtStartVertex.TabIndex = 4;
            this.txtStartVertex.TextChanged += new System.EventHandler(this.txtStartVertex_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label1.Location = new System.Drawing.Point(19, 302);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(208, 29);
            this.label1.TabIndex = 8;
            this.label1.Text = "Nhập đỉnh bắt đầu";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // rtbResult
            // 
            this.rtbResult.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.rtbResult.BackColor = System.Drawing.Color.WhiteSmoke;
            this.rtbResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.rtbResult.Location = new System.Drawing.Point(672, 162);
            this.rtbResult.Name = "rtbResult";
            this.rtbResult.ReadOnly = true;
            this.rtbResult.Size = new System.Drawing.Size(161, 410);
            this.rtbResult.TabIndex = 9;
            this.rtbResult.Text = "";
            this.rtbResult.TextChanged += new System.EventHandler(this.rtbResult_TextChanged);
            // 
            // txtEdgeU
            // 
            this.txtEdgeU.BackColor = System.Drawing.Color.WhiteSmoke;
            this.txtEdgeU.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txtEdgeU.Location = new System.Drawing.Point(276, 152);
            this.txtEdgeU.Name = "txtEdgeU";
            this.txtEdgeU.Size = new System.Drawing.Size(136, 34);
            this.txtEdgeU.TabIndex = 2;
            this.txtEdgeU.TextChanged += new System.EventHandler(this.txtEdgeU_TextChanged);
            // 
            // txtEdgeV
            // 
            this.txtEdgeV.BackColor = System.Drawing.Color.WhiteSmoke;
            this.txtEdgeV.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txtEdgeV.Location = new System.Drawing.Point(276, 227);
            this.txtEdgeV.Name = "txtEdgeV";
            this.txtEdgeV.Size = new System.Drawing.Size(136, 34);
            this.txtEdgeV.TabIndex = 3;
            this.txtEdgeV.TextChanged += new System.EventHandler(this.txtEdgeV_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label2.Location = new System.Drawing.Point(63, 155);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(85, 29);
            this.label2.TabIndex = 12;
            this.label2.Text = "nhập u";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(65, 230);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 29);
            this.label3.TabIndex = 13;
            this.label3.Text = "nhập v";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(0, -2);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(873, 647);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.LightBlue;
            this.tabPage1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.tabPage1.Controls.Add(this.label9);
            this.tabPage1.Controls.Add(this.cleardata);
            this.tabPage1.Controls.Add(this.label5);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.btnAddEdge);
            this.tabPage1.Controls.Add(this.txtStartVertex);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.txtEdgeV);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.btnBFS);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.txtEdgeU);
            this.tabPage1.Controls.Add(this.lstEdges);
            this.tabPage1.Controls.Add(this.rtbResult);
            this.tabPage1.Controls.Add(this.lblEdges);
            this.tabPage1.Controls.Add(this.txtEdges);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(865, 618);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "BFS";
            this.tabPage1.Click += new System.EventHandler(this.tabPage1_Click);
            // 
            // label9
            // 
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label9.Location = new System.Drawing.Point(270, 3);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(319, 61);
            this.label9.TabIndex = 17;
            this.label9.Text = "Minh họa BFS";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // cleardata
            // 
            this.cleardata.BackColor = System.Drawing.Color.LightSlateGray;
            this.cleardata.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.cleardata.ForeColor = System.Drawing.Color.Black;
            this.cleardata.Location = new System.Drawing.Point(137, 493);
            this.cleardata.Name = "cleardata";
            this.cleardata.Size = new System.Drawing.Size(143, 75);
            this.cleardata.TabIndex = 16;
            this.cleardata.Text = "Xóa tất cả dữ liệu";
            this.cleardata.UseVisualStyleBackColor = false;
            this.cleardata.Click += new System.EventHandler(this.cleardata_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label5.Location = new System.Drawing.Point(684, 95);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(101, 29);
            this.label5.TabIndex = 15;
            this.label5.Text = "Kết quả:";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label4
            // 
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label4.Location = new System.Drawing.Point(470, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(143, 81);
            this.label4.TabIndex = 14;
            this.label4.Text = "Danh sách các cạnh:";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.LightBlue;
            this.tabPage2.Controls.Add(this.label8);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.txtoutput);
            this.tabPage2.Controls.Add(this.button4);
            this.tabPage2.Controls.Add(this.checkEmpty);
            this.tabPage2.Controls.Add(this.pop);
            this.tabPage2.Controls.Add(this.btnAdd);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.txtinput);
            this.tabPage2.Controls.Add(this.lstQueue);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(865, 618);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "QUEUE";
            // 
            // label8
            // 
            this.label8.BackColor = System.Drawing.Color.LightBlue;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label8.Location = new System.Drawing.Point(336, 21);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(248, 48);
            this.label8.TabIndex = 9;
            this.label8.Text = "HÀNG ĐỢI";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label7.Location = new System.Drawing.Point(19, 222);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(139, 29);
            this.label7.TabIndex = 8;
            this.label7.Text = "Giá trị lấy ra";
            // 
            // txtoutput
            // 
            this.txtoutput.BackColor = System.Drawing.Color.WhiteSmoke;
            this.txtoutput.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txtoutput.Location = new System.Drawing.Point(181, 222);
            this.txtoutput.Name = "txtoutput";
            this.txtoutput.ReadOnly = true;
            this.txtoutput.Size = new System.Drawing.Size(191, 45);
            this.txtoutput.TabIndex = 7;
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.LightSlateGray;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.button4.Location = new System.Drawing.Point(251, 481);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(174, 73);
            this.button4.TabIndex = 6;
            this.button4.Text = "Lấy hết phần tử ";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // checkEmpty
            // 
            this.checkEmpty.BackColor = System.Drawing.Color.LightSlateGray;
            this.checkEmpty.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.checkEmpty.Location = new System.Drawing.Point(24, 475);
            this.checkEmpty.Name = "checkEmpty";
            this.checkEmpty.Size = new System.Drawing.Size(174, 73);
            this.checkEmpty.TabIndex = 5;
            this.checkEmpty.Text = "Kiểm tra rỗng";
            this.checkEmpty.UseVisualStyleBackColor = false;
            this.checkEmpty.Click += new System.EventHandler(this.button3_Click);
            // 
            // pop
            // 
            this.pop.BackColor = System.Drawing.Color.LightSlateGray;
            this.pop.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.pop.Location = new System.Drawing.Point(251, 373);
            this.pop.Name = "pop";
            this.pop.Size = new System.Drawing.Size(174, 73);
            this.pop.TabIndex = 4;
            this.pop.Text = "Lấy phần tử";
            this.pop.UseVisualStyleBackColor = false;
            this.pop.Click += new System.EventHandler(this.button2_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.BackColor = System.Drawing.Color.LightSlateGray;
            this.btnAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btnAdd.Location = new System.Drawing.Point(24, 373);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(174, 73);
            this.btnAdd.TabIndex = 3;
            this.btnAdd.Text = "Thêm phần tử";
            this.btnAdd.UseVisualStyleBackColor = false;
            this.btnAdd.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label6.Location = new System.Drawing.Point(19, 161);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(148, 29);
            this.label6.TabIndex = 2;
            this.label6.Text = "Nhập giá trị: ";
            // 
            // txtinput
            // 
            this.txtinput.BackColor = System.Drawing.Color.WhiteSmoke;
            this.txtinput.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txtinput.Location = new System.Drawing.Point(181, 150);
            this.txtinput.Name = "txtinput";
            this.txtinput.Size = new System.Drawing.Size(191, 45);
            this.txtinput.TabIndex = 1;
            this.txtinput.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lstQueue
            // 
            this.lstQueue.BackColor = System.Drawing.Color.WhiteSmoke;
            this.lstQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lstQueue.FormattingEnabled = true;
            this.lstQueue.HorizontalScrollbar = true;
            this.lstQueue.ItemHeight = 31;
            this.lstQueue.Location = new System.Drawing.Point(589, 92);
            this.lstQueue.Name = "lstQueue";
            this.lstQueue.Size = new System.Drawing.Size(176, 500);
            this.lstQueue.TabIndex = 0;
            this.lstQueue.SelectedIndexChanged += new System.EventHandler(this.lstQueue_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(867, 627);
            this.Controls.Add(this.tabControl1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Minh họa";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Label lblEdges;
        private System.Windows.Forms.TextBox txtEdges;
        private System.Windows.Forms.ListBox lstEdges;
        private System.Windows.Forms.Button btnAddEdge;
        private System.Windows.Forms.Button btnBFS;
        private System.Windows.Forms.TextBox txtStartVertex;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox rtbResult;
        private System.Windows.Forms.TextBox txtEdgeU;
        private System.Windows.Forms.TextBox txtEdgeV;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ListBox lstQueue;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button checkEmpty;
        private System.Windows.Forms.Button pop;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtinput;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtoutput;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button cleardata;
        private System.Windows.Forms.Label label9;
    }
}

