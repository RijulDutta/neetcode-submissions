class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;

        q.push({beginWord, 1});
        if(s.find(beginWord) != s.end()) s.erase(beginWord);

        while(!q.empty()){
            int levelSize = q.size();

            for(int i=0; i<levelSize; i++){
                auto [curr, level] = q.front();
                q.pop();

                if(curr == endWord) return level;

                for(int i=0; i<curr.size(); i++){
                    string copy = curr;
                    for(char c='a'; c<='z'; c++){
                        copy[i] = c;
                        if(s.find(copy) != s.end()){
                            q.push({copy, level+1});
                            s.erase(copy);
                        }
                    }
                }
            }
        }
        return 0;
    }
};