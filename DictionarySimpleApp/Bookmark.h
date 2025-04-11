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

    void loadFromFile();

    void insert(string word);

    bool contains(string word);

    void display();
};
// implement the above functions here....

bool BookMarkList::contains(string word)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == word)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

BookMarkList::BookMarkList()
{
    head = nullptr;
    loadFromFile();
}

void BookMarkList::loadFromFile()
{
    ifstream inFile("InputFile/Bookmark.txt");
    if (!inFile)
    {
        cout << "Couldn't open file for reading!" << endl;
        return;
    }
    string word;
    while (getline(inFile, word))
    {
        if (!word.empty())
        {
            Node *newNode = new Node;
            newNode->data = word;
            newNode->next = nullptr;

            if (!head)
            {
                head = newNode;
            }
            else
            {
                Node *cur = head;
                while (cur->next)
                {
                    cur = cur->next;
                }
                cur->next = newNode;
            }
        }
    }

    inFile.close();
}

void BookMarkList::insert(string word)
{
    if (contains(word))
    {
        return;
    }
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
    outFile.open("InputFile/Bookmark.txt", ios::app);
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