class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;


        auto isSortable = [&](int k) -> bool {
            int last_max = 0; // Tracks the maximum element of the previous block

            for (int i = 0; i < n; i += k) {
                int drop_count = 0;
                int drop_idx = -1;
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k];
                    if (curr > next) {
                        drop_count++;
                        drop_idx = j;
                    }
                }
                if (drop_count > 1) return false;

                int block_min, block_max;
                if (drop_count == 0) {
                    block_min = nums[i];
                    block_max = nums[i + k - 1];
                } else {
                    block_min = nums[i + (drop_idx + 1) % k];
                    block_max = nums[i + drop_idx];
                }
                if (block_min < last_max) return false;
                
                last_max = block_max;
            }
            return true;
        };

        // Find all divisors of n and test each
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(k)) {
                    ans += k;
                }
            }
        }

        return ans;
    }
};
