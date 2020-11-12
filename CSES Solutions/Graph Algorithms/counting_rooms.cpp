#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int r, c;
string s[N];
bool vis[N][N];

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return;
    if (s[x][y] == '#') return;
    if (vis[x][y]) return;
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j] && s[i][j] == '.') ans++, dfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
