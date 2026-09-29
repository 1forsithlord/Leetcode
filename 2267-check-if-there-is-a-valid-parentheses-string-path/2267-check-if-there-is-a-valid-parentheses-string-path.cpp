
class Solution {
public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        

        int max_bal = (m + n - 1) / 2;
        

        std::vector<std::vector<std::vector<bool>>> dp(
            m, std::vector<std::vector<bool>>(n, std::vector<bool>(max_bal + 1, false))
        );
        

        dp[0][0][1] = true; 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= max_bal; ++k) {
                    if (!dp[i][j][k]) continue;
                    
                    // Move Down
                    if (i + 1 < m) {
                        int next_k = k + (grid[i + 1][j] == '(' ? 1 : -1);
                        if (next_k >= 0 && next_k <= max_bal) {
                            dp[i + 1][j][next_k] = true;
                        }
                    }
                    

                    if (j + 1 < n) {
                        int next_k = k + (grid[i][j + 1] == '(' ? 1 : -1);
                        if (next_k >= 0 && next_k <= max_bal) {
                            dp[i][j + 1][next_k] = true;
                        }
                    }
                }
            }
        }
        

        return dp[m - 1][n - 1][0];
    }
};
