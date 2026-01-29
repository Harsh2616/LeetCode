class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());  // Step 1
        
        int n = s.size();
        string result;
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++; // skip spaces
            
            if (i >= n) break;
            
            int j = i;
            while (j < n && s[j] != ' ') j++; // find word
            
            reverse(s.begin() + i, s.begin() + j); // reverse word
            
            if (!result.empty()) result += " ";
            result.append(s.substr(i, j - i));
            
            i = j;
        }
        return result;
        
    }
};