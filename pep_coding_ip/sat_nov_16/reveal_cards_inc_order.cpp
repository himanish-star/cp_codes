class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> deckIndex;
        sort(deck.begin(),deck.end());
        for(int i=0;i<deck.size();i++) {
            deckIndex.push(i);
        }
        
        vector<int> result(deck.size());
        for(int i=0;i<deck.size() && deckIndex.size();i++) {
            result[deckIndex.front()]=deck[i];
            deckIndex.pop();
            if(deckIndex.size()) {
                deckIndex.push(deckIndex.front());
                deckIndex.pop();
            }
        }
        return result;
    }
};
