#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector <int> graph[N];
int nodes, dist[N];

pair <int,int> bfs(int s) {
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (auto x: graph[f]) {
            if (dist[x] == -1) {
                dist[x] = dist[f] + 1;
                q.push(x);
            }
        }
    }
    int node = -1, d = -1;
    for (int i = 1; i <= nodes; i++) {
        if (dist[i] > d) {
            d = dist[i], node = i;
        }
    }
    return make_pair(d, node);
}
int main() {
    cin >> nodes;
    for (int i = 1; i <= nodes - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    pair <int,int> x = bfs(1);
    pair <int,int> y = bfs(x.second);
    cout << y.first << "\n";
    return 0;
}
