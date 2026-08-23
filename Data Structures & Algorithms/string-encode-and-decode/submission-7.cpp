class Solution {
public:

    string encode(vector<string>& strs) { 
        string ans;
        for(string st: strs){
            int currSize = st.size();
            ans += to_string(currSize) + "#" + st; 
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j-i));
            string word = s.substr(j+1, len);
            ans.push_back(word);
            i = j+len+1;
        }
        return ans;
    }
};

