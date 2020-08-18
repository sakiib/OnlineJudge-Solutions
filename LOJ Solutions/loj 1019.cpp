#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int INF=100000000;

int dist[100010];
vector<pii> graph[1005];

void dijkstra() {
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    for(int i=0;i<=1005;i++) dist[i]=INF;
    dist[1]=0;
    Q.push(pii(dist[1],1));
    while(!Q.empty()) {
        pii T=Q.top();
        int d=T.first;
        int s=T.second;
        Q.pop();
        for(int i=0;i<graph[s].size();i++) {
            pii P=graph[s][i];
            int nd=P.second;
            int ns=P.first;
            if(dist[ns]==INF||(dist[ns]>dist[s]+nd)) {
                dist[ns]=dist[s]+nd;
                Q.push(pii(dist[ns],ns));
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,e;
        scanf("%d%d",&n,&e);
        for(int i=1;i<=e;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            graph[a].push_back(pii(b,c));
            graph[b].push_back(pii(a,c));
        }
        dijkstra();
        if(dist[n]==INF) printf("Case %d: Impossible\n",tc);
        else printf("Case %d: %d\n",tc,dist[n]);
        for(int i=0;i<=n;i++) graph[i].clear();
    }
    return 0;
}
