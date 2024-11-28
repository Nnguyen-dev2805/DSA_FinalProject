// Class BST

#pragma once

#include <iostream>
#include "BankAccount.h"

using namespace std;

template <typename T>
class BST
{
private:
    struct Node
    {
        T data;
        Node *pLeft, *pRight;
        Node(T value)
        {
            this->data = value;
            this->pLeft = nullptr;
            this->pRight = nullptr;
        }
    };

    Node *root;

    // helper function to destructor
    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;

        // Xóa đệ quy con trái
        deleteTree(node->pLeft);

        // Xóa đệ quy con phải
        deleteTree(node->pRight);

        // Xóa node hiện tại
        delete node;
    }

    // helper function to insert
    void addNode(Node *&node, Node *newNode)
    {
        if (node == nullptr)
        {
            node = newNode;
        }
        else if (node->data < newNode->data)
        {
            addNode(node->pRight, newNode);
        }
        else if (node->data > newNode->data)
        {
            addNode(node->pLeft, newNode);
        }
        else
        {
            return;
        }
    }

    // helper function to delete
    bool removeNode(Node *&node, T value)
    {
        if (node == nullptr)
            return false;
        if (node->data > value)
        {
            return removeNode(node->pLeft, value);
        }
        if (node->data < value)
        {
            return removeNode(node->pRight, value);
        }
        if (node->pRight != nullptr && node->pLeft != nullptr)
        {
            Node *cur = node->pRight;
            while (cur->pLeft != nullptr)
            {
                cur = cur->pLeft;
            }
            node->data = cur->data;
            removeNode(node->pRight, cur->data);
        }
        else
        {
            Node *cur = node;
            if (node->pLeft == nullptr)
            {
                node = node->pRight;
            }
            else if (node->pRight == nullptr)
            {
                node = node->pLeft;
            }
            delete cur;
        }
        return true;
    }

    // helper function for search
    Node *findNode(Node *&node, T value)
    {
        if (node == nullptr || node->data == value)
        {
            return node;
        }
        if (node->data < value)
        {
            return findNode(node->pRight, value);
        }
        else
        {
            return findNode(node->pLeft, value);
        }
    }

    // helper function for calc height tree
    int HeightTree(Node *node)
    {
        if (node == nullptr)
            return 0;
        int h1 = HeightTree(node->pRight);
        int h2 = HeightTree(node->pLeft);
        return 1 + max(h1, h2);
    }

    // helper function for display
    void printInOrder(Node *node)
    {
        if (node == nullptr)
            return;
        printInOrder(node->pLeft);
        // cout << node->data << endl;
        node->data.display();
        printInOrder(node->pRight);
    }
    void FileInOrder(Node *node, ofstream &outfile)
    {
        if (node == nullptr)
            return;
        FileInOrder(node->pLeft, outfile);
        outfile << node->data.accountID << endl;
        outfile << node->data.accountHolderName << endl;
        outfile << node->data.bankName << endl;
        outfile << node->data.balance << endl;
        FileInOrder(node->pRight, outfile);
    }

public:
    BST()
    {
        this->root = nullptr;
    }

    ~BST()
    {
        deleteTree(root);
    }

    bool isEmptyTree()
    {
        return root == nullptr;
    }

    // insert use recursive
    void insert(T value)
    {
        Node *newNode = new Node(value);
        addNode(this->root, newNode);
    }

    // insert no use recursive
    void insertNoRecursive(T value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            cout << "Them nut thanh cong!" << endl;
            return;
        }
        Node *cur = root;
        Node *parent = nullptr;
        while (cur != nullptr)
        {
            parent = cur;
            if (value == cur->data)
            {

                cout << "Nut da ton tai trong cay!" << endl;
                return;
            }

            if (value > cur->data)
            {
                cur = cur->pRight;
            }
            else
            {
                cur = cur->pLeft;
            }
        }
        if (value > parent->data)
        {
            parent->pRight = newNode;
            cout << "Them nut thanh cong!" << endl;
        }
        else
        {
            parent->pLeft = newNode;
            cout << "Them nut thanh cong!" << endl;
        }
    }

    // delete use recursive
    void deleteNode(T value)
    {
        if (removeNode(this->root, value))
        {
            cout << "Xoa tai khoan thanh cong (de quy)!" << endl;
        }
        else
        {
            // cout << "Not found";
            cout << "No found " << value.getAccountID() << " in Tree" << endl;
        }
    }

    // delete no use recursive
    bool deleteNoRecursive(T value)
    {
        Node *cur = root;
        Node *parent = nullptr;
        while (cur != nullptr && cur->data != value)
        {
            parent = cur;
            if (value > cur->data)
            {
                cur = cur->pRight;
            }
            else
            {
                cur = cur->pLeft;
            }
        }
        if (cur == nullptr)
        {
            return false;
        }
        if (cur->pRight != nullptr && cur->pLeft != nullptr)
        {
            Node *minNode = cur->pRight;
            Node *minNodeParent = cur;
            // nhỏ nhất bên phải
            while (minNode->pLeft != nullptr)
            {
                minNodeParent = minNode;
                minNode = minNode->pLeft;
            }
            // cập nhật giá trị của nút cha
            cur->data = minNode->data;
            if (minNodeParent == cur)
            {
                minNodeParent->pRight = minNode->pRight;
            }
            else
            {
                minNodeParent->pLeft = minNode->pRight;
            }
            // cập nhật nút cur và parent để xóa nút minNode
            // cur = minNode;
            delete minNode;
            // parent = minNodeParent;
        }
        else
        {
            // Trường hợp có 0 con và 1 con
            Node *child = (cur->pLeft != nullptr) ? cur->pLeft : cur->pRight;
            if (cur == root)
            {
                root = child;
            }
            else if (cur == parent->pLeft)
            {
                parent->pLeft = child;
            }
            else
            {
                parent->pRight = child;
            }
            delete cur;
        }
        return true;
    }

    Node *searchNode(T value)
    {
        return findNode(this->root, value);
    }

    int getHeight()
    {
        return HeightTree(root);
    }

    void printTree()
    {
        if (root == nullptr)
        {
            cout << "Cay rong." << endl;
            return;
        }
        printInOrder(root);
    }
    // ghi ra file
    void printFile(ofstream &outfile)
    {
        if (root == nullptr)
        {
            cout << "Cay rong." << endl;
            return;
        }
        FileInOrder(root, outfile);
    }
};
