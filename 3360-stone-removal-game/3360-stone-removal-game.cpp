class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        bool isAliceTurn = true;

        while (n >= stonesToRemove && stonesToRemove > 0) {
            n -= stonesToRemove;
            stonesToRemove--;
            isAliceTurn = !isAliceTurn;
        }

        return !isAliceTurn;
    }
};
