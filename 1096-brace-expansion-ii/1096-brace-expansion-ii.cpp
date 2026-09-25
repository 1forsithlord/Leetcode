class Solution {
private:

    pair<set<string>, int> parse(const string& s, int i) {

        set<string> res = {""};
        
        while (i < s.length() && s[i] != '}' && s[i] != ',') {
            if (s[i] == '{') {
                i++; 
                set<string> combined_inner;
                

                while (true) {
                    auto [next_set, next_idx] = parse(s, i);
                    i = next_idx;
                    

                    combined_inner.insert(next_set.begin(), next_set.end());
                    
                    if (i < s.length() && s[i] == ',') {
                        i++; 
                    } else if (i < s.length() && s[i] == '}') {
                        i++; 
                        break;
                    }
                }
                

                set<string> temp;
                for (const auto& prefix : res) {
                    for (const auto& suffix : combined_inner) {
                        temp.insert(prefix + suffix);
                    }
                }
                res = move(temp);
            } else {

                char ch = s[i];
                i++;
                set<string> temp;
                for (const auto& prefix : res) {
                    temp.insert(prefix + ch);
                }
                res = move(temp);
            }
        }
        return {res, i};
    }

public:
    vector<string> braceExpansionII(string expression) {
        auto [unique_words, _] = parse(expression, 0);
        

        return vector<string>(unique_words.begin(), unique_words.end());
    }
};
