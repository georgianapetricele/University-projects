using System.Data;
using Microsoft.Data.SqlClient;
using System.Security.Policy;
using System.Security.Cryptography;
using System.Windows.Forms;
using System.Data.Common;
using System;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Reflection;



namespace Homework1
{
    public partial class Form1 : Form
    {

        private SqlConnection dbConn;
        private SqlDataAdapter dataAdapt;
        private DataSet dataSet;

        public Form1()
        {
            dbConn = new SqlConnection("Data Source=DESKTOP-IBPVCVC\\SQLEXPRESS;Initial Catalog=LearningPlatform;Integrated Security=True;TrustServerCertificate=true");
            dataAdapt = new SqlDataAdapter();
            dataSet = new DataSet();


            InitializeComponent();
            this.childTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            ParentTable_Load();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void ParentTable_Load()
        {
            this.parentTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            this.dataAdapt.SelectCommand = new SqlCommand("SELECT * FROM Student", dbConn);
            this.dataSet.Clear();
            this.dataAdapt.Fill(this.dataSet, "Student");

            this.parentTable.DataSource = this.dataSet.Tables["Student"];
        }

        private void ParentTable_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            assignmentIdBox.Clear();
            contentBox.Clear();
            gradeBox.Clear();
            deadlineBox.Clear();


            try
            {
                if (this.parentTable.SelectedRows.Count > 0)
                {
                    //take the selected row
                    DataGridViewRow selectedRow = this.parentTable.SelectedRows[0];

                    if (this.parentTable.SelectedRows.Count > 0)
                    {
                        //take the student id

                        int studentId = Convert.ToInt32(selectedRow.Cells[0].Value);
                        this.dataAdapt.SelectCommand = new SqlCommand("SELECT * FROM Assignment WHERE StudentId = " + studentId, dbConn);
                        this.dataAdapt.SelectCommand.Parameters.AddWithValue("@id", studentId);

                        //populate the child table
                        this.dataSet = new DataSet();
                        this.dataAdapt.Fill(this.dataSet, "Assignment");
                        this.childTable.DataSource = this.dataSet.Tables["Assignment"];

                    }
                }
            }
            catch(System.InvalidCastException ex)
            {
                MessageBox.Show("Error: Index out of range!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void ChildTable_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            // We take the index of the selected row
            int index = this.childTable.SelectedRows[0].Index;


            assignmentIdBox.Text = dataSet.Tables["Assignment"].Rows[index][0].ToString();
            studentIdBox.Text = dataSet.Tables["Assignment"].Rows[index][1].ToString();
            contentBox.Text = dataSet.Tables["Assignment"].Rows[index][2].ToString();
            gradeBox.Text = dataSet.Tables["Assignment"].Rows[index][3].ToString();
            deadlineBox.Text = dataSet.Tables["Assignment"].Rows[index][4].ToString();

        }


        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void clearTextBoxes()
        {
            assignmentIdBox.Clear();
            studentIdBox.Clear();
            contentBox.Clear();
            gradeBox.Clear();
            deadlineBox.Clear();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {

            try
            {

                dataAdapt.InsertCommand = new SqlCommand("INSERT INTO Assignment VALUES (@aid,@sid,@co,@gr,@de)", dbConn);
                dataAdapt.InsertCommand.Parameters.Add("@aid", SqlDbType.VarChar).Value = assignmentIdBox.Text;
                dataAdapt.InsertCommand.Parameters.Add("@sid", SqlDbType.VarChar).Value = studentIdBox.Text;
                dataAdapt.InsertCommand.Parameters.Add("@co", SqlDbType.VarChar).Value = contentBox.Text;
                dataAdapt.InsertCommand.Parameters.Add("@gr", SqlDbType.VarChar).Value = gradeBox.Text;
                dataAdapt.InsertCommand.Parameters.Add("@de", SqlDbType.VarChar).Value = deadlineBox.Text;

                dbConn.Open();
                dataAdapt.InsertCommand.ExecuteNonQuery();
                dbConn.Close();
                MessageBox.Show("Assignment added successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (SqlException ex)
            {
                if (ex.Number == 547)
                    MessageBox.Show("There is no assignment with given ID!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                else
                    if(ex.Number == 2627)
                    MessageBox.Show("Assignment ID/Student ID must be unique!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                else
                    MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                dbConn.Close();

                clearTextBoxes();
            }

        }



        private void buttonRemove_Click(object sender, EventArgs e)
        {
            int index = this.childTable.SelectedRows[0].Index;
            DialogResult dr;
            dr = MessageBox.Show("Are you sure?\n No undo after remove!", "Confirm removing", MessageBoxButtons.YesNo);
            if (dr == DialogResult.Yes)
            {
                try
                {
                    // We create the delete command
                    this.dataAdapt.DeleteCommand = new SqlCommand("DELETE FROM Assignment WHERE AssignmentId=@aid", dbConn);
                    this.dataAdapt.DeleteCommand.Parameters.Add("@aid", SqlDbType.Int).Value = this.dataSet.Tables["Assignment"].Rows[index][0];

                    this.dbConn.Open();
                    this.dataAdapt.DeleteCommand.ExecuteNonQuery();
                    MessageBox.Show("Removed Succesfull from Database");
                    this.dbConn.Close();

                    this.dataSet = new DataSet();
                    this.dataAdapt.Fill(this.dataSet, "Assignment");
                    this.childTable.DataSource = this.dataSet.Tables["Assignment"];

                    this.clearTextBoxes();
                }
                catch (System.IndexOutOfRangeException ex)
                {
                    MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    this.dbConn.Close();
                }
               
            }
            else
            {
                MessageBox.Show("Deletion Aborted");
                this.dbConn.Close();
            }

        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                int x;
                dataAdapt.UpdateCommand = new SqlCommand("Update Assignment set StudentId = @sid,Content=@co,Grade=@gr,Deadline=@de where AssignmentId = @id", dbConn);
               
                dataAdapt.UpdateCommand.Parameters.Add("@sid",SqlDbType.VarChar).Value = studentIdBox.Text;
                dataAdapt.UpdateCommand.Parameters.Add("@co",SqlDbType.VarChar).Value = contentBox.Text;
                dataAdapt.UpdateCommand.Parameters.Add("@gr",SqlDbType.VarChar).Value = gradeBox.Text;
                dataAdapt.UpdateCommand.Parameters.Add("@de",SqlDbType.VarChar).Value = deadlineBox.Text;

                int index = this.childTable.SelectedRows[0].Index;
                this.dataAdapt.UpdateCommand.Parameters.Add("@id", SqlDbType.Int).Value = this.dataSet.Tables["Assignment"].Rows[index][0];

                dbConn.Open();
                x = dataAdapt.UpdateCommand.ExecuteNonQuery();
                dbConn.Close();
                if (x >= 1)
                {
                    MessageBox.Show("The record has been updated");
                }
                else
                {
                    MessageBox.Show("The record has not been updated");
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                this.dbConn.Close();
            }
        }

        private void Form1_Load_2(object sender, EventArgs e)
        {
            
        }

    }


}
