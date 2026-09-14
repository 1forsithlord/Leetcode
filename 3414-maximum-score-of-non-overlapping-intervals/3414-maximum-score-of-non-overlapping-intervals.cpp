class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    vector<vector<Node>> dp;
    vector<vector<int>> intervals;
    vector<int> starts;
    int n;

    // Check which vector is lexicographically smaller
    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    Node solve(int i, int cnt) {
       
        if (i >= n || cnt == 4)
            return {0, {}};

        if (dp[i][cnt].score != -1)
            return dp[i][cnt];

        
        Node skip = solve(i + 1, cnt);

        Node take = solve(
            upper_bound(starts.begin(), starts.end(), intervals[i][1])
                - starts.begin(),
            cnt + 1
        );

        take.score += intervals[i][2];
        take.indices.push_back(intervals[i][3]);

        // Keep indices sorted for lexicographical comparison
        sort(take.indices.begin(), take.indices.end());

        if (better(take, skip))
            dp[i][cnt] = take;
        else
            dp[i][cnt] = skip;

        return dp[i][cnt];
    }

    vector<int> maximumWeight(vector<vector<int>>& input) {
        n = input.size();

        // Add original index
        intervals.clear();

        for (int i = 0; i < n; i++) {
            intervals.push_back({
                input[i][0],   // left
                input[i][1],   // right
                input[i][2],   // weight
                i              // original index
            });
        }

        // Sort by starting position
        sort(intervals.begin(), intervals.end());

        starts.resize(n);

        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        dp.assign(n, vector<Node>(5, {-1, {}}));

        return solve(0, 0).indices;
    }
};