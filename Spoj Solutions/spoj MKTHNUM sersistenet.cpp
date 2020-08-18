#include <bits/stdc++.h>
using namespace std;

//#define sz(o) ((int)o.size())
//#define all(o) o.begin(), o.end()
//#define rep(i, a, b) for(int i = (a); i <= (b); i++)
//#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void fs(int &nn) {
    bool neg = false;
    register int ch;
    nn = 0;
    ch = getchar();
    if (ch == '-') {
        neg = true;
        ch = getchar();
    }
    for (; (ch > 47 && ch < 58); ch = getchar()) nn = nn * 10 + ch - 48;
    if (neg) nn *= -1;
}

const int maxn = 111111;
int n, m, maxi;
int a[maxn], rm[maxn];
map<int, int> M;

struct node {
    int count;
    node *left, *right;
    node(int count, node *left, node *right) :count(count), left(left), right(right) {}
};

node *root[maxn];
node *null = new node(0, NULL, NULL);

node* build(node *cur, int l, int r, int c) {
    if (l == r) return new node(cur->count + 1, null, null);
    else {
        int mid = (l + r) >> 1;
        node *newNode = new node(0, null, null);
        if (c <= mid) {
            newNode->right = cur->right;
            newNode->left = build(cur->left, l, mid, c);
            newNode->count = newNode->left->count + newNode->right->count;
        }
        else {
            newNode->left = cur->left;
            newNode->right = build(cur->right, mid + 1, r, c);
            newNode->count = newNode->left->count + newNode->right->count;
        }
        return newNode;
    }
}

int query(node *a, node *b, int l, int r, int k) {
    if (l == r) return l;
    else {
        int mid = (l + r) >> 1;
        int count = a->left->count - b->left->count;
        if (count >= k) return query(a->left, b->left, l, mid, k);
        return query(a->right, b->right, mid + 1, r, k - count);
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        M[a[i]];
    }
    maxi = 0;
    for(auto it = M.begin(); it != M.end(); it++){
        M[it->first] = ++maxi;
        rm[maxi] = it->first;
    }

    null->left = null->right = null;
    root[0] = null;
    for(int i = 1; i <= n; i++) root[i] = build(root[i - 1], 1, maxi, M[a[i]]);

    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        printf("%d\n", rm[query(root[r], root[l - 1], 1, maxi, k)]);
    }
}

int main() {

    solve();

    return 0;
}







