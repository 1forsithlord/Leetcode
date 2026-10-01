class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> bracket_map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        std::stack<char> st;
        
        for (char c : s) {
            if (bracket_map.count(c)) {
                if (st.empty() || st.top() != bracket_map[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }
        
        return st.empty();
    }
};
