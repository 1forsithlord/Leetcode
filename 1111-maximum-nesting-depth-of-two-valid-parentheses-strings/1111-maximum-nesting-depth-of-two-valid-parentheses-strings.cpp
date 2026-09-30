

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> answer;
        answer.reserve(seq.length()); // Optimise memory allocation
        int depth = 0;
        
        for (char c : seq) {
            if (c == '(') {
                // Assign using current depth parity, then increment depth
                answer.push_back(depth % 2);
                depth++;
            } else {
                // Decrement depth first, then assign using new parity
                depth--;
                answer.push_back(depth % 2);
            }
        }
        
        return answer;
    }
};
