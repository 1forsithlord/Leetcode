class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::vector<char> stack;

        for (char c : s) {
            if (c == ')') {
                // Collect characters until the matching '(' is found
                std::string temp = "";
                while (!stack.empty() && stack.back() != '(') {
                    temp += stack.back();
                    stack.pop_back();
                }
                
                // Pop the opening parenthesis '('
                if (!stack.empty()) {
                    stack.pop_back();
                }
                
                // Push the reversed characters back onto the stack
                for (char tc : temp) {
                    stack.push_back(tc);
                }
            } else {
                // Push regular characters and '(' onto the stack
                stack.push_back(c);
            }
        }

        // Construct the final string from the remaining characters in the stack
        return std::string(stack.begin(), stack.end());
    }
};
