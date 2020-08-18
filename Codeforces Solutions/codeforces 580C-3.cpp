#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, mx, cat[N];
vector <int> graph[N];
bool visited[N];
int ans;

void solve(int st , int cur , bool prev) {
    if(visited[st]) return;
    visited[st] = true;
    if (cur > mx) return;
    if (graph[st].size() == 1 && st!=1) {
        ans++;
        return;
    }
    for (int i = 0; i < graph[st].size(); i++) {
        int next = graph[st][i];
        if (!visited[next]) {
            solve(next , (prev == true )?cur+cat[next]:cat[next] , (cat[next] == 0)?false:true);
        }
    }
}
int main(int argc, char const *argv[]) {
    scanf("%d%d",&n,&mx);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&cat[i]);
    }
    for (int i = 1; i < n; i++) {
        int u , v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    solve(1 , cat[1] , (cat[1] == 0) ? false : true);
    printf("%d\n",ans);
    return 0;
}
