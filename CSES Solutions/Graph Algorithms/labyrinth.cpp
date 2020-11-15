#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int r, c;
string s[N];
int dist[N][N];
char par[N][N];
pair <int,int> path[N][N];
char dir[] = {'D', 'U', 'R', 'L'};

bool inside(int nx, int ny) {
    return (nx >= 0 && ny >= 0 && nx < r && ny < c);
}
bool valid(int nx, int ny) {
    return (s[nx][ny] != '#');
}
void bfs(int sx, int sy, int ex, int ey) {
    queue <pair <int,int> > q;
    q.push(make_pair(sx, sy));
    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 0;
    while (!q.empty()) {
        pair <int,int> f = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = f.first + dx[i], ny = f.second + dy[i];
            if (!inside(nx, ny) || !valid(nx, ny)) continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[f.first][f.second] + 1;
                path[nx][ny] = make_pair(f.first, f.second);
                par[nx][ny] = dir[i];
                q.push(make_pair(nx, ny));
            }
        }
    }
    if (dist[ex][ey] == -1) {
        cout << "NO" << "\n";
        exit(0);
    }
    cout << "YES" << "\n";
    cout << dist[ex][ey] << "\n";
    string ans = "";
    while (!(ex == sx && ey == sy)) {
        ans += par[ex][ey];
        pair <int,int> temp = path[ex][ey];
        ex = temp.first, ey = temp.second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];

    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'A') sx = i, sy = j;
            if (s[i][j] == 'B') ex = i, ey = j;
        }
    }
    assert(sx != -1 && sy != -1 && ex != -1 && ey != -1);
    bfs(sx, sy, ex, ey);
    return 0;
}
