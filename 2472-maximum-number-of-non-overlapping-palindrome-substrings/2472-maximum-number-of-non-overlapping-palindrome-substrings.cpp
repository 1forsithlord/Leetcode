class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // palindrome[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // dp[i] = max number of palindromes in s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Don't use s[i-1]
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int start = 0; start <= i - k; start++) {
                if (palindrome[start][i - 1]) {
                    dp[i] = max(dp[i],
                                dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};