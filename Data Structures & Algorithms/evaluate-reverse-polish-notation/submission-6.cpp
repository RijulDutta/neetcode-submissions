class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;

        for(string token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int op2 = stoi(st.top());
                st.pop();
                int op1 = stoi(st.top());
                st.pop();
                int result = getResult(op1, op2, token);
                st.push(to_string(result));
            }else{
                st.push(token);
            }
        }

        return stoi(st.top());
    }

    int getResult(int op1, int op2, string operand){
        char c = operand[0];

        switch(c){
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
            default: return 0;
        }
    }
};
