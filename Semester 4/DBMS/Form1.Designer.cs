

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
            parentTable.Size = new Size(544, 210);
            parentTable.TabIndex = 0;
            // 
            // childTable
            // 
            childTable.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            childTable.Location = new Point(12, 314);
            childTable.Margin = new Padding(3, 4, 3, 4);
            childTable.Name = "childTable";
            childTable.RowHeadersWidth = 51;
            childTable.Size = new Size(544, 215);
            childTable.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(153, 267);
            label1.Name = "label1";
            label1.Size = new Size(146, 20);
            label1.TabIndex = 2;
            label1.Text = "Parent Table-Courses";
            label1.Click += label1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(143, 566);
            label2.Name = "label2";
            label2.Size = new Size(156, 20);
            label2.TabIndex = 3;
            label2.Text = "Child Table-Instructors";
            label2.Click += label2_Click;
            // 
            // buttonRemove
            // 
            buttonRemove.Location = new Point(791, 314);
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
            buttonAdd.Location = new Point(655, 314);
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
            buttonUpdate.Location = new Point(927, 314);
            buttonUpdate.Margin = new Padding(3, 4, 3, 4);
            buttonUpdate.Name = "buttonUpdate";
            buttonUpdate.Size = new Size(130, 50);
            buttonUpdate.TabIndex = 6;
            buttonUpdate.Text = "Update";
            buttonUpdate.UseVisualStyleBackColor = true;
            buttonUpdate.Click += buttonUpdate_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1119, 750);
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
    }
}
