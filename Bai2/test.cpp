#include <iostream>
#include "BST.h"  // Include the BST class header

using namespace std;

int main() {
    // Tạo đối tượng BST kiểu int
    BST<int> tree;

    // Thêm các phần tử vào cây
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // In cây theo thứ tự (In-order traversal)
    cout << "Cay BST sau khi them cac phan tu: " << endl;
    tree.printTree();

    // Xóa một node (ví dụ: xóa node có giá trị 10)
    cout << "\nXoa node co gia tri 10:" << endl;
    tree.deleteNoRecursive(10);

    // In cây sau khi xóa node
    cout << "\nCay BST sau khi xoa node 10: " << endl;
    tree.printTree();

    // Thử xóa node không tồn tại (ví dụ: node có giá trị 100)
    cout << "\nXoa node co gia tri 15:" << endl;
    tree.deleteNoRecursive(15);

    // In cây sau khi thử xóa node không tồn tại
    cout << "\nCay BST sau khi thu xoa node 15: " << endl;
    tree.printTree();

    // Kiểm tra chiều cao của cây
    cout << "\nChieu cao cua cay BST: " << tree.getHeight() << endl;

    return 0;
}
