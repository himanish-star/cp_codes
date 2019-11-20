class Solution {
public:
    
    int bfs(string beginWord,string endWord, map<string,vector<string>> &regexToWord) {
        queue<string> qu;
        qu.push(beginWord);
        
        int cost=0;
        map<string,int> vis;
        while(qu.size()) {
            int count=qu.size();
            cost++;
            while(count--) {
                string s=qu.front();
                qu.pop();
                
                if(vis[s])
                    continue;
                
                vis[s]=1;
                
                // cout<<s<<endl;
                
                if(endWord==s)
                    return cost;
                
                for(int i=0;i<s.size();i++) {
                    string regex=s;
                    regex[i]='*';
                    for(int j=0;j<regexToWord[regex].size();j++) {
                        string nextWord=regexToWord[regex][j];
                        if(!vis[nextWord])
                            qu.push(nextWord);
                    }
                }
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> regexToWord;
        for(int i=0;i<wordList.size();i++) {
            for(int j=0;j<wordList[i].size();j++) {
                string regex=wordList[i];
                regex[j]='*';
                regexToWord[regex].push_back(wordList[i]);
            }
        }
        
        return bfs(beginWord,endWord,regexToWord);
    }
};