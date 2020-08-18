#include<bits/stdc++.h>
using namespace std;

const int N=100;

#define ll long long
vector<ll> graph[N];
bool visited[N];
ll ans=1;

void bfs(ll start) {
    queue<ll> Q;
    visited[start]=true;
    Q.push(start);
    while(!Q.empty()) {
        ll F=Q.front();
        Q.pop();
        for(int i=0;i<graph[F].size();i++) {
            if(!visited[graph[F][i]]) {
                ans*=2;
                visited[graph[F][i]]=true;
                Q.push(graph[F][i]);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++) {
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(ll i=1;i<=n;i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
