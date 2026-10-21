#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        if (n == 2) {
            return -1;
        }
        char mn = s[0];
        char mx = s[0];
        for (char c : s) {
            mn = min(mn, c);
            mx = max(mx, c);
        }
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        return 3;
    }
};
