#include "BST.h"
#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void displayMenu()
{
    cout << "\n========== MENU ==========\n" << endl;
    cout << "0. Hien thi danh sach tai khoan" << endl;
    cout << "1. Them tai khoan (de quy)" << endl;
    cout << "2. Them tai khoan (khong de quy)" << endl;
    cout << "3. Xoa tai khoan (de quy)" << endl;
    cout << "4. Xoa tai khoan (khong de quy)" << endl;
    cout << "5. Tim kiem tai khoan" << endl;
    cout << "6. Hien thi chieu cao cua cay" << endl;
    cout << "7. Thoat" << endl;
    cout << "\n==========================\n"
         << endl;
    cout << "Chon mot tuy chon: ";
}


void readfromFile(BST<BankAccount> &tree)
    {
        ifstream infile("account.txt");
        if (!infile)
        {
            cout << "Couldn't open file for reading!" << endl;
            return;
        }

        string line;
        
        while (getline(infile, line))
        {
            stringstream ss(line);
            vector<string> words;
            string word;
            while (ss >> word)
            {
                words.push_back(word);
            }
            if (words.size() <= 3) continue;
            int id = stoi(words[0]);
            double balance = stod(words[words.size() - 1]);
            string bank_name = words[words.size() - 2];
            string name = "";
            for (int i = 1; i < words.size() - 2; i++)
            {
                name += (words[i] + " ");
            }
            if(!name.empty())
            {
                name.pop_back();
            }
            
            BankAccount account(id,name,bank_name,balance);
            tree.insert(account);
        }
        infile.close();
}

void addtoFile(const BankAccount &account)
{
    ofstream outfile ("account.txt", ios::app);
    if(!outfile)
    {
            cout << "Couldn't open file for add!" << endl;
            return;
    }
    string line = "";
    line += to_string(account.accountID) + " ";
    line += account.accountHolderName + " " ;
    line += account.bankName + " ";
    line += to_string(account.balance);
    outfile << endl;
    outfile << line;
    outfile.close();
}

void deletefromFile(int id)
{
    ifstream infile ("account.txt");
    if(!infile)
    {
            cout << "Couldn't open file for add!" << endl;
            return;
    }
    string line = "";
    vector<string> lines;
    while(getline(infile,line))
    {
        stringstream ss(line);
        string word;
        ss >> word;
        if (stoi(word) != id)
        {
            lines.push_back(line);
        }
    }

    infile.close();

    ofstream outfile("account.txt");
    if(!outfile)
    {
        cout << "Couldn't open file" << endl;
        return;       
    }

    for (string temp : lines)
    {
        outfile << temp <<endl;
    }
    outfile.close();

}

int main()
{
    BST<BankAccount> tree;
    readfromFile(tree);
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
            addtoFile(account);
            cout << "Them tai khoan thanh cong (de quy)!" << endl;
            break;
        }
        case 2:
        {
            BankAccount account;
            cout << "Nhap thong tin tai khoan (them khong de quy):\n";
            account.enterValue();
            tree.insertNoRecursive(account);
            addtoFile(account);
            cout << "Them tai khoan thanh cong (khong de quy)!" << endl;
            break;
        }
        case 3:
        {
            int accountID;
            cout << "Nhap ID tai khoan can xoa (de quy): ";
            cin >> accountID;
            deletefromFile(accountID);
            tree.deleteNode(BankAccount(accountID, "", "", 0.0));
            break;
        }
        case 4:
        {
            int accountID;
            cout << "Nhap ID tai khoan can xoa (khong de quy): ";
            cin >> accountID;
            deletefromFile(accountID);
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
