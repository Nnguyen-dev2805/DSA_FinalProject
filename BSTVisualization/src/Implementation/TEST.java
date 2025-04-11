package Implementation;

public class TEST {
    public static void main(String[] args) {
        BST<String>bst = new BST<>();
        bst.insert("Nhat Nguyen");
        bst.insert("Quang Huy");
        bst.insert("Hoang Ha");
        bst.insert("Tai Dang");
        bst.inorder();
    }
}
