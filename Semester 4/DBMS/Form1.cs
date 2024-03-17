using System.Data;
using Microsoft.Data.SqlClient;
using System.Security.Policy;
using System.Security.Cryptography;
using System.Windows.Forms;



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
            //this.libraryIDBox.ReadOnly = true;
            this.childTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            ParentTable_Load();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void ParentTable_Load()
        {
            this.dataAdapt.SelectCommand = new SqlCommand("SELECT * FROM Course", dbConn);
            this.dataSet.Clear();
            this.dataAdapt.Fill(this.dataSet, "Course");

            this.parentTable.DataSource = this.dataSet.Tables["Course"];
        }

  
        private void Form1_Load_1(object sender, EventArgs e)
        {

        }


        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {

        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {

        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {

        }
    }
}
