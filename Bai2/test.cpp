#include "BST.h"
#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void readfromFile(BST<BankAccount> &tree)
    {
        ifstream infile("textcase.txt");
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

int main()
{
	BST<BankAccount> tree;
	readfromFile(tree);
	tree.printTree();
	return 0;
}