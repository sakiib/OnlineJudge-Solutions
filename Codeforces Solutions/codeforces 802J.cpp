#include<bits/stdc++.h>
using namespace std;

const int N=105;
vector<pair<int,int> > graph[N];
bool visited[N];
int mx=0;

void dfs(int start,int cur) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        pair<int,int> P=graph[start][i];
        //printf("here : %d %d \n",start,cur);
        int source=P.first;
        int cost=P.second;
        if(graph[source].size()==1) {
            mx=max(mx,cur+cost);
        }
        if(!visited[source]) {
            dfs(source,cur+cost);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    dfs(0,0);
    printf("%d\n",mx);
    return 0;
}
