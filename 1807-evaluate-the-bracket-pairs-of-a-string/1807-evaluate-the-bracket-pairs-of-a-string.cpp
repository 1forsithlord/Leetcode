

class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {

        std::unordered_map<std::string, std::string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        std::string result = "";
        std::string currentKey = "";
        bool inBracket = false;
        

        for (char c : s) {
            if (c == '(') {
                inBracket = true;
            } else if (c == ')') {
                inBracket = false;

                auto it = dict.find(currentKey);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += "?";
                }
                currentKey = "";
            } else {
                if (inBracket) {
                    currentKey += c;
                } else {
                    result += c;
                }
            }
        }
        
        return result;
    }
};
