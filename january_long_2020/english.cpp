#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ALPHABET_SIZE = 26; 

struct TrieNode 
{ 
    TrieNode *children[ALPHABET_SIZE];
    int nos;
    int depth;
    bool isEndOfWord; 
}; 
  
TrieNode* getNode(void) 
{ 
    TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
    pNode->nos=0;
    pNode->depth=0;
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
void insert(TrieNode *root, string key) 
{ 
    TrieNode *pCrawl = root;
    int depth=0;
    printf("inserting key -> %s\n",key.c_str());
    // pCrawl->nos++;
  
    printf("node -> (%d,%d)\n",pCrawl->nos,pCrawl->depth);
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
        pCrawl->depth=++depth;
        pCrawl->nos++;
        printf("node -> (%d,%d)\n",pCrawl->nos,pCrawl->depth);
    } 
  
    pCrawl->isEndOfWord = true; 
} 
  
bool search(TrieNode *root, string key) 
{ 
    TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string keys[n];
        TrieNode *root = getNode();  
        root->nos=0;
        root->depth=0;

        for(int i=0;i<n;i++) {
            cin>>keys[i];
        }
        
        for(int i=0;i<n;i++) {
            cout<<keys[i]<<endl;
            insert(root,keys[i]);
        }
    }
    return 0;
}