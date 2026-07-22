class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
                return 0;

            // Check for underflow
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
                return 0;

            ans = ans * 10 + digit;
        }

        return ans;
    }
};