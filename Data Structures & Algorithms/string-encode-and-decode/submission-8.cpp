class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string str: strs){
            int length = str.size();
            ans += to_string(length) + '#' + str;
        }
        cout<<ans;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                int length = stoi(s.substr(start, i-start));
                string word = s.substr(i+1, length);
                ans.push_back(word);
                start = i+length+1;
                i = start-1;
            }
        }

        return ans;
    }
};
