class Solution {
    vector<long long> tree_sum;
    vector<long long> tree_sq_sum;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        int mid = start + (end - start) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;
        long long val = lazy[node];
        tree_sq_sum[left_child] += 2 * val * tree_sum[left_child] + val * val * (mid - start + 1);
        tree_sum[left_child] += val * (mid - start + 1);
        lazy[left_child] += val;
        tree_sq_sum[right_child] += 2 * val * tree_sum[right_child] + val * val * (end - mid);
        tree_sum[right_child] += val * (end - mid);
        lazy[right_child] += val;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        
        if (l <= start && end <= r) {
            tree_sq_sum[node] += 2 * val * tree_sum[node] + (long long)val * val * (end - start + 1);
            tree_sum[node] += (long long)val * (end - start + 1);
            lazy[node] += val;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
        tree_sq_sum[node] = tree_sq_sum[2 * node] + tree_sq_sum[2 * node + 1];
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        tree_sum.assign(4 * n, 0);
        tree_sq_sum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int i = last_pos.count(nums[j]) ? last_pos[nums[j]] + 1 : 0;
            update(1, 0, n - 1, i, j, 1);
            total_sum = (total_sum + tree_sq_sum[1]) % MOD;
            
            last_pos[nums[j]] = j;
        }

        return total_sum;
    }
};
