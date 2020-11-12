#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int sub[N];
vector <int> graph[N];

void dfs(int s, int p) {
    sub[s] = 1;
    for (auto x: graph[s]) {
        if (x != p) {
            dfs(x, s);
            sub[s] += sub[x];
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << sub[i] - 1;
        else cout << " " << sub[i] - 1;
    }
    cout << endl;
    return 0;
}
