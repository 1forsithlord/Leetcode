class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        struct Element {
            int val;
            int digitSum;
            int originalIdx;
        };
        
        std::vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], getDigitSum(nums[i]), i};
        }
        
        std::sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });
        
        std::vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].originalIdx == i) {
                continue;
            }
            
            int cycleSize = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].originalIdx;
                cycleSize++;
            }
            
            if (cycleSize > 0) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
