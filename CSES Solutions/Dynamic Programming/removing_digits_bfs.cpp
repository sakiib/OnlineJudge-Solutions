#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int inf = 1e9;

vector <int> v[N];
int cost[N];

int bfs(int cur) {
    memset(cost, -1, sizeof(cost));
    queue <int> q;
    cost[cur] = 0;
    q.push(cur);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (auto x: v[f]) {
            if (cost[f - x] == -1) {
                cost[f - x] = cost[f] + 1;
                q.push(f - x);
            }
        }
    }
    return cost[0];
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur) {
            int x = cur%10;
            if (x != 0) v[i].push_back(x);
            cur /= 10;
        }
    }
    cout << bfs(n) << "\n";
    return 0;
}
