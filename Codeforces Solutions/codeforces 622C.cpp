#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <cmath>

#include <unordered_set>
#include <unordered_map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i < int(n); i++)
#define forft(i, from, to) for (int i = int(from); i < int(to); i++)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define correct(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)

using namespace std;

template<typename T> T sqr(const T &x) {
	return x * x;
}

typedef long long ll;
typedef long long li;
typedef pair<int, int> pt;
typedef long double ld;
typedef pair<ld, ld> pd;

const int INF = int(1e9);
const ll INF_LL = ll(4e18);
const ll INF64 = ll(4e18);
const ll LINF = ll(4e18);
const ld EPS = 1e-8;
const ld PI = 3.14159265358979323846264338;

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

const int N = 2e5 + 10;
const int M = 1e3 + 10;
const li MOD = li(1e9) + 7;

int n, m;
int a[N];
int z[N];

void solve() {
	scanf("%d %d", &n, &m);

	forn(i, n) {
		scanf("%d", &a[i]);
	}

	z[n - 1] = 1;

	forr(i, n - 1) {
		if (a[i] == a[i + 1]) {
			z[i] = z[i + 1] + 1;
		} else {
			z[i] = 1;
		}
	}
	forn(i, m) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		--l, --r;

		if (a[l] != x) {
			printf("%d\n", l + 1);
			continue;
		}

		if (l + z[l] > r) {
			printf("-1\n");
		} else {
			printf("%d\n", l + z[l] + 1);
		}
	}
}

int main() {

	solve();
	return 0;
}
