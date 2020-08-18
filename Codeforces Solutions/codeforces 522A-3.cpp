#include<bits/stdc++.h>
using namespace std;

const int N=100;

#define ll long long
vector<ll> graph[N];
bool visited[N];
ll ans=1;

void dfs(ll start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        if(!visited[graph[start][i]]) {
            ans*=2;
            dfs(graph[start][i]);
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
            dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
