class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int a = 0, b = 1;
        while(n--) {
            b = a + b;
            a = b - a;
        }
        return a;
    }
};