#include <iostream>
#include "BST.h"
#include "BankAccount.h"

using namespace std;

void displayMenu()
{
    cout << "========== MENU ==========" << endl;
    cout << "0. Hien thi danh sach tai khoan" << endl;
    cout << "1. Them tai khoan (de quy)" << endl;
    cout << "2. Them tai khoan (khong de quy)" << endl;
    cout << "3. Xoa tai khoan (de quy)" << endl;
    cout << "4. Xoa tai khoan (khong de quy)" << endl;
    cout << "5. Tim kiem tai khoan" << endl;
    cout << "6. Hien thi chieu cao cua cay" << endl;
    cout << "7. Thoat" << endl;
    cout << "==========================\n"
         << endl;
    cout << "Chon mot tuy chon: ";
}

int main()
{
    BST<BankAccount> tree;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
        {
            cout << "Danh sach tai khoan hien co: " << endl;
            tree.printTree();
            break;
        }
        case 1:
        {
            BankAccount account;
            cout << "Nhap thong tin tai khoan (them de quy):\n";
            account.enterValue();
            tree.insert(account);
            cout << "Them tai khoan thanh cong (de quy)!" << endl;
            break;
        }
        case 2:
        {
            BankAccount account;
            cout << "Nhap thong tin tai khoan (them khong de quy):\n";
            account.enterValue();
            tree.insertNoRecursive(account);
            cout << "Them tai khoan thanh cong (khong de quy)!" << endl;
            break;
        }
        case 3:
        {
            int accountID;
            cout << "Nhap ID tai khoan can xoa (de quy): ";
            cin >> accountID;
            tree.deleteNode(BankAccount(accountID, "", "", 0.0));
            break;
        }
        case 4:
        {
            int accountID;
            cout << "Nhap ID tai khoan can xoa (khong de quy): ";
            cin >> accountID;
            if (tree.deleteNoRecursive(BankAccount(accountID, "", "", 0.0)))
            {
                cout << "Xoa tai khoan thanh cong (khong de quy)!" << endl;
            }
            else
            {
                cout << "Khong tim thay tai khoan voi ID: " << accountID << endl;
            }
            break;
        }
        case 5:
        {
            int accountID;
            cout << "Nhap ID tai khoan can tim: ";
            cin >> accountID;
            auto node = tree.searchNode(BankAccount(accountID, "", "", 0.0));
            if (node)
            {
                cout << "Tai khoan tim thay:\n";
                node->data.display();
            }
            else
            {
                cout << "Khong tim thay tai khoan voi ID: " << accountID << endl;
            }
            break;
        }
        case 6:
        {
            cout << "Chieu cao cua cay: " << tree.getHeight() << endl;
            break;
        }
        case 7:
        {
            cout << "Thoat chuong trinh." << endl;
            break;
        }
        default:
        {
            cout << "Tuy chon khong hop le. Vui long thu lai." << endl;
            break;
        }
        }
    } while (choice != 7);

    return 0;
}
