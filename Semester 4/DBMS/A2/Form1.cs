using System.Data;
using Microsoft.Data.SqlClient;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Configuration;
using System.Windows.Forms;



namespace Homework1
{
    public partial class Form1 : Form
    {
        SqlConnection dbConnection = new SqlConnection("Data Source=DESKTOP-IBPVCVC\\SQLEXPRESS;Initial Catalog=LearningPlatform;Integrated Security=True;TrustServerCertificate=true");
        private SqlDataAdapter daParent, daChild;
        private DataSet tableData;
        private DataRelation drParentChild;
        private BindingSource bsParent, bsChild;

        public Form1()
        {
            InitializeComponent();
            childTable.SelectionChanged += childTable_SelectionChanged;
            parentTable.SelectionChanged += parentTable_SelectionChanged;

        }

        private string getDatabase()
        {
            return ConfigurationManager.AppSettings["Database"].ToString();
        }

        private string getParentTableName()
        {
            return ConfigurationManager.AppSettings["ParentTableName"].ToString();
        }

        private string getChildTableName()
        {
            return ConfigurationManager.AppSettings["ChildTableName"].ToString();
        }

        private string getParentSelectQuery()
        {
            return ConfigurationManager.AppSettings["ParentSelectQuery"].ToString();
        }

        private string getChildSelectQuery()
        {
            return ConfigurationManager.AppSettings["ChildSelectQuery"].ToString();
        }

        private string getParentReferencedKey()
        {
            return ConfigurationManager.AppSettings["ParentReferencedKey"].ToString();
        }

        private string getChildForeignKey()
        {
            return ConfigurationManager.AppSettings["ChildForeignKey"].ToString();
        }

        private void buttonDisplay_Click(object sender, EventArgs e)
        {
            tableData = new DataSet();

            daParent = new SqlDataAdapter(getParentSelectQuery(), dbConnection);
            daParent.Fill(tableData, getParentTableName());


            daChild = new SqlDataAdapter(getChildSelectQuery(), dbConnection);
            daChild.Fill(tableData, getChildTableName());


            DataColumn referenceId = tableData.Tables[getParentTableName()].Columns[getParentReferencedKey()];
            DataColumn foreignId = tableData.Tables[getChildTableName()].Columns[getChildForeignKey()];
            drParentChild = new DataRelation("FK_Parent_Child", referenceId, foreignId);
            tableData.Relations.Add(drParentChild);

            bsParent = new BindingSource();
            bsParent.DataSource = tableData;
            bsParent.DataMember = getParentTableName();
            parentTable.DataSource = bsParent;

            DataTable childDataTable = tableData.Tables[getChildTableName()];
            childTable.DataSource = childDataTable;

            // Clear existing text boxes from the panel
            panel1.Controls.Clear();

            // Add text boxes dynamically based on the column names
            for (int i = 0; i < childDataTable.Columns.Count; i++)
            {
                string columnName = childDataTable.Columns[i].ColumnName;
                Label label = new Label();
                label.Text = columnName;
                label.Scale(new SizeF(1.5f, 1.5f));
                label.Location = new Point(10, 10 + i * 30);
                panel1.Controls.Add(label);
                System.Windows.Forms.TextBox textBox = new System.Windows.Forms.TextBox();
                textBox.Name = "textBox_" + columnName;
                textBox.Location = new Point(200, 10 + i * 30);
                textBox.Size = new Size(180, 30);
                panel1.Controls.Add(textBox);
            }
        }

        // load tablew view 1
        private void ReloadChildTableView()
        {
            if (tableData.Tables[getChildTableName()] != null)
            {
                tableData.Tables[getChildTableName()].Clear();
            }
            daChild.Fill(tableData, getChildTableName());
            DataTable childDataTable = tableData.Tables[getChildTableName()];
            childTable.DataSource = childDataTable;
        }

        // select Child from child view

        private void childTable_SelectionChanged(object? sender, EventArgs e)
        {

            if (childTable.SelectedRows.Count > 0)
            {
                DataGridViewRow selectedRow = childTable.SelectedRows[0];
                DataTable childTableSelected = tableData.Tables[getChildTableName()];

                // Populate text boxes with values from the selected row
                for (int i = 0; i < childTableSelected.Columns.Count; i++)
                {
                    string columnName = childTableSelected.Columns[i].ColumnName;
                    System.Windows.Forms.TextBox textBox = (System.Windows.Forms.TextBox)panel1.Controls["textBox_" + columnName];
                    textBox.Text = selectedRow.Cells[columnName].Value.ToString();
                }
            }
        }

