package Implementation;

import java.util.ArrayList;
import java.util.Iterator;

@SuppressWarnings("ALL")
public class BST<E extends Comparable<E>> implements Tree<E> {
    public TreeNode<E> root;
    public int size = 0;

    public BST() {
    }

    public BST(E[] objects) {
        for (E object : objects) {
            insert(object);
        }
    }

    private boolean search(TreeNode<E> root, E e) {
        if (root == null)
            return false;
        else if (e.compareTo(root.element) == 0)
            return true;
        else if (e.compareTo(root.element) > 0) return search(root.right, e);
        else return search(root.left, e);
    }

    @Override
    public boolean search(E e) {
        return search(root, e);
    }

    public int height(TreeNode<E> node) {
        if (node == null)
            return 0;
        return node.height;
    }

    public TreeNode<E> insert(TreeNode<E> root, E e) {
        if (root == null)
            return createNewNode(e);
        else if (e.compareTo(root.element) > 0)
            root.right = insert(root.right, e);
        else if (e.compareTo(root.element) < 0)
            root.left = insert(root.left, e);
        else
            return null;
        return root;
    }

    @Override
    public boolean insert(E e) {
        root = insert(root, e);
        if (root == null)
            return false;
        size++;
        return true;
    }

    public TreeNode<E> createNewNode(E e) {
        return new TreeNode<>(e);
    }

    public TreeNode<E> delete(TreeNode<E> root, E e) {
        if (root == null)
            return null;
        if (e.compareTo(root.element) > 0)
            root.right = delete(root.right, e);
        else if (e.compareTo(root.element) < 0)
            root.left = delete(root.left, e);
        else {
            if (root.left == null && root.right == null)
                root = null;
            else if (root.left == null)
                root = root.right;
            else if (root.right == null)
                root = root.left;
            else {
                root.element = findMax(root.left);
                root.left = delete(root.left, root.element);
            }
        }
        return root;
    }

    private E findMax(TreeNode<E> root) {
        TreeNode<E> temp = root;
        while (temp.right != null) {
            temp = temp.right;
        }
        return temp.element;
    }

    @Override
    public boolean delete(E e) {
        root = delete(root, e);
        if (root == null)
            return false;
        size--;
        return true;
    }

    private void inorder(TreeNode<E> root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.element + " ");
            inorder(root.right);
        }
    }

    @Override
    public void inorder() {
        inorder(root);
    }

    private void postorder(TreeNode<E> root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.element + " ");
        }
    }

    @Override
    public void postorder() {
        postorder(root);
    }

    private void preorder(TreeNode<E> root) {
        if (root != null) {
            System.out.print(root.element + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    @Override
    public void preorder() {
        preorder(root);
    }

    // Truy vết đường dẫn của của nút gốc đến nút có giá trị e
    public ArrayList<TreeNode<E>> path(E e) {
        ArrayList<TreeNode<E>> list = new ArrayList<>();
        TreeNode<E> current = root;
        while (current != null) {
            list.add(current);
            if (e.compareTo(current.element) > 0) {
                current = current.right;
            } else if (e.compareTo(current.element) < 0) {
                current = current.left;
            } else {
                break;
            }
        }
        return list;
    }

    @Override
    public int getSize() {
        return size;
    }

    public TreeNode<E> getRoot() {
        return root;
    }

    @Override
    public boolean isEmpty() {
        return getSize() == 0;
    }

    @Override
    public Iterator<E> iterator() {
        return null;
    }

    public int getHeight() {
        return getHeight(root);
    }

    private int getHeight(TreeNode<E> root) {
        if (root == null) return 0;
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
