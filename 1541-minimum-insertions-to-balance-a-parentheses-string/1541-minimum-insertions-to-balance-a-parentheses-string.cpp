class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int right_needed = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                right_needed += 2;
                if (right_needed % 2 != 0) {
                    insertions++;
                    right_needed--; 
                }
            } else { 
                right_needed--;
                
                if (right_needed < 0) {
                    insertions++;
                    right_needed += 2; 
                }
            }
        }
        
        return insertions + right_needed;
    }
};
