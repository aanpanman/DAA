#include <bits/stdc++.h>
using namespace std;

struct Trie {
    string key;
    int cnt;
    unordered_map<char, Trie*> map;
};

Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->cnt = 0;
    return node;
}

void insert(Trie*& root, string& str)
{
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) 
    {
        char x = str[i];
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();
        temp = temp->map[x];
    }
    temp->key = str;
    temp->cnt += 1;
}

bool preorder(Trie* temp, int& maxcnt, string& key)
{
    if (temp == NULL)
        return false;
    for (auto it : temp->map) 
    {
        if (maxcnt < it.second->cnt) 
        {
            key = it.second->key;
            maxcnt = it.second->cnt;
        }
        preorder(it.second, maxcnt, key);
    }
}
 
void mostFrequentWord(string arr[], int n)
{
    Trie* root = getNewTrieNode();
    for (int i = 0; i < n; i++)
    {
        insert(root, arr[i]);
    }
    string key;
    int cnt = 0;
    preorder(root, cnt, key);
    cout << "The word that occurs most is : " << key << endl;
    cout << "No of times: " << cnt << endl;
}

int main()
{
    string arr[] = { "whenever", "people", "read", "a", "book", "they", "travel", "to", "another", "place", "a", "book", "can", "transform", "a", "person", "in", "many", "ways" };
    int n = sizeof(arr) / sizeof(arr[0]);
    mostFrequentWord(arr, n);
    return 0;
}