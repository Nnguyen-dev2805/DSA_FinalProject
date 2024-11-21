// ------------------------------------------------------------------------------------
//
// Bookmarks
//
// ------------------------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// node for bookmark class
struct Node
{
    string data;
    Node *next;
};

class BookMarkList
{
private:
    Node *head;

public:
    BookMarkList();

    void insert(string word);

    void display();
};
// implement the above functions here....
BookMarkList::BookMarkList()
{
    head = nullptr;
}

void BookMarkList::insert(string word)
{
    Node *newNode = new Node;
    newNode->data = word;
    newNode->next = nullptr;
    Node *cur = head;
    if (!head)
    {
        head = newNode;
    }
    else
    {
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    ofstream outFile;
    outFile.open("Bookmark.txt", ios::app);
    if (!outFile)
    {
        cout << "Couldn't open file!" << endl;
    }
    else
    {
        outFile << word << endl;
    }
    outFile.close();
}

void BookMarkList::display()
{
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << " " << cur->data << endl;
        cur = cur->next;
    }
}