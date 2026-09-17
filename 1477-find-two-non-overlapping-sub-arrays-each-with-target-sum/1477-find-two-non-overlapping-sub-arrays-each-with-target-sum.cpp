class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        
        // min_len[i] stores the minimum length of a valid sub-array ending at or before index i
        std::vector<int> min_len(n, INT_MAX);
        
        // Map to store the latest index of each prefix sum
        std::unordered_map<long long, int> prefix_map;
        prefix_map[0] = -1;
        
        long long current_sum = 0;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            current_sum += arr[i];
            
            // Carry forward the minimum length from the previous index
            if (i > 0) {
                min_len[i] = min_len[i - 1];
            }
            
            long long required_sum = current_sum - target;
            if (prefix_map.find(required_sum) != prefix_map.end()) {
                int j = prefix_map[required_sum];
                int curr_len = i - j;
                
                // Update the best sub-array length ending at or before i
                min_len[i] = std::min(min_len[i], curr_len);
                
                // If a valid non-overlapping sub-array exists before index j
                if (j >= 0 && min_len[j] != INT_MAX) {
                    ans = std::min(ans, min_len[j] + curr_len);
                }
            }
            
            // Record the current prefix sum index
            prefix_map[current_sum] = i;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};