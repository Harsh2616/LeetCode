class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26);
        vector<bool> visited(26, false);
        
        // Store last occurrence of each character
        for(int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;
        
        string result = "";
        
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if(visited[c - 'a'])
                continue;
            
            while(!result.empty() && 
                  result.back() > c && 
                  lastIndex[result.back() - 'a'] > i) {
                
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(c);
            visited[c - 'a'] = true;
        }
        
        return result;
    }
};
