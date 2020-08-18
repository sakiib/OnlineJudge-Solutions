#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int ans=0;
bool visited[100005];

void dfs(int start) {
    visited[start]=true;
    ans++;
    for(int i=0;i<graph[start].size();i++) {
        if(!visited[graph[start][i]]) {
            dfs(graph[start][i]);
        }
    }
}
int main(int argc,char const *argv[]){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        memset(visited,false,sizeof(visited));
        ans=0;
        for(int i=1;i<=l;i++) {
            int pos;
            scanf("%d",&pos);
            if(!visited[pos]) {
                dfs(pos);
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=100005;i++) graph[i].clear();
    }
    return 0;
}
