#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int N=17000;
const int INF=100000000;

vector<pii> graph[N];
int dist[N];
bool visited[N];

void dijkstra(int start) {
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    for(int i=0;i<=550;i++) dist[i]=INF;
    dist[start]=0;
    Q.push({0,start});
    while(!Q.empty()) {
        pii T=Q.top();
        int d=T.first;//distance
        int s=T.second;//source
        Q.pop();
        for(int i=0;i<graph[s].size();i++) {
            pii P=graph[s][i];
            int nd=P.second;//distance
            int ns=P.first;//source
            int cost=max(nd,d);
            if(dist[ns]==INF||(dist[ns]>cost)) {
                dist[ns]=cost;
                Q.push({dist[ns],ns});
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
            scanf("%d%d%d",&a,&b,&c);
            graph[a].push_back(pii(b,c));
            graph[b].push_back(pii(a,c));
        }
        int k;
        scanf("%d",&k);
        dijkstra(k);
        printf("Case %d:\n",tc);
        for(int i=0;i<n;i++) {
            if(dist[i]==INF) cout<<"Impossible"<<endl;
            else cout<<dist[i]<<endl;
        }
        for(int i=0;i<=n;i++) graph[i].clear();
    }
    return 0;
}
