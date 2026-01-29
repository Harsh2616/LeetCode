class Solution {
public:
    int match(const string &a, const string &b){
        int cnt = 0;
        for(int i=0;i<6;i++)
            if(a[i]==b[i]) cnt++;
        return cnt;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        for(int t=0; t<30; t++){
            // frequency table
            vector<vector<int>> freq(6, vector<int>(26, 0));
            for(auto &w : candidates){
                for(int i=0;i<6;i++)
                    freq[i][w[i]-'a']++;
            }
            // score words
            string bestWord;
            int bestScore = -1;
            for(auto &w : candidates){
                int score = 0;
                for(int i=0;i<6;i++)
                    score += freq[i][w[i]-'a'];
                if(score > bestScore){
                    bestScore = score;
                    bestWord = w;
                }
            }
            int matches = master.guess(bestWord);
            if(matches == 6) return;
            vector<string> next;
            for(auto &w : candidates){
                if(match(bestWord, w) == matches)
                    next.push_back(w);
            }
            candidates = next;
        }
    }
};
