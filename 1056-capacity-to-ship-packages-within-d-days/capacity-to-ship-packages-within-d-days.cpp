class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int l = *max_element(w.begin(), w.end());
        int r = accumulate(w.begin(), w.end(), 0);
        while (l < r) {
            int mid = (l + r) / 2, d = 1, cur = 0;
            for (int x : w) {
                if (cur + x > mid) d++, cur = 0;
                cur += x;
            }
            if (d <= days) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};