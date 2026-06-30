class Solution 
{
 public:int characterReplacement(string s, int k) 
 {
  vector<int> cnt(26);
  int l = 0, ans = 0, mx = 0;
  for (int r = 0; r < s.size(); r++) 
  {
   mx = max(mx, ++cnt[s[r] - 'A']);
   while (r - l + 1 - mx > k)
    cnt[s[l++] - 'A']--;
   ans = max(ans, r - l + 1);
  }
  return ans;
 }
};