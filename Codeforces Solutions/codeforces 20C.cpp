#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>

const ll N=100010;
const ll INF=(ll)(1e15);

vector<pll> graph[N];
bool visited[N];
ll dist[N];
map<ll,ll> path;

void print_path(ll n) {
    if(n==0) return;
    print_path(path[n]);
    cout<<n<< " ";
}
void dijkstra() {
    priority_queue<pll,vector<pll>,greater<pll> > PQ;
    for(int i=1;i<=N;i++) dist[i]=INF;
    dist[1]=0;
    PQ.push({0,1});
    while(!PQ.empty()) {
        pll T=PQ.top();
        PQ.pop();
        ll tx=T.first;
        ll ty=T.second;
        visited[ty]=true;
        for(int i=0;i<graph[ty].size();i++) {
            pll P=graph[ty][i];
            //cerr<<P.first<<" "<<P.second<<endl;
            ll px=P.first;
            ll py=P.second;
            if(visited[px]) continue;
            if(dist[px]>dist[ty]+py) {
                dist[px]=dist[ty]+py;
                path[px]=ty;
                PQ.push({dist[px],px});
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dijkstra();
    if(dist[n]==INF) {
        cout<<-1<<endl; return 0;
    }
    print_path(n);
    //cerr<<dist[n]<<endl;
    //cerr<<path[n]<<endl;
    //cerr<<path[3]<<endl;
    //cerr<<path[4]<<endl;
    return 0;
}
