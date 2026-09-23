#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int i = 0; i < n; ++i) {
            int current_val = nums[i] % k;
            vector<long long> next_dp(k, 0);
            
            next_dp[current_val]++;
            
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_rem = (r * current_val) % k;
                    next_dp[next_rem] += dp[r];
                }
            }
            
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }
            
            dp = next_dp;
        }
        
        return result;
    }
};
