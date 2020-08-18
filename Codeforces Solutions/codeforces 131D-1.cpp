#include<bits/stdc++.h>
using namespace std;

vector<int> graph[3005];
bool visited[3005];
int parent[3005];
bool cycle[3005];
int dist[3005];

void cycle_find(int start,int par) {
    visited[start]=true;
    parent[start]=par;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            cycle_find(next,start);
        }
        else if(visited[next]&&next!=par) {
            cycle[next]=true;
            cycle[start]=true;
            parent[next]=start;
            int temp=start;
            while(temp!=next) {
                cycle[temp]=true;
                temp=parent[temp];
            }
            return;
        }
    }
}
void dfs(int start) {
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!cycle[next]&&(dist[next]>dist[start]+1)) {
            dist[next]=dist[start]+1;
            dfs(next);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited,false,sizeof(visited));
    cycle_find(1,0);
    for(int i=1;i<=3005;i++) {
        dist[i]=1000000;
    }
    for(int i=1;i<=n;i++) {
        if(cycle[i]) {
            dist[i]=0;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++) {
        printf("%d ",dist[i]);
    }
    return 0;
}
