// ------------------------------------------------------------------------------------
//
// Trie For AUTOCOMPLETE / AUTOCORRECT
//
// ------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cctype>
#include <sstream>

#include "TrieNode.h"

using namespace std;

string normalizeString(const string &input)
{
    stringstream ss(input);
    string word, result;
    while (ss >> word)
    {
        // dùng stringstream để đọc từng từ
        if (!result.empty())
        {
            result += " "; // chèn khoảng trắng giữa các từ
        }
        result += word;
    }
    while (result[result.size() - 1] == ' ')
    {
        result.erase(result.size() - 1);
    }
    return result;
}

class Trie
{
private:
    TrieNode *root;
    int counter; // counter to keep track of the number added to the trie
public:
    // defaut constructor
    Trie();

    // destructor
    ~Trie();

    // helper function for destructor
    void clear(TrieNode *node);

    // function for importing dictionary file
    void import_txt();

    // function for importing binary file
    void import_bin();

    // insert data - string word into trie
    void insert(string term);

    // insert data - string word , string def into trie
    void insert(string term, string def);

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

Trie::~Trie()
{
    clear(root);
    delete root;
}

void Trie::clear(TrieNode *node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            clear(node->children[i]);
            delete node->children[i];
            node->children[i] = nullptr;
        }
    }
}

void Trie::import_txt()
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
    while (getline(textFile, line) && i < 5021)
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
            word = normalizeString(word);
            this->insert(word, def);
            i++;
        }
    }

    textFile.close();
}

void Trie::import_bin()
{
    ifstream binaryFile;
    binaryFile.open("InputFile/EnglishDictionary.dat", ios::binary);
    if (!binaryFile)
    {
        cout << "Couldn't open file!" << endl;
        return;
    }
    int i = 0;
    while (binaryFile.peek() != EOF && i < 5021)
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
        word = normalizeString(word);
        this->insert(word, def);
        i++;
    }
    binaryFile.close();
}

void Trie::insert(string term)
{
    term = normalizeString(term);
    if (term.empty())
        return;
    TrieNode *cur = root;
    int len = term.size();
    TrieNode *ans = root;
    for (int i = 0; i < len; i++)
    {
        term[i] = tolower(term[i]);
        int j = term[i] - 'a';
        if (j < 0 || j >= 26)
        {
            return; // no number or special char
        }

        if (cur->children[j] == nullptr)
        {
            cur->children[j] = new TrieNode(term[i]);
        }
        ans = cur;
        cur = cur->children[j];
    }
    counter++;
    cur->value = counter;
}

void Trie::insert(string term, string def)
{
    term = normalizeString(term);
    if (term.empty())
        return;
    TrieNode *cur = root;
    int len = term.size();
    TrieNode *ans = root;
    for (int i = 0; i < len; i++)
    {
        term[i] = tolower(term[i]);
        int j = term[i] - 'a';
        if (j < 0 || j >= 26)
        {
            return; // no number or special char
        }

        if (cur->children[j] == nullptr)
        {
            cur->children[j] = new TrieNode(term[i]);
        }
        ans = cur;
        cur = cur->children[j];
    }
    counter++;
    ans->def = def;
    cur->def = def;
    cur->value = counter;
}

bool Trie::search(string key)
{
    if (key.empty())
        return false;
    TrieNode *cur = root;
    long int len = key.size();
    for (int i = 0; i < len; i++)
    {
        // term[i] = tolower(term[i]);
        int j = key[i] - 'a';

        if (j < 0 || j >= 26 || cur->children[j] == nullptr)
            return false;

        // if word matched
        cur = cur->children[j];
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
    TrieNode *ans = root;
    int len = prefix.size();
    string new_prefix = "";
    for (int i = 0; i < len; i++)
    {
        char c = tolower(prefix[i]);
        int j = c - 'a';
        if (j < 0 || j > 26)
            return false;
        if (cur->children[j])
        {
            ans = cur;
            cur = cur->children[j];
            new_prefix += c;
        }
        else
        {
            break;
        }
    }
    if (ans->def != "")
    {
        cout << new_prefix << " " << ans->def;
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
    dfs(cur, new_prefix);
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
    if (node == nullptr)
        return;
    cout << " " << prefix;
    cout << node->node_char;

    TrieNode *ans = node;
    while (node != nullptr)
    {
        int pos = 0;
        while (node->children[pos] == nullptr && pos < 26)
        {
            pos++;
        }
        if (pos >= 26)
            break;
        ans = node;
        node = node->children[pos];
        cout << node->node_char;
    }
    if (ans != nullptr)
    {
        cout << ans->def;
    }
    cout << endl;
}
