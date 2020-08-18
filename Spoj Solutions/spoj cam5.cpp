#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
bool visited[100005];

void dfs(int st) {
    visited[st]=true;
    for(int i=0;i<graph[st].size();i++) {
        if(!visited[graph[st][i]]) {
            dfs(graph[st][i]);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
       memset(visited,false,sizeof(visited));
       for(int i=0;i<100005;i++) graph[i].clear();
       int n;
       scanf("%d",&n);
       int k;
       scanf("%d",&k);
       for(int i=1;i<=k;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
       }
       int ans=0;
       for(int i=0;i<n;i++) {
        if(!visited[i]) {
         ans++;
         dfs(i);
        }
       }
       printf("%d\n",ans);
    }
    return 0;
}
