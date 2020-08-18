#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int inf=100000000;
map<int,bool> has;
vector<int> graph[10010];
int cost[2007];

void dijkstra(int start) {
    for(int i=1;i<=2005;i++) {
        cost[i]=inf;
    }
    if(has.find(start)==has.end()) cost[start]=1;
    else cost[start]=0;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push({start,cost[start]});
    while(!Q.empty()) {
        pii t=Q.top(); Q.pop();
        int s=t.first;
        int c=t.second;
        for(int i=0;i<graph[s].size();i++) {
            int p=graph[s][i];
            int wt;
            if(has.find(p)==has.end()) wt=1;
            else wt=0;
            if(cost[p]==inf||(cost[p]>cost[s]+wt)) {
                cost[p]=cost[s]+wt;
                Q.push({p,cost[p]});
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    bool f=false;
    for(int tc=1;tc<=t;tc++) {
        int n,m,k;
        f=true;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++) {
            int air;
            scanf("%d",&air);
            has[air]=true;
        }
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--) {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u==v) {
              printf("0\n");
              continue;
            }
            dijkstra(u);
            if(cost[v]==inf) printf("-1\n");
            else printf("%d\n",cost[v]);
        }
        printf("\n");
        for(int i=1;i<=10004;i++) graph[i].clear();
        has.clear();
    }
    return 0;
}