        private void parentTable_SelectionChanged(object? sender, EventArgs e)
        {
            bsChild = new BindingSource();
            bsChild.DataSource = bsParent;
            bsChild.DataMember = "FK_Parent_Child";

            parentTable.DataSource = bsParent;
            childTable.DataSource = bsChild;
        }

        private void ClearTextBoxes()
        {
            foreach (System.Windows.Forms.TextBox textBox in panel1.Controls.OfType<System.Windows.Forms.TextBox>())
            {
                textBox.Text = string.Empty;
            }
        }


        private void buttonAdd_Click(object sender, EventArgs e)
        {
            if (panel1.Controls.OfType<System.Windows.Forms.TextBox>().All(textBox => textBox.Text.Length > 0))
            {
                try
                {
                    Dictionary<string, object> columnValues = new Dictionary<string, object>();
                    foreach (System.Windows.Forms.TextBox textBox in panel1.Controls.OfType<System.Windows.Forms.TextBox>())
                    {
                        string columnName = textBox.Name.Replace("textBox_", "");
                        columnValues[columnName] = textBox.Text;
                    }

                    string tableName = getChildTableName();
                    string columnNames = string.Join(", ", columnValues.Keys);
                    string parameterNames = string.Join(", ", columnValues.Keys.Select((_, index) => $"@param{index}"));
                    string insertQuery = $"INSERT INTO {tableName} ({columnNames}) VALUES ({parameterNames})";

                    SqlCommand command = new SqlCommand(insertQuery, dbConnection);
                    foreach (var kvp in columnValues.Select((pair, index) => (pair, index)))
                    {
                        command.Parameters.AddWithValue($"@param{kvp.index}", kvp.pair.Value);
                    }

                    try
                    {
                        dbConnection.Open();
                        command.ExecuteNonQuery();
                        ReloadChildTableView();
                        ClearTextBoxes();
                    }
                    catch (SqlException ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                    finally
                    {
                        dbConnection.Close();
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
            else
            {
                MessageBox.Show("Please provide values for all fields.");
            }
        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            if (childTable.SelectedRows.Count > 0)
            {

                int id = (int)childTable.SelectedRows[0].Cells[0].Value;
                string tableName = getChildTableName();
                string columnName = childTable.Columns[0].Name;

                string deleteQuery = $"DELETE FROM {tableName} WHERE {columnName} = @{columnName}";
                SqlCommand deleteCommand = new SqlCommand(deleteQuery, dbConnection);
                deleteCommand.Parameters.AddWithValue($"@{columnName}", id);

                try
                {
                    dbConnection.Open();
                    deleteCommand.ExecuteNonQuery();
                    MessageBox.Show("Object deleted successfully!");
                    ReloadChildTableView();
                }
                catch (SqlException ex)
                {
                    MessageBox.Show("Error deleting object: " + ex.Message);
                }
                finally
                {
                    dbConnection.Close();
                }
            }
            else
            {
                MessageBox.Show("Please select object to delete.");
            }
        }


        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            if (childTable.SelectedRows.Count > 0)
            {
                try
                {
                    string idColumnName = childTable.Columns[0].Name;

                    object idObject = childTable.SelectedRows[0].Cells[idColumnName].Value;

                    if (idObject != null && int.TryParse(idObject.ToString(), out int finalId))
                    {
                        string updateQuery = $"UPDATE {getChildTableName()} SET ";
                        List<string> updateValues = new List<string>();

                        foreach (System.Windows.Forms.TextBox textBox in panel1.Controls.OfType<System.Windows.Forms.TextBox>())
                        {
                            string columnName = textBox.Name.Replace("textBox_", "");
                            string columnValue = textBox.Text;

                            updateValues.Add($"{columnName} = '{columnValue}'");
                        }
                        updateQuery += string.Join(", ", updateValues);
                        updateQuery += $" WHERE {idColumnName} = {finalId}";
                        try
                        {
                            dbConnection.Open();
                            SqlCommand command = new SqlCommand(updateQuery, dbConnection);
                            command.ExecuteNonQuery();
                            MessageBox.Show("Object updated successfully!");
                            ReloadChildTableView();
                        }
                        catch (SqlException ex)
                        {
                            MessageBox.Show("Error updating object: " + ex.Message);
                        }
                        finally
                        {
                            dbConnection.Close();
                        }
                    }
                    else
                    {
                        MessageBox.Show("Invalid ID value in the selected row.");
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
            else
            {
                MessageBox.Show("Please select a row to update.");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
          
        }

    }


}
