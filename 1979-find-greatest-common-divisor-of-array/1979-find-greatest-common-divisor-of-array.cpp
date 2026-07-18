class Solution {
public:
    int findGCD(vector<int>& nums) {
       // Find the smallest and largest numbers in the array
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Return their greatest common divisor
        return std::gcd(min_val, max_val);
    }
};        
   