package GUI;

import Implementation.BST;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

@SuppressWarnings("ALL")
public class BSTVisualizer extends JFrame {
    private static ArrayList<Integer> nodes = new ArrayList<>();
    private BST<Integer> tree;
    private BSTPane view;
    private JLabel heightLabel;

    public BSTVisualizer() {
        tree = new BST<>();
        view = new BSTPane(tree);

        // Thiết lập giao diện chính
        setTitle("Binary Search Tree Visualization");
        setLayout(new BorderLayout());
        setPane();

        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        // Trì hoãn việc gọi setStatus trước khi giao diện được hiện thị
        SwingUtilities.invokeLater(() -> {
            if (tree.getRoot() == null) {
                view.setStatus("Tree is empty");
            }
        });

    }

    public void setPane() {
        add(view, BorderLayout.CENTER);
        JPanel bottomPanel = new JPanel();
        TextField textField = new TextField(3);
        JButton insertButton = new JButton("Insert");
        JButton deleteButton = new JButton("Delete");
        JButton searchButton = new JButton("Search");
        addFunctionlities(textField, insertButton, deleteButton,searchButton);

        bottomPanel.add(new Label("Enter a value: "));
        bottomPanel.add(textField);
        bottomPanel.add(insertButton);
        bottomPanel.add(deleteButton);
        bottomPanel.add(searchButton);

        heightLabel = new JLabel("Height Tree: 0");
        add(bottomPanel, BorderLayout.SOUTH);
        add(heightLabel, BorderLayout.NORTH);
    }

    public void addFunctionlities(TextField textField, JButton insertButton, JButton deleteButton,JButton searchButton) {
        insertButton.addActionListener(e -> {
            String text = textField.getText();
            if (text.equals("")) {
                JOptionPane.showMessageDialog(null, "You haven't entered anything!", "Warning", JOptionPane.WARNING_MESSAGE);
            } else {
                int key = Integer.parseInt(text);
                nodes.add(key);
                if (tree.search(key)) {
                    view.displayTree();
                    view.setStatus(key + " is already in the tree");
                } else {
                    tree.insert(key);
                    view.displayTree();
                    view.setStatus(key + " was inserted");
                }
                updateHeight();
            }
            textField.setText("");
        });
        deleteButton.addActionListener(e -> {
            if(textField.getText().equals("")) {
                JOptionPane.showMessageDialog(null, "You have not entered anything!", "Warning", JOptionPane.WARNING_MESSAGE);
                return;
            }
            int key = Integer.parseInt(textField.getText());
            if (tree.search(key)) {
                tree.delete(key);
                view.displayTree();
                view.setStatus(key + " was deleted");
                if (tree.getRoot() == null) {
                    view.setStatus("Tree is empty");
                }
            } else {
                view.displayTree();
                view.setStatus(key + " is not in the tree");
            }
            updateHeight();
            textField.setText("");
        });
        searchButton.addActionListener(e -> {
            String text = textField.getText();
            if (text.equals("")) {
                JOptionPane.showMessageDialog(null, "You haven't entered anything!", "Warning", JOptionPane.WARNING_MESSAGE);
            }
            else{
                int key = Integer.parseInt(text);
                if (tree.search(key)) {
                    view.highlightNode(key);
                    view.setStatus(key + " was found");
                }
                else{
                    view.displayTree();
                    view.setStatus(key + " was not found");
                }
            }
            textField.setText("");
        });
    }

    private void updateHeight(){
        int height=tree.getHeight();
        heightLabel.setText("Height Tree: "+height);
    }
}