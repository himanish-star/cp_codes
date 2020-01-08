#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll ALPHABET_SIZE = 26; 

struct TrieNode 
{ 
    TrieNode *children[ALPHABET_SIZE];
    vector<ll> idxs;
    ll nos;
    ll childs;
    ll depth;
    bool isEndOfWord; 
}; 
  
TrieNode* getNode(void) 
{ 
    TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
    pNode->nos=0;
    pNode->depth=0;
    pNode->childs=0;
  
    for (ll i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
void insert(TrieNode *root, string key) 
{ 
    TrieNode *pCrawl = root;
    ll depth=0;
    // printf("inserting key -> %s\n",key.c_str());
    // pCrawl->nos++;
  
    // printf("node -> (%d,%d)\n",pCrawl->nos,pCrawl->depth);
    for (ll i = 0; i < key.length(); i++) 
    { 
        ll index = key[i] - 'a'; 

        if (!pCrawl->children[index]) { 
            pCrawl->children[index] = getNode(); 
            pCrawl->childs++;
            pCrawl->idxs.push_back(index);
        }
  
        // printf("node -> (%d,%d) and child=%d\n",pCrawl->nos,pCrawl->depth,pCrawl->childs);
       
        pCrawl = pCrawl->children[index]; 
        pCrawl->depth=++depth;
        pCrawl->nos++;
    } 
  
    // printf("node -> (%d,%d) and child=%d\n",pCrawl->nos,pCrawl->depth,pCrawl->childs);
    pCrawl->isEndOfWord = true; 
} 

ll computePalin(TrieNode *node) {
    if(node->childs==1 && node->isEndOfWord==false) {
        return computePalin(node->children[node->idxs[0]]);
    } else {
        vector<ll> nextIdxs;
        ll oddsRemain=0,evensRemain=0;
        for(ll i=0;i<node->idxs.size();i++) {
            if(node->children[node->idxs[i]]->nos%2==0) {
                nextIdxs.push_back(node->idxs[i]);
                evensRemain+=node->children[node->idxs[i]]->nos;
            } else {
                oddsRemain++;
                evensRemain+=node->children[node->idxs[i]]->nos-1;
                if(node->children[node->idxs[i]]->nos>=3) {
                    nextIdxs.push_back(node->idxs[i]);
                }
            }
        }

        ll ans=(floor(oddsRemain/2))*pow(floor(node->depth),2);

        if(node->isEndOfWord==true) {
            if(oddsRemain%2==0) {
                ll tempRes=node->nos-oddsRemain-evensRemain;
                ans+=floor((tempRes)/2)*pow(floor(node->depth),2);
            } else {
                ll tempRes=node->nos-oddsRemain-evensRemain+1;
                ans+=floor((tempRes)/2)*pow(floor(node->depth),2);
            }
        }

        for(ll i=0;i<nextIdxs.size();i++) {
            ans+=computePalin(node->children[nextIdxs[i]]);
        }
        return ans;
    }
}

ll compute(TrieNode *node) {
    if(node->childs==1 && node->isEndOfWord==false) {
        return compute(node->children[node->idxs[0]]);
    } else {
        vector<ll> nextIdxs;
        ll oddsRemain=0,evensRemain=0;
        for(ll i=0;i<node->idxs.size();i++) {
            if(node->children[node->idxs[i]]->nos%2==0) {
                nextIdxs.push_back(node->idxs[i]);
                evensRemain+=node->children[node->idxs[i]]->nos;
            } else {
                oddsRemain++;
                evensRemain+=node->children[node->idxs[i]]->nos-1;
                if(node->children[node->idxs[i]]->nos>=3) {
                    nextIdxs.push_back(node->idxs[i]);
                }
            }
        }

        ll ans=(floor(oddsRemain/2))*pow(floor(node->depth/2),2);

        if(node->isEndOfWord==true) {
            if(oddsRemain%2==0) {
                ll tempRes=node->nos-oddsRemain-evensRemain;
                ans+=floor((tempRes)/2)*pow(floor(node->depth),2);
            } else {
                ll tempRes=node->nos-oddsRemain-evensRemain+1;
                ans+=floor((tempRes)/2)*pow(floor(node->depth),2);
            }
        }

        for(ll i=0;i<nextIdxs.size();i++) {
            ans+=compute(node->children[nextIdxs[i]]);
        }
        return ans;
    }
}

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        string keys[n];
        TrieNode *root = getNode(), *palinroot = getNode();  
        root->nos=0,palinroot->nos=0;
        root->depth=0,palinroot->depth=0;

        for(ll i=0;i<n;i++) {
            cin>>keys[i];
        }
        
        ll nopalin=0;
        for(ll i=0;i<n;i++) {
            // cout<<keys[i]<<endl;
            string temp;
            int s=0,e=keys[i].size()-1;
            bool ispalin=true;
            while(e>=s) {
                if(keys[i][s]!=keys[i][e])
                    ispalin=false;
                if(e==s){ 
                    temp.push_back(keys[i][s]);
                    s++;
                    e--;
                } else {
                    temp.push_back(keys[i][s]);
                    temp.push_back(keys[i][e]);
                    s++;
                    e--;
                }
            }
            nopalin+=(ispalin==true);
            insert(root,temp);
            insert(palinroot,keys[i]);
        }
        
        ll ans=0;
        if(nopalin==n) {
            // cout<<"ALL PALIN"<<endl;
            for(ll i=0;i<26;i++) {
                if(palinroot->children[i]) {
                    ans+=computePalin(palinroot->children[i]);
                }
            }
        } else {
            for(ll i=0;i<26;i++) {
                if(root->children[i]) {
                    ans+=compute(root->children[i]);
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}