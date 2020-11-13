#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int val[N];

template <typename T> class segment_tree {
public:
    const T def_value = 0;
    vector <T> tree;
    segment_tree(int sz) {
        tree.resize(sz + 5, 0);
    }
    void build(int node, int b, int e) {
        if (b > e) return;
        if (b == e) { tree[node] = val[b]; return; }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        build(l, b, m);
        build(r, m + 1, e);
        tree[node] = (tree[l] + tree[r]);
    }
    void update(int node, int b, int e, int pos, T new_val) {
        if (b > e || pos > e || pos < b) return;
        if (b == e && b == pos) { tree[node] = new_val; return; }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        update(l, b, m, pos, new_val);
        update(r, m + 1, e, pos, new_val);
        tree[node] = (tree[l] + tree[r]);
    }
    T query(int node, int b, int e, int i, int j) {
        if (b > e || i > e || j < b) return def_value;
        if (i <= b && j >= e) return tree[node];
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        return query(l, b, m, i, j) + query(r, m + 1, e, i, j);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    segment_tree <long long> tree (4 * n);
    tree.build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            tree.update(1, 1, n, pos, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << tree.query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
