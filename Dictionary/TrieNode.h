// ------------------------------------------------------------------------------------
//
// Trie Node For Trie Implementation
//
// ------------------------------------------------------------------------------------

#pragma once

class TrieNode
{
public:
    int value;              // used for indicating ending of string
    TrieNode *children[26]; // all for 26 alphabets
    TrieNode *pNext;
    char node_char;

    // defaut constructor
    TrieNode();

    // paremetried constructor
    TrieNode(char letter);

    // destructor
    ~TrieNode() {};
};
// implement the above functions here....

TrieNode::TrieNode()
{
    value = 0;
    for (int i = 0; i < 26; i++)
    {
        children[i] = nullptr;
    }
}

TrieNode::TrieNode(char letter)
{
    node_char = letter;
    for (int i = 0; i < 26; i++)
    {
        children[i] = nullptr;
    }
}