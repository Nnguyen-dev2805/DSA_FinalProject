package GUI;

import Implementation.BST;
import Implementation.TreeNode;

import javax.swing.*;
import java.awt.*;

@SuppressWarnings("ALL")
public class BSTPane extends JPanel {
    private BST<Integer> tree;
    private int radius = 15;
    // Khoảng cách dọc giữa các cấp trong cây
    private int vGap = 50;
    private boolean showMessage = false;
    private Integer highlightNodeValue = null;

    BSTPane(BST<Integer> tree) {
        this.tree = tree;
        setBackground(Color.WHITE);
    }

    public void setStatus(String msg) {
        if (!msg.equals("Tree is Empty") || !showMessage) {
            JOptionPane.showMessageDialog(this, msg);
            if (msg.equals("Tree is Empty")) {
                showMessage = true;
            }
        }
        repaint();
    }

    public void displayTree() {
        repaint(); // Tự động gọi phương thức paintComponent để vẽ lại cây
    }

    public void highlightNode(int value) {
        highlightNodeValue = value;
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (tree.getRoot() != null) {
            showMessage = false;
            displayTree(g, tree.getRoot(), getWidth() / 2, vGap, getWidth() / 4, Color.LIGHT_GRAY);
        }
    }

    // hGap khoảng cách theo chiều ngang giữa các nút của cây
    private void displayTree(Graphics g, TreeNode<Integer> root, int x, int y, int hGap, Color color) {
        g.setColor(color);
        if (root.left != null) {
            g.drawLine(x, y, x - hGap, y + vGap);
            displayTree(g, root.left, x - hGap, y + vGap, hGap / 2, color);
        }
        if (root.right != null) {
            g.drawLine(x, y, x + hGap, y + vGap);
            displayTree(g, root.right, x + hGap, y + vGap, hGap / 2, color);
        }
        if(root.element.equals(highlightNodeValue)){
            g.setColor(Color.RED);
        }
        else{
            g.setColor(color);
        }
        // Tô màu
        g.fillOval(x - radius, y - radius, radius * 2, radius * 2);
        g.setColor(Color.BLACK);
        // Vẽ viền
        g.drawOval(x - radius, y - radius, radius * 2, radius * 2);
        g.drawString(root.element + "", x - g.getFontMetrics().stringWidth(root.element + "") / 2, y + g.getFontMetrics().getHeight() / 3);
    }
}