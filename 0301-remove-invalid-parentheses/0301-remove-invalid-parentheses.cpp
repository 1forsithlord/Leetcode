class Solution {
private:

    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);

        bool foundLevel = false;

        while (!q.empty()) {
            int levelSize = q.size();
            

            for (int i = 0; i < levelSize; ++i) {
                std::string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    foundLevel = true;
                }

                if (foundLevel) continue;
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;
                    std::string nextState = curr.substr(0, j) + curr.substr(j + 1);

                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            if (foundLevel) break;
        }

        return result;
    }
};
