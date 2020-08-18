#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>

const ll N=100100;
const ll INF=(ll)(1e15);

ll from,to;
vector<pii> graph[N];
bool visited[N];
ll dist[N];

void dijkstra(ll start) {
    priority_queue<pii> Q;
    for(int i=0;i<=N;i++) dist[i]=INF;
    dist[start]=0;
    Q.push({0,start});
    while(!Q.empty()) {
        pii T=Q.top();
        ll c=T.first;
        ll s=T.second;
        Q.pop();
        for(int i=0;i<graph[s].size();i++) {
            pii P=graph[s][i];
            ll x=P.first;
            ll y=P.second;
            if(!visited[x]||dist[x]>=dist[s]+y) {
                if(dist[x]>dist[s]+y) {
                    dist[x]=dist[s]+y;
                    visited[x]=true;
                    Q.push({dist[x],x});
                }
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        memset(visited,false,sizeof(visited));
        ll n,e;
        cin>>n>>e;
        for(ll i=1;i<=e;i++) {
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a].push_back({b,c});
            //graph[b].push_back({a,c});
        }
        cin>>from>>to;
        dijkstra(from);
        if(dist[to]==INF) cout<<"NO"<<endl;
        else cout<<dist[to]<<endl;
        for(int i=0;i<=N;i++) graph[i].clear();
    }
    return 0;
}
