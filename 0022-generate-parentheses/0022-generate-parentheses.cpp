class Solution {
public:
    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int max_pairs) {
        if (current.length() == max_pairs * 2) {
            result.push_back(current);
            return;
        }

        if (open < max_pairs) {
            backtrack(result, current + "(", open + 1, close, max_pairs);
        }

        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max_pairs);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

