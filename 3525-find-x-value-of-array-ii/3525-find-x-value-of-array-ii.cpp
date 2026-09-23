#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int K;
    int n;

    struct Node {
        int prod;
        int remain[5];
        
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) remain[i] = 0;
        }
    };

    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;
        
        for (int i = 0; i < K; ++i) {
            res.remain[i] += left.remain[i];
        }
        
        for (int i = 0; i < K; ++i) {
            int new_rem = (i * left.prod) % K;
            res.remain[new_rem] += right.remain[i];
        }
        
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % K;
            tree[node].prod = val;
            tree[node].remain[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % K;
            for (int i = 0; i < 5; ++i) tree[node].remain[i] = 0;
            tree[node].prod = rem;
            tree[node].remain[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }
        return merge(query(2 * node, start, mid, l, r),
                     query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->K = k;
        this->n = nums.size();
        tree.assign(4 * n, Node());
        
        build(1, 0, n - 1, nums);
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            
            update(1, 0, n - 1, index, value);
            
            Node res = query(1, 0, n - 1, start, n - 1);
            
            ans.push_back(res.remain[x]);
        }
        
        return ans;
    }
};

