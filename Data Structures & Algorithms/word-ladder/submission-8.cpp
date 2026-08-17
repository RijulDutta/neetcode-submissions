class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = beginWord.size();
        unordered_set<string>s(wordList.begin(), wordList.end());
        
        queue<string>q;
        q.push(beginWord);
        if(s.find(beginWord) != s.end()) s.erase(beginWord);
        int ans = 0;

        while(!q.empty()){
            int levelSize = q.size();
            ans++;

            for(int k=0; k<levelSize; k++){
                string curr = q.front();
                q.pop();

                if(curr == endWord) return ans;

                for(int i=0; i<size; i++){
                    string temp = curr;
                    for(char c = 'a'; c<='z'; c++){
                        temp[i] = c;
                        if(s.find(temp) != s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                } 
            }            
        }
        return 0;
    }
};
