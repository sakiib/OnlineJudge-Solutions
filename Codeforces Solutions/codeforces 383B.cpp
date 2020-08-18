#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<pair<ll,ll>,ll> dist;
map<pair<ll,ll>,bool> visited;

int dx[]={0,+1};
int dy[]={+1,0};
ll n;

bool valid(ll nx,ll ny) {
    return (nx>=1&&ny>=1&&nx<=n&&ny<=n);
}
void bfs() {
    visited[{1,1}]=true;
    dist[{1,1}]=0;
    queue<pair<ll,ll> > Q;
    Q.push({1,1});
    while(!Q.empty()) {
        pair<ll,ll> T=Q.front();
        ll px=T.first; ll py=T.second;
        Q.pop();
        for(int i=0;i<2;i++) {
            ll nx=px+dx[i];
            ll ny=py+dy[i];
            if(!visited[{nx,ny}]&&valid(nx,ny)) {
                Q.push({nx,ny});
                dist[{nx,ny}]=dist[{px,py}]+1;
            }
        }
    }
}
int main(int argc,char const *argv[]) {

    cin>>n;
    ll m;
    cin>>m;
    for(int i=1;i<=m;i++) {
        ll a,b;
        cin>>a>>b;
        visited[{a,b}]=true;
    }
    bfs();
    if(dist[{n,n}]==0) cout<<-1<<endl;
    else cout<<dist[{n,n}]<<endl;
    return 0;
}
