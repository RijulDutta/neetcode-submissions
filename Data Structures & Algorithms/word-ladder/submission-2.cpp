class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_set<string>track;

        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        track.insert(beginWord);

        while(!q.empty()){
            int levelSize = q.size();
    
            for(int k=0; k<levelSize; k++){
                auto [curr, level] = q.front();
                q.pop();

                if(curr == endWord) return level;

                for(int i=0; i<curr.size(); i++){
                    string original = curr;
                    for(int j=0; j<26; j++){
                        curr[i] = (char)('a' + j);
                        if(track.find(curr) == track.end() && s.find(curr) != s.end()){
                            q.push({curr, level+1});
                            track.insert(curr);
                        }
                    }
                    curr = original;
                }
            }   
        }

        return  0;
    }
};
