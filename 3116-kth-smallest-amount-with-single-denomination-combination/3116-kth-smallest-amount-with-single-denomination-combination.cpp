class Solution {
public:
    long long findKthSmallest(vector<int>& coins, long long k) {
        int n = coins.size();

        // Function to count how many distinct amounts ≤ x can be formed
        auto count = [&](long long x) {
            long long total = 0;
            int m = coins.size();

            // Inclusion-Exclusion principle
            for (int mask = 1; mask < (1 << m); mask++) {
                long long lcm = 1;
                bool overflow = false;

                for (int j = 0; j < m; j++) {
                    if (mask & (1 << j)) {
                        long long g = gcd(lcm, (long long)coins[j]);
                        if (lcm > x / (coins[j] / g)) {
                            overflow = true;
                            break;
                        }
                        lcm = lcm / g * coins[j];
                    }
                }

                if (!overflow) {
                    long long cnt = x / lcm;
                    if (__builtin_popcount(mask) % 2 == 1) total += cnt;
                    else total -= cnt;
                }
            }
            return total;
        };

        // Binary search for the k-th smallest amount
        long long left = 1, right = 1e18, ans = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (count(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
