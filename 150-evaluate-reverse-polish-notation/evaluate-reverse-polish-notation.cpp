class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &t : tokens) {
            if (t.size() == 1 && !isdigit(t[0])) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (t[0] == '+') st.push(b + a);
                else if (t[0] == '-') st.push(b - a);
                else if (t[0] == '*') st.push(b * a);
                else st.push(b / a);
            } 
            else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};