#include <iostream>
#include <vector>
using namespace std;

const int maxn = 3001;

vector<int> g[maxn];
int was[maxn];
int p[maxn];
bool cycle[maxn];
int d[maxn];

void dfs(int v, int par = 0) {
	p[v] = par;
	was[v] = 1;
	for(int x : g[v]) {
		if(was[x] == 0) dfs(x, v);
		else if(x != par and was[x] == 1) { //found cycle
			cycle[x] = true;
			cycle[v] = true;
			p[x] = v;
			int tmp = v;
			while(tmp != x) {
				cycle[tmp] = true;
				tmp = p[tmp];
			}
			return;
		}
	}
}

void dfs2(int v, int par = 0) {
	d[v] = d[par] + 1;
	for(int x : g[v]) {
		if(x != par and !cycle[x]) {
            cerr<<"dfs : "<<x<<" "<<v<<endl;
			dfs2(x, v);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	d[0] = -1;
	for(int i = 1;  i <= n; i++) {
		if(cycle[i]) {
            cerr<<"start : "<<i<<endl;
			dfs2(i, 0);
		}
	}
	for(int i = 1; i <= n; i++) cout << d[i] << ' ';
	cout << endl;
	return 0;
}
