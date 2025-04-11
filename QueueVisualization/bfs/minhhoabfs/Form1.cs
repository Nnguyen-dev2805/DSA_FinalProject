using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading.Tasks;
using System.Drawing;
using static System.Windows.Forms.LinkLabel;
using System.Linq;

namespace BFS_Graph_App
{
    public partial class Form1 : Form
    {
        private Dictionary<int, List<int>> graph = new Dictionary<int, List<int>>();
        private int vertices, edges;
        private Queue<int> myqueue = new Queue<int>();

        public object Lines { get; private set; }

        public Form1()
        {
            InitializeComponent();
        }

        private void btnAddEdge_Click(object sender, EventArgs e)
        {
            // Kiểm tra dữ liệu nhập vào có hợp lệ hay không
            if (string.IsNullOrWhiteSpace(txtEdgeU.Text) ||
                string.IsNullOrWhiteSpace(txtEdges.Text) ||
                string.IsNullOrWhiteSpace(txtEdgeV.Text))
            {
                MessageBox.Show("Vui lòng nhập dữ liệu vào tất cả các ô.", "Thông báo");
                return;
            }
             else if (!int.TryParse(txtEdges.Text, out _) ||
                !int.TryParse(txtEdgeU.Text, out _) ||
                !int.TryParse(txtEdgeV.Text, out _))
            {
                MessageBox.Show("Dữ liệu nhập vào phải là số nguyên.", "Thông báo");
                return;
            }
            // Kiểm tra nhập quá số cạnh 
            if(lstEdges.Items.Count >= int.Parse(txtEdges.Text))
            {
                MessageBox.Show($"Đã đạt tới giới hạn {int.Parse(txtEdges.Text)} cạnh.", "Thông báo");
            }
            else
            {
                // Lấy số cạnh
                edges = int.Parse(txtEdges.Text);

                // Nhập cạnh mới
                int u = int.Parse(txtEdgeU.Text);
                int v = int.Parse(txtEdgeV.Text);

                if (!graph.ContainsKey(u))
                    graph[u] = new List<int>();
                if (!graph.ContainsKey(v))
                    graph[v] = new List<int>();

                graph[u].Add(v);
                graph[v].Add(u);

                // Hiển thị cạnh trong ListBox
                lstEdges.Items.Add($"Cạnh: {u} - {v}");
                lstEdges.TopIndex = lstEdges.Items.Count - 1;
            } 
            txtEdgeU.Clear();
            txtEdgeV.Clear();
            // Trả con trỏ về ô nhập U
            txtEdgeU.Focus();
        }

        private void btnBFS_Click(object sender, EventArgs e)
        {
            // Lấy đỉnh bắt đầu
            if(string.IsNullOrWhiteSpace(txtStartVertex.Text))
                {
                MessageBox.Show("Vui lòng nhập dữ liệu vào tất cả các ô.", "Thông báo");
                return;
            }
            else if (!int.TryParse(txtStartVertex.Text, out _))
            {
                MessageBox.Show("Dữ liệu nhập vào phải là số nguyên.", "Thông báo");
                return;
            }
            if (!graph.ContainsKey(int.Parse(txtStartVertex.Text)))
            {
                MessageBox.Show("Đỉnh bắt đầu không tồn tại! Vui lòng nhập lại.", "Thông báo" );
                return;
            }
            int startVertex = int.Parse(txtStartVertex.Text);
            rtbResult.Clear();
            BFS(startVertex);
        }

        private void txtEdges_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void lstEdges_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void lblEdges_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void txtStartVertex_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void txtEdgeU_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtEdgeV_TextChanged(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private async void button4_Click(object sender, EventArgs e)
        {
            while(myqueue.Count > 0)
            {
                txtoutput.Text = myqueue.Dequeue().ToString();
                updateQueuedisplay();
                await Task.Delay(500);
            }
            MessageBox.Show("Đã lấy hết phần tử từ hàng đợi!", "Thông báo");
            txtoutput.Clear();
        }

        private void lstQueue_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void BFS(int start)
        {
            foreach (var key in graph.Keys.ToList())
            {
                graph[key] = graph[key].OrderBy(x => x).ToList();
            }
            Queue<int> queue = new Queue<int>();
            HashSet<int> visited = new HashSet<int>();

            queue.Enqueue(start);
            visited.Add(start);
            rtbResult.AppendText($"BFS từ đỉnh {start}: \n");

            while (queue.Count > 0)
            {
                int current = queue.Dequeue();
                rtbResult.AppendText("        " + current + " \n" + "        ↓ " + "\n");
              //  rtbResult.SelectionStart = rtbResult.Text.Length;
              // rtbResult.ScrollToCaret();
                foreach (int neighbor in graph[current])
                {
                    if (!visited.Contains(neighbor))
                    {
                        queue.Enqueue(neighbor);
                        visited.Add(neighbor);
                    }
                }
            }
            if (rtbResult.Lines.Length > 0)
            {
                rtbResult.Lines = rtbResult.Lines.Take(rtbResult.Lines.Length - 2).ToArray();
            }
        }
        // Tab Queue
        // Thêm phần tử vào hàng đợi
        private void button1_Click_1(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(txtinput.Text) || !int.TryParse(txtinput.Text,out _))
            {
                MessageBox.Show("Vui lòng nhập giá trị số nguyên!", "Thông báo");
            }
            else
            {
                myqueue.Enqueue(int.Parse(txtinput.Text));
                txtinput.Clear();  
                updateQueuedisplay();
                lstQueue.TopIndex = lstQueue.Items.Count - 1;
            }
            txtoutput.Clear();
            // đưa con trỏ tự động quay về ô input
            txtinput.Focus();

        }
        // Lấy phần tử đầu tiên ra khỏi hàng đợi
        private void button2_Click(object sender, EventArgs e)
        {
            if (myqueue.Count == 0)
            {
                MessageBox.Show("Hàng đợi rỗng!", "Thông báo");
            }
            else
            {
                txtoutput.Text = myqueue.Dequeue().ToString();
                updateQueuedisplay();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (myqueue.Count == 0)
            {
                MessageBox.Show("Hàng đợi rỗng.", "Thông báo");
            }
            else
            {
                MessageBox.Show("Hàng đợi tồn tại phần tử.", "Thông báo");
            }
            txtoutput.Clear();
        }
        //Xóa tất cả dữ liệu của đồ thị
        private void cleardata_Click(object sender, EventArgs e)
        {
            txtEdges.Clear();
            txtEdgeU.Clear();
            txtEdgeV.Clear();
            lstEdges.Items.Clear();
            rtbResult.Clear();
            txtStartVertex.Clear();
            graph.Clear();
            myqueue.Clear();
            MessageBox.Show("Dữ liệu đã được xóa.", "Thông báo ");

        }

        private void rtbResult_TextChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        // Tab Queue
        // Hàm cập nhật hiển thị các phần tử trong queue
        private void updateQueuedisplay()
        {
            lstQueue.Items.Clear();
            foreach(var x in myqueue)
            {
                lstQueue.Items.Add("        " + x);
            }
        }


    }
}
