class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        
        vector<long long> last(26, 0);
        long long dp = 1;  // empty subsequence

        for (char c : s) {
            int x = c - 'a';

            long long newDp = (2 * dp - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = newDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};