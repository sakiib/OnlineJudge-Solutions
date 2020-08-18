#include<bits/stdc++.h>
using namespace std;
const int inf=100000000;

vector<pair<int,int> > graph[50005];
int dist[20005];

void dijkstra(int s,int e) {
    for(int i=0;i<=20004;i++) {
        dist[i]=inf;
    }
    dist[s]=0;
    priority_queue<int,vector<int>,greater<int> > Q;
    Q.push(s);
    while(!Q.empty()) {
        int top=Q.top(); Q.pop();
        for(int i=0;i<graph[top].size();i++) {
            pair<int,int> p=graph[top][i];
            int next=p.first;
            int cost=p.second;
            if(dist[next]==inf||(dist[next]>dist[top]+cost)) {
                dist[next]=dist[top]+cost;
                Q.push(next);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,m,s,e;
        scanf("%d%d%d%d",&n,&m,&s,&e);
        for(int i=1;i<=m;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            graph[u].push_back({v,c});
            graph[v].push_back({u,c});
        }
        dijkstra(s,e);
        if(dist[e]==inf) printf("Case #%d: unreachable\n",tc);
        else printf("Case #%d: %d\n",tc,dist[e]);
        for(int i=0;i<=50004;i++) graph[i].clear();
    }
    return 0;
}
