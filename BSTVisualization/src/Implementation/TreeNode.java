package Implementation;

public class TreeNode<E extends Comparable<E>> {
    public TreeNode<E> left;
    public TreeNode<E> right;
    public E element;
    public int height = 0;

    public TreeNode(E element) {
        this.element = element;
    }
}
