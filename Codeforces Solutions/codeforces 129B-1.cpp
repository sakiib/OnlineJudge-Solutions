#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
bool found;
int ans , degree[N]={0};
vector <int> graph[N];

void solve(int n , int e) {
    queue <int> Q;

    for (int i = 1; i <= n; i++) {
         if (degree[i] == 1) {
            Q.push(i);
            degree[i]--;
         }
    }
    while(!Q.empty()) {

    }
}
int main(int argc,char const *argv[]) {
    int n , e;
    scanf("%d%d",&n,&e);
    for (int i = 1; i <= e; i++) {
        int u , v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++ , degree[v]++;
    }
    solve(n,e);
    return 0;
}
