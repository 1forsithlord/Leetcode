class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // Store the first and last occurrence of each character
        std::vector<int> first(26, -1);
        std::vector<int> last(26, -1);
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }
        
        std::vector<std::pair<int, int>> validIntervals;
        
        // Form valid intervals for each unique character
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            int left = first[i];
            int right = last[i];
            bool isValid = true;
            
            // Expand the interval to cover all occurrences of any included character
            for (int j = left; j <= right; ++j) {
                 int currChar = s[j] - 'a';
                
                // If a character inside has its first occurrence before 'left', 
                // this interval cannot start at 'left' (it would be a duplicate logic check)
                if (first[currChar] < left) {
                    isValid = false;
                    break;
                }
                right = std::max(right, last[currChar]);
            }
            
            if (isValid) {
                validIntervals.push_back({right, left}); // Store right first to sort by end position
            }
        }
        
        // Sort intervals by their end position (greedy criteria)
        std::sort(validIntervals.begin(), validIntervals.end());
        
        std::vector<std::string> result;
        int prevEnd = -1;
        for (const auto& interval : validIntervals) {
            int end = interval.first;
            int start = interval.second;
            
            // If the current interval does not overlap with the previous selected one
            if (start > prevEnd) {
                result.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }
        
        return result;
        
    }
};