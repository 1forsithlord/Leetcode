class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> squares(n);
        

        for (int i = 0; i < n; ++i) {
            squares[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        

        std::sort(squares.begin(), squares.end());
        
        long long total_score = 0;
        int negative_count = n / 2; // Number of elements that will be subtracted
        

        for (int i = 0; i < n; ++i) {
            if (i < negative_count) {
                total_score -= squares[i];
            } else {
                total_score += squares[i];
            }
        }
        
        return total_score;
    }
};


