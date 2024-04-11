


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
            assignmentIdBox = new TextBox();
            studentIdBox = new TextBox();
            contentBox = new TextBox();
            gradeBox = new TextBox();
            deadlineBox = new TextBox();
            assignmentIdLabel = new Label();
            studentIdLabel = new Label();
            contentLabel = new Label();
            gradeLabel = new Label();
            deadlineLabel = new Label();
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
            parentTable.Size = new Size(677, 210);
            parentTable.TabIndex = 0;
            parentTable.CellClick += ParentTable_CellClick;
            // 
            // childTable
            // 
            childTable.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            childTable.Location = new Point(12, 314);
            childTable.Margin = new Padding(3, 4, 3, 4);
            childTable.Name = "childTable";
            childTable.RowHeadersWidth = 51;
            childTable.Size = new Size(677, 215);
            childTable.TabIndex = 1;
            childTable.CellClick += ChildTable_CellClick;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(153, 267);
            label1.Name = "label1";
            label1.Size = new Size(146, 20);
            label1.TabIndex = 2;
            label1.Text = "Parent Table-Student";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(143, 566);
            label2.Name = "label2";
            label2.Size = new Size(165, 20);
            label2.TabIndex = 3;
            label2.Text = "Child Table-Assignment";
            // 
            // buttonRemove
            // 
            buttonRemove.Location = new Point(908, 479);
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
            buttonAdd.Location = new Point(741, 479);
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
            buttonUpdate.Location = new Point(1071, 479);
            buttonUpdate.Margin = new Padding(3, 4, 3, 4);
            buttonUpdate.Name = "buttonUpdate";
            buttonUpdate.Size = new Size(130, 50);
            buttonUpdate.TabIndex = 6;
            buttonUpdate.Text = "Update";
            buttonUpdate.Click += buttonUpdate_Click;
            // 
            // assignmentIdBox
            // 
            assignmentIdBox.Location = new Point(983, 114);
            assignmentIdBox.Name = "assignmentIdBox";
            assignmentIdBox.Size = new Size(218, 27);
            assignmentIdBox.TabIndex = 10;
            // 
            // studentIdBox
            // 
            studentIdBox.Location = new Point(983, 190);
            studentIdBox.Name = "studentIdBox";
            studentIdBox.Size = new Size(218, 27);
            studentIdBox.TabIndex = 14;
            // 
            // contentBox
            // 
            contentBox.Location = new Point(983, 260);
            contentBox.Name = "contentBox";
            contentBox.Size = new Size(218, 27);
            contentBox.TabIndex = 11;
            // 
            // gradeBox
            // 
            gradeBox.Location = new Point(983, 335);
            gradeBox.Name = "gradeBox";
            gradeBox.Size = new Size(218, 27);
            gradeBox.TabIndex = 12;
            // 
            // deadlineBox
            // 
            deadlineBox.Location = new Point(983, 404);
            deadlineBox.Name = "deadlineBox";
            deadlineBox.Size = new Size(218, 27);
            deadlineBox.TabIndex = 13;
            // 
            // assignmentIdLabel
            // 
            assignmentIdLabel.Location = new Point(760, 114);
            assignmentIdLabel.Name = "assignmentIdLabel";
            assignmentIdLabel.Size = new Size(122, 23);
            assignmentIdLabel.TabIndex = 15;
            assignmentIdLabel.Text = "Assignment ID";
            // 
            // studentIdLabel
            // 
            studentIdLabel.Location = new Point(760, 190);
            studentIdLabel.Name = "studentIdLabel";
            studentIdLabel.Size = new Size(100, 23);
            studentIdLabel.TabIndex = 16;
            studentIdLabel.Text = "Student ID";
            // 
            // contentLabel
            // 
            contentLabel.Location = new Point(760, 260);
            contentLabel.Name = "contentLabel";
            contentLabel.Size = new Size(100, 23);
            contentLabel.TabIndex = 17;
            contentLabel.Text = "Content";
            // 
            // gradeLabel
            // 
            gradeLabel.Location = new Point(760, 335);
            gradeLabel.Name = "gradeLabel";
            gradeLabel.Size = new Size(100, 23);
            gradeLabel.TabIndex = 18;
            gradeLabel.Text = "Grade";
            // 
            // deadlineLabel
            // 
            deadlineLabel.Location = new Point(760, 404);
            deadlineLabel.Name = "deadlineLabel";
            deadlineLabel.Size = new Size(100, 23);
            deadlineLabel.TabIndex = 19;
            deadlineLabel.Text = "Deadline";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1252, 750);
            Controls.Add(buttonAdd);
            Controls.Add(buttonRemove);
            Controls.Add(buttonUpdate);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(childTable);
            Controls.Add(parentTable);
            Controls.Add(assignmentIdBox);
            Controls.Add(studentIdBox);
            Controls.Add(contentBox);
            Controls.Add(gradeBox);
            Controls.Add(deadlineBox);
            Controls.Add(assignmentIdLabel);
            Controls.Add(studentIdLabel);
            Controls.Add(contentLabel);
            Controls.Add(gradeLabel);
            Controls.Add(deadlineLabel);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load_2;
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
        private System.Windows.Forms.TextBox assignmentIdBox;
        private System.Windows.Forms.TextBox studentIdBox;
        private System.Windows.Forms.TextBox contentBox;
        private System.Windows.Forms.TextBox gradeBox;
        private System.Windows.Forms.TextBox deadlineBox;
        private System.Windows.Forms.Label assignmentIdLabel;
        private System.Windows.Forms.Label studentIdLabel;
        private System.Windows.Forms.Label contentLabel;
        private System.Windows.Forms.Label gradeLabel;
        private System.Windows.Forms.Label deadlineLabel;

    }
}
