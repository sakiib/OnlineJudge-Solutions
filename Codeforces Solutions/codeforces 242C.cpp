#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<pair<ll,ll>,ll> M;
map<pair<ll,ll>,ll> visited;
map<pair<ll,ll>,ll> val;
ll sx,sy,ex,ey;
ll r,c;
ll mx=(ll)(1e9);

ll dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
ll dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool possible(ll nx,ll ny) {
    return (nx>=1&&nx<=mx&&ny>=1&&ny<=mx&&(M[{nx,ny}]==-1)&&(visited[{nx,ny}]==0));
}
void bfs(ll sx,ll sy) {
    queue<pair<ll,ll> > Q;
    Q.push({sx,sy});
    visited[{sx,sy}]=0;
    val[{sx,sy}]=0;
    val[{ex,ey}]=-1;
    while(!Q.empty()) {
        pair<ll,ll> p=Q.front();
        if(p.first==ex&&p.second==ey) {return; }
        Q.pop();
        for(ll i=0;i<8;i++) {
            ll nx=p.first+dx[i];
            ll ny=p.second+dy[i];
            if(possible(nx,ny)) {
                val[{nx,ny}]=val[{p.first,p.second}]+1;
                Q.push({nx,ny});
                //cerr<<"here"<<endl;
                visited[{nx,ny}]=1;
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>sx>>sy>>ex>>ey;
    //cerr<<M[{sx,sy}]<< " " <<M[{ex,ey}]<<endl;
    ll n;
    cin>>n;
    while(n--) {
        ll a,b;
        cin>>r>>a>>b;
        for(ll i=a;i<=b;i++) {
            M[{r,i}]=-1;
        }
    }
    //cerr<<M[{5,3}]<< " " <<M[{5,8}]<<endl;
    bfs(sx,sy);
    cout<<val[{ex,ey}]<<endl;
    return 0;
}

