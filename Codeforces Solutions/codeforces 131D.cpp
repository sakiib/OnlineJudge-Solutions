#include<bits/stdc++.h>
using namespace std;

vector<int> graph[3005];
bool visited[3005];
int par[3005];
int dist[3005];
bool cycle[3005];

void find_cycle(int child,int parent) {
    par[child]=parent;
    visited[child]=true;

    for(int i=0;i<graph[child].size();i++) {
        if(!visited[graph[child][i]]) {
            find_cycle(graph[child][i],child);
        }
        else if(graph[child][i]!=parent&&visited[graph[child][i]]) {
            cycle[graph[child][i]]=true;
            cycle[child]=true;
            par[graph[child][i]]=child;
            int temp=child;
            while(temp!=graph[child][i]) {
                cycle[temp]=true;
                temp=par[temp];
            }
            return;
        }
    }
}
void dfs(int start,int parent) {
    dist[start]=dist[parent]+1;
    for(int i=0;i<graph[start].size();i++) {
        if(!cycle[graph[start][i]]&&graph[start][i]!=parent) {
            dfs(graph[start][i],start);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    find_cycle(1,0);
    memset(dist,-1,sizeof(dist));
    for(int i=1;i<=n;i++) {
        if(cycle[i]) {
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
    return 0;
}
