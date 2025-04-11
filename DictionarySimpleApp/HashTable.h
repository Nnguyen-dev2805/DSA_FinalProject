// ------------------------------------------------------------------------------------
//
// Hash Table For Dictionary
//
// ------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

#define DICTIONARY_HASHTABLE_SIZE 5021

using namespace std;

class HashNode
{
public:
    string word;
    string def;
    HashNode *next;

    HashNode()
    {
        word = "";
        def = "";
        next = nullptr;
    }

    HashNode(string word, string def)
    {
        this->word = word;
        this->def = def;
        next = nullptr;
    }
};
// implement the above functions here....

class HashTable
{
private:
    HashNode *dictTable[DICTIONARY_HASHTABLE_SIZE]; // array of HashNode pointers
    unsigned int words_entered;                     // number of words entered
public:
    // defaut constructor
    HashTable();

    // destructor
    ~HashTable();

    // insert a word
    void insert(string word, string def);

    // returns the definition if found word in the dict
    string getDefinition(string word);

    // hash function
    int hashFunction(string word);

    // load words from .txt file
    void loadWordsFromFile();

    // load words from binary file
    void loadWordsFromBinaryFile();

    // function for DEBUG
    void display();
};
// implement the above functions here....

HashTable::HashTable()
{
    words_entered = 0;

    for (int i = 0; i < DICTIONARY_HASHTABLE_SIZE; i++)
    {
        dictTable[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < DICTIONARY_HASHTABLE_SIZE; i++)
    {
        HashNode *cur = dictTable[i];
        while (cur != nullptr)
        {
            HashNode *temp = cur;
            cur = cur->next;
            delete temp;
        }
        dictTable[i] = nullptr;
    }
}

// polynomial rolling hash
// learn about here https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
int HashTable::hashFunction(string word)
{
    int g = 31;
    unsigned int sum = 0;
    for (int i = 0; i < word.size(); i++)
    {
        sum = (sum * g + (int)word[i]) % DICTIONARY_HASHTABLE_SIZE;
    }
    return sum;
}

void HashTable::insert(string word, string def)
{
    int index = hashFunction(word);

    HashNode *temp = new HashNode(word, def);

    // if there's already a word at the hash table, traverse linked list of nodes
    if (dictTable[index] != nullptr)
    {
        // add node to head of linked list
        temp->next = dictTable[index];
        dictTable[index] = temp;
    }
    else
        dictTable[index] = temp;
    words_entered++;
}

string HashTable::getDefinition(string word)
{
    int index = hashFunction(word);

    // if word is found at hash index
    if (dictTable[index] == nullptr)
        return " Word doesn't exist!";
    else
    {
        HashNode *cur = dictTable[index];
        while (cur != nullptr)
        {
            if (cur->word == word)
            {
                return cur->def;
            }
            cur = cur->next;
        }
    }
    return " Word doesn't exist!";
}

void HashTable::loadWordsFromFile()
{
    ifstream textFile;

    textFile.open("InputFile/EnglishDictionary.txt");

    if (!textFile)
    {
        cout << "Couldn't open file!" << endl;
        return;
    }

    int i = 0;
    string line;
    while (getline(textFile, line) && i < DICTIONARY_HASHTABLE_SIZE)
    {
        string word, def;

        if (line != "")
        {
            auto it = line.begin();
            while (it != line.end() && *it != ' ')
            {
                word.push_back(*it);
                it++;
            }
            while (it != line.end())
            {
                def.push_back(*it);
                it++;
            }

            // insert word and definition into dictionary
            this->insert(word, def);
            i++;
        }
    }

    textFile.close();
}

void HashTable::loadWordsFromBinaryFile()
{
    ifstream binaryFile;
    binaryFile.open("InputFile/EnglishDictionary.dat", ios::binary);
    if (!binaryFile)
    {
        cout << "Couldn't open file!" << endl;
        return;
    }
    int i = 0;
    while (binaryFile.peek() != EOF && i < DICTIONARY_HASHTABLE_SIZE)
    {
        auto readString = [](ifstream &binaryFile) -> string
        {
            size_t len;
            binaryFile.read(reinterpret_cast<char *>(&len), sizeof(len));
            string str(len, ' ');
            binaryFile.read(&str[0], len);
            return str;
        };
        string word = readString(binaryFile);
        string def = readString(binaryFile);
        this->insert(word, def);
        i++;
    }
    binaryFile.close();
}

void HashTable::display()
{
    for (int i = 0; i < DICTIONARY_HASHTABLE_SIZE; i++)
    {
        HashNode *cur = dictTable[i];
        do
        {
            cout << i << ": " << cur->word;
            if (cur->word != "")
                cout << " [" << cur->def << "]";
            cur = cur->next;
            if (cur != nullptr)
                cout << " -->";
        } while (cur != nullptr);
        cout << endl;
    }
    cout << "Words: " << words_entered << endl;
}
