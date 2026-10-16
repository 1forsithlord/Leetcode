class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<long long> tree_sum;  // Stores sum of x
    vector<long long> tree_sq;   // Stores sum of x^2
    vector<long long> lazy;      // Lazy propagation array

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        int mid = start + (end - start) / 2;
        int left = 2 * node;
        int right = 2 * node + 1;
        long long val = lazy[node];
        tree_sq[left] = (tree_sq[left] + 2 * val * tree_sum[left] + (mid - start + 1) * val % MOD * val) % MOD;
        tree_sum[left] = (tree_sum[left] + (mid - start + 1) * val) % MOD;
        lazy[left] = (lazy[left] + val) % MOD;

        tree_sq[right] = (tree_sq[right] + 2 * val * tree_sum[right] + (end - mid) * val % MOD * val) % MOD;
        tree_sum[right] = (tree_sum[right] + (end - mid) * val) % MOD;
        lazy[right] = (lazy[right] + val) % MOD;

        lazy[node] = 0;
    }
    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        
        if (l <= start && end <= r) {
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] + (end - start + 1) * val % MOD * val) % MOD;
            tree_sum[node] = (tree_sum[node] + (end - start + 1) * val) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long total_sum = 0;

        for (int i = 0; i < n; ++i) {
            int prev_idx = last_pos.count(nums[i]) ? last_pos[nums[i]] : -1;
            update(1, 0, n - 1, prev_idx + 1, i, 1);
            

            total_sum = (total_sum + tree_sq[1]) % MOD;
            

            last_pos[nums[i]] = i;
        }

        return total_sum;
    }
};
