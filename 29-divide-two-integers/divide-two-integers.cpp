class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long ans = 0;
        long long num = abs((long long)dividend);
        long long d = abs((long long)divisor);
        while (num >= d) {
            int count = 0;
            while (num >= d << (count + 1)) {
                count++;
            }
            ans += (1 << count);
            num = num - (d << count);
        }
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;
        return ans;
    }
};