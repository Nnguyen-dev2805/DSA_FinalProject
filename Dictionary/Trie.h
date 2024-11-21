// ------------------------------------------------------------------------------------
//
// Trie For AUTOCOMPLETE / AUTOCORRECT
//
// ------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "TrieNode.h"

using namespace std;
class Trie
{
private:
    TrieNode *root;
    int counter; // counter to keep track of the number added to the trie
public:
    // defaut constructor
    Trie();

    // destructor
    ~Trie() {};

    // function for importing dictionary file
    void import_txt();

    // insert data into trie
    void insert(string term);

    // function for searching word
    bool search(string key);

    // for finding possible combinations
    bool get_prefix(string prefix);

    // traversing common path
    void dfs(TrieNode *node, string prefix);

    // printing all combinations
    void dfs2(TrieNode *node, string prefix);
};
// implement the above functions here....

Trie::Trie()
{
    root = new TrieNode();
    counter = 0;
}
void Trie::import_txt()
{
    int count = 0;
    string term;

    ifstream get_file("EnglishDictionary.txt");

    if (!get_file)
    {
        cout << "Couldn't open file!" << endl;
        return;
    }

    while (!get_file.eof())
    {
        string word;
        getline(get_file, term);

        if (term != "")
        {
            int index = 0;
            while (index < term.size() && term[index] != ' ')
            {
                word.push_back(term[index]);
                index++;
            }
        }
        insert(word);
        count++;
        if (count >= 28102)
        {
            break;
        }
    }

    get_file.close();
}

void Trie::insert(string term)
{
    TrieNode *cur = root;
    int len = term.size();

    for (int i = 0; i < len; i++)
    {
        int j = term[i] - 'a';

        if (j < 0)
        {
            return; // no number or special char
        }

        if (!cur->children[j])
        {
            cur->children[j] = new TrieNode(term[i]);
        }
        cur = cur->children[j];
    }
    counter++;
    cur->value = counter;
}

bool Trie::search(string key)
{
    TrieNode *cur = root;
    long int len = key.size();
    for (int i = 0; i < len; i++)
    {
        int j = key[i] - 'a';

        // if word matched
        if (cur->children[j])
        {
            cur = cur->children[j];
        }
        else
        {
            return false; // word dont match
        }
    }
    if (cur->value != 0)
    {
        return true;
    }
    else
    {
        return false; // just a prefix to another word
    }
}

// find words start with the prefix,if not found try with a shorter prefix
bool Trie::get_prefix(string prefix)
{
    TrieNode *cur = root;
    int len = prefix.size();
    for (int i = 0; i < len; i++)
    {
        int j = prefix[i] - 'a';
        if (cur->children[j])
        {
            cur = cur->children[j];
        }
        else
        {
            // if entered wrong then remove last alphabet and check again and repeat this until it find a word
            string prefix1 = prefix.substr(0, prefix.size() - 1);
            if (!prefix1.empty())
            {
                if (get_prefix(prefix1))
                    return true;
            }
            else
            {
                return false;
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i] != nullptr)
            flag = false;
    }

    if (!flag)
        cout << "Do you mean..." << endl
             << endl;
    dfs(cur, prefix);
    return true;
}

// find words start with the prefix
void Trie::dfs(TrieNode *node, string prefix)
{
    int pos = 0;
    while (pos < 26)
    {
        if (node->children[pos] != nullptr)
        {
            dfs2(node->children[pos], prefix);
        }
        pos++;
    }
    cout << endl;
}

// print all words can be formed form a node
void Trie::dfs2(TrieNode *node, string prefix)
{
    cout << " " << prefix;
    cout << node->node_char;
    while (node != nullptr)
    {
        int pos = 0;
        while (node->children[pos] == nullptr && pos < 26)
        {
            pos++;
        }
        node = node->children[pos];
        if (node != nullptr)
        {
            cout << node->node_char;
        }
    }
    cout << endl;
}
