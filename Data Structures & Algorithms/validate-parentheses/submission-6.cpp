class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        st.push('#');
        int size = s.size();

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                continue;
            }

            if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')){
                st.pop();
            }else{
                return false;
            }
        }

        if(st.top() == '#') return true;
        return false;
    }
};
