#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;

struct data {
    int v,w,idx;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> graph[100005];
int dist[100005];
int n,m,k,d;

void dijkstra () {
    for(int i=0;i<=10005;i++) {
        dist[i]=inf;
        Index[i]=inf;
    }
    queue<data> Q;

    dist[0]=0;
    Q.push({dist[0],0,0});

    while(!Q.empty()) {

    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back({v,w,0});
        }
        for(int i=1;i<=k;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back({v,w,1});
        }
        dijkstra();
        printf("%d\n",dist[n-1]);
    }
    return 0;
}
