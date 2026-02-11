class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s) {
            if(!st.empty() && st.top() == c) {
                st.pop();  // Remove duplicate
            } else {
                st.push(c);
            }
        }
        // Build result string from stack
        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
