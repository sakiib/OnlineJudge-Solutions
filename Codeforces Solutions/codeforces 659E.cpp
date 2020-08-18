#include<bits/stdc++.h>
using namespace std;
const int N=100005;

bool visited[N];
vector<int> graph[N];
bool cycle=false;

void dfs(int start,int par) {
    visited[start]=true;
    for(auto x: graph[start]) {
        if(!visited[x]) {
            dfs(x,start);
        }
        else if(visited[x]&&x!=par) {
            cycle=true;
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=1;i<=e;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            cycle=false;
            dfs(i,-1);
            if(!cycle) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
