class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        string res;
        res.reserve(n);

        int cycle = 2 * numRows - 2;

        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < n; i += cycle) {
                res.push_back(s[i]);

                int diag = i + cycle - 2 * r;
                if (r != 0 && r != numRows - 1 && diag < n)
                    res.push_back(s[diag]);
            }
        }
        return res;
    }
};
