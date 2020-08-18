#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=100005;
const ll INF=(ll)(5e18);

ll n;
ll val[3];
ll ara[N];
ll dp[N][3];
bool visited[N][3];

ll solve(int pos,int taken) {
    if(taken==3) return 0;
    if(pos==n) return -INF;
    if(visited[pos][taken]) return dp[pos][taken];
    visited[pos][taken]=true;
    ll ret1=solve(pos+1,taken);
    ll ret2=val[taken]*ara[pos]+solve(pos,taken+1);
    dp[pos][taken]=max(ret1,ret2);
    return dp[pos][taken];
}
int main(int argc,char const *argv[]) {
    cin>>n;
    cin>>val[0]>>val[1]>>val[2];
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    memset(visited,false,sizeof(visited));
    ll ans=solve(0,0);
    cout<<ans<<endl;
    return 0;
}
