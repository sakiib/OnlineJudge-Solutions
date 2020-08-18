#include<bits/stdc++.h>
using namespace std;

vector<int> graph[50005];
bool visited[50005];
int dist[50005];
int cnt;

void dfs(int start) {
    visited[start]=true;
    cnt++;
    for(int i=0;i<graph[start].size();i++) {
        if(!visited[graph[start][i]]) {
            dfs(graph[start][i]);
        }
    }
    visited[start]=false;
    cnt++;
    dist[start]=cnt;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        int mx=0,idx=0;
        for(int i=1;i<=n;i++) {
            cnt=0;
            if(!dist[i]) {
                dfs(i);
            }
            if(dist[i]>mx) {
                mx=dist[i];
                idx=i;
            }
        }
        printf("Case %d: %d\n",tc,idx);
        for(int i=1;i<=50005;i++) {
            graph[i].clear();
            visited[i]=false;
            dist[i]=0;
        }
    }
    return 0;
}
