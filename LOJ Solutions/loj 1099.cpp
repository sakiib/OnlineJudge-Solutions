#include<bits/stdc++.h>
using namespace std;

const int INF=100000000;

#define pii pair<int,int>
int dist1[100010];
int dist2[100010];
vector<pii> graph[100010];

void dijkstra() {
    for(int i=1;i<=5005;i++) dist1[i]=INF;
    dist1[1]=0; dist2[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(0,1));
    while(!Q.empty()) {
        pii T=Q.top();
        int s=T.second;
        int d=T.first;
        Q.pop();
        for(int i=0;i<graph[s].size();i++) {
            pii P=graph[s][i];
            int ns=P.first;
            int nd=P.second;
            if(dist1[ns]==INF||(dist1[ns]>dist1[s]+nd)) {
                //cerr<<"dist : "<<dist1[ns]<<endl;
                dist1[ns]=dist1[s]+nd;
                Q.push(pii(dist1[ns],ns));
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
        printf("Case %d: %d\n",tc,dist1[n]);
        cerr<<"dist[1] dist[2]: "<<dist1[1]<<" "<<dist1[2]<<endl;
        for(int i=1;i<=5005;i++) graph[i].clear();
    }
    return 0;
}
