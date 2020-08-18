#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 1e5 + 10;
int n, m, k;
int tree[6][maxn << 2], a[maxn][6];

void build(int idx, int node, int l, int r) {
	if(l == r) {
		tree[idx][node] = a[l][idx];
		return;
	} int mid = l + r >> 1;
	build(idx, node << 1, l, mid);
	build(idx, node << 1|1, mid+1, r);
	tree[idx][node] = max(tree[idx][node << 1], tree[idx][node << 1|1]);
}
ll query(int idx, int node, int l, int r, int i, int j) {
	if(r < i || l > j) return 0;
	if(i <= l && r <= j) return tree[idx][node];
	int mid = l + r >> 1;
	return max(query(idx, node<<1, l, mid, i, j),
		 	   query(idx, node <<1|1, mid+1, r, i, j));
}
ll sum(int l, int r) {
	ll ret = 0;
	for(int i = 1; i <= m; i++)
		ret += query(i, 1, 1, n, l, r);
	return ret;
}
bool check(int len) {
	for(int i = 1; i + len - 1 <= n; i++)
		if(sum(i, i + len - 1) <= k) return 1;
	return 0;
}
int main(int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	for(int i = 1; i <= m; i++)
		build(i, 1, 1, n);

	int lo = 0, hi = n, ans = 0;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(check(mid)) ans = mid, lo = mid + 1;
		else hi = mid-1;
	}
	cout <<"Ans: "<< tree[2][1]<< endl;
	if(!ans) {
		for(int i = 1; i <= m; i++) printf("0 "); return 0;
	}
	for(int i = 1; i + ans - 1 <= n; i++) {
		if(sum(i, i + ans - 1) <= k) {
			for(int j = 1; j <= m; j++) {
				printf("%lld ", query(j, 1, 1, n, i, i + ans - 1));
			} return 0;
		}
	}
}
