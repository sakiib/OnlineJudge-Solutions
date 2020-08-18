#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

const ll N=1000100;
const ll INF=1000000000000000LL;

ll D1[N],D2[N];
vector<pll> graph_1[N];
vector<pll> graph_2[N];
bool visited[N];

void dijkstra_1() {
    for(int i=1;i<=N;i++) D1[i]=INF;
    D1[1]=0;
    priority_queue<pll,vector<pll>,greater<pll> > PQ;
    PQ.push({0,1});//val//source
    while(!PQ.empty()) {
        pll T=PQ.top();
        PQ.pop();
        ll tx=T.first;
        ll ty=T.second;
        visited[ty]=true;
        for(int i=0;i<graph_1[ty].size();i++) {
            pll P=graph_1[ty][i];
            ll px=P.first;//source
            ll py=P.second;//cost
            if(visited[px]) continue;
            if(D1[px]>D1[ty]+py) {
                D1[px]=D1[ty]+py;
                PQ.push({D1[px],px});
            }
        }
    }
}
void dijkstra_2() {
    for(int i=1;i<=N;i++) D2[i]=INF;
    D2[1]=0;
    priority_queue<pll,vector<pll>,greater<pll> > PQ;
    PQ.push({0,1});//val//source
    while(!PQ.empty()) {
        pll T=PQ.top();
        PQ.pop();
        ll tx=T.first;
        ll ty=T.second;
        visited[ty]=true;
        for(int i=0;i<graph_2[ty].size();i++) {
            pll P=graph_2[ty][i];
            ll px=P.first;//source
            ll py=P.second;//cost
            if(visited[px]) continue;
            if(D2[px]>D2[ty]+py) {
                D2[px]=D2[ty]+py;
                PQ.push({D2[px],px});
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    ll t;
    scanf("%lld",&t);
    while(t--) {
        memset(visited,false,sizeof(visited));
        for(int i=0;i<=N;i++) graph_1[i].clear(),graph_2[i].clear();
        ll n,e;
        scanf("%lld%lld",&n,&e);
        for(int i=1;i<=e;i++) {
            ll a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            graph_1[a].push_back({b,c});
            graph_2[b].push_back({a,c});
        }
        dijkstra_1();
        memset(visited,false,sizeof(visited));
        dijkstra_2();
        ll ans=0;
        for(int i=1;i<=n;i++) {
            ans+=D1[i]+D2[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
