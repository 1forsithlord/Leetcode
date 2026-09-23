#include <string>

using namespace std;

class Solution {
public:
    long long reverseDegree(string s) {
        long long total_sum = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            int rev_alpha_pos = 26 - (s[i] - 'a'); 
            int str_pos = i + 1; // 1-indexed position
            
            total_sum += (long long)rev_alpha_pos * str_pos;
        }
        
        return total_sum;
    }
};
