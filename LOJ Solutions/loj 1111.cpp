#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10005];
int dist[10005];
bool visited[1005];

void dfs(int start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        if(!visited[graph[start][i]]) {
            dist[graph[start][i]]++;
            dfs(graph[start][i]);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,k,m;
        scanf("%d%d%d",&k,&n,&m);
        int start[1000];
        for(int i=1;i<=k;i++) {
            scanf("%d",&start[i]);
        }
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        memset(dist,0,sizeof(dist));
        for(int i=1;i<=k;i++) {
            memset(visited,false,sizeof(visited));
            dist[start[i]]++;
            dfs(start[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(dist[i]==k) ans++;
        }
        printf("Case %d: %d\n",tc,ans);
        for(int i=1;i<=1005;i++) {
            graph[i].clear();
        }
    }
    return 0;
}
