// ------------------------------------------------------------------------------------
//
// Trie Node For Trie Implementation
//
// ------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#pragma once

using namespace std;
class TrieNode
{
public:
    string def;
    int value;              // used for indicating ending of string
    TrieNode *children[26]; // all for 26 alphabets
    char node_char;

    // defaut constructor
    TrieNode();

    // paremetried constructor
    TrieNode(char letter);

    // destructor
    ~TrieNode();
};
// implement the above functions here....

TrieNode::TrieNode()
{
    value = 0;
    this->def = "";
    for (int i = 0; i < 26; i++)
    {
        children[i] = nullptr;
    }
}

TrieNode::TrieNode(char letter)
{
    value = 0;
    this->def = "";
    node_char = letter;
    for (int i = 0; i < 26; i++)
    {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode()
{
    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            delete children[i];
            children[i] = nullptr;
        }
    }
}
