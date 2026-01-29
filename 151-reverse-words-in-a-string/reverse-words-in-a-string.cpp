class Solution {
public:
    void cleanSpaces(string &s) {
        int i = 0, j = 0, n = s.size();
        
        while (j < n) {
            while (j < n && s[j] == ' ') j++; // skip spaces
            
            while (j < n && s[j] != ' ')
                s[i++] = s[j++]; // copy word
            
            while (j < n && s[j] == ' ') j++; // skip spaces
            
            if (j < n) s[i++] = ' '; // add single space
        }
        s.resize(i);
    }
    
    string reverseWords(string s) {
        cleanSpaces(s);
        reverse(s.begin(), s.end());
        
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};
