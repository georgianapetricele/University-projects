


namespace Homework1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>

        private void InitializeComponent()
        {
            parentTable = new DataGridView();
            childTable = new DataGridView();
            label1 = new Label();
            label2 = new Label();
            buttonRemove = new Button();
            buttonAdd = new Button();
            buttonUpdate = new Button();
            panel1 = new Panel();
            buttonDisplay = new Button();
            ((System.ComponentModel.ISupportInitialize)parentTable).BeginInit();
            ((System.ComponentModel.ISupportInitialize)childTable).BeginInit();
            SuspendLayout();
            // 
            // parentTable
            // 
            parentTable.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            parentTable.Location = new Point(12, 31);
            parentTable.Margin = new Padding(3, 4, 3, 4);
            parentTable.Name = "parentTable";
            parentTable.RowHeadersWidth = 51;
            parentTable.Size = new Size(604, 232);
            parentTable.TabIndex = 0;
            // 
            // childTable
            // 
            childTable.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            childTable.Location = new Point(12, 314);
            childTable.Margin = new Padding(3, 4, 3, 4);
            childTable.Name = "childTable";
            childTable.RowHeadersWidth = 51;
            childTable.Size = new Size(604, 247);
            childTable.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(143, 267);
            label1.Name = "label1";
            label1.Size = new Size(89, 20);
            label1.TabIndex = 2;
            label1.Text = "Parent Table";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(143, 565);
            label2.Name = "label2";
            label2.Size = new Size(82, 20);
            label2.TabIndex = 3;
            label2.Text = "Child Table";
            // 
            // buttonRemove
            // 
            buttonRemove.Location = new Point(832, 351);
            buttonRemove.Margin = new Padding(3, 4, 3, 4);
            buttonRemove.Name = "buttonRemove";
            buttonRemove.Size = new Size(130, 50);
            buttonRemove.TabIndex = 5;
            buttonRemove.Text = "Remove";
            buttonRemove.UseVisualStyleBackColor = true;
            buttonRemove.Click += buttonRemove_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.Location = new Point(663, 351);
            buttonAdd.Margin = new Padding(3, 4, 3, 4);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(130, 50);
            buttonAdd.TabIndex = 4;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // buttonUpdate
            // 
            buttonUpdate.Location = new Point(994, 351);
            buttonUpdate.Margin = new Padding(3, 4, 3, 4);
            buttonUpdate.Name = "buttonUpdate";
            buttonUpdate.Size = new Size(130, 50);
            buttonUpdate.TabIndex = 6;
            buttonUpdate.Text = "Update";
            buttonUpdate.Click += buttonUpdate_Click;
            // 
            // panel1
            // 
            panel1.Location = new Point(663, 31);
            panel1.Name = "panel1";
            panel1.Size = new Size(461, 300);
            panel1.TabIndex = 20;
            // 
            // buttonDisplay
            // 
            buttonDisplay.Location = new Point(835, 431);
            buttonDisplay.Name = "buttonDisplay";
            buttonDisplay.Size = new Size(127, 50);
            buttonDisplay.TabIndex = 21;
            buttonDisplay.Text = "Display";
            buttonDisplay.UseVisualStyleBackColor = true;
            buttonDisplay.Click += buttonDisplay_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1252, 611);
            Controls.Add(buttonDisplay);
            Controls.Add(panel1);
            Controls.Add(buttonAdd);
            Controls.Add(buttonRemove);
            Controls.Add(buttonUpdate);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(childTable);
            Controls.Add(parentTable);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)parentTable).EndInit();
            ((System.ComponentModel.ISupportInitialize)childTable).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }


        #endregion

        private System.Windows.Forms.DataGridView parentTable;
        private System.Windows.Forms.DataGridView childTable;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonAdd;
        private System.Windows.Forms.Button buttonRemove;
        private System.Windows.Forms.Button buttonUpdate;
        private Panel panel1;
        private Button buttonDisplay;
    }
}
