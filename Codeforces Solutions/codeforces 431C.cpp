#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=(ll)(1e9+7);
const int N=105;

ll n,k,d;
ll dp[N][N];

ll solve(ll tot,ll mx) {
    if(tot<0) return 0;
    if(tot==0) {
        if(mx>=d) return 1;
        return 0;
    }
    if(dp[tot][mx]!=-1) return dp[tot][mx];
    ll ans=0;
    for(ll i=1;i<=k;i++) {
        //cout<<"tot-i : max(mx,i) : ans "<<tot-i<<" "<<max(mx,i)<<" "<<ans<<endl;
        ans+=solve(tot-i,max(mx,i));
    }
    ans%=mod;
    dp[tot][mx]=ans;
    return dp[tot][mx];
}
int main(int argc,char const *argv[]) {
    cin>>n>>k>>d;
    memset(dp,-1,sizeof(dp));
    ll ans=solve(n,0);
    cout<<(ans%mod)<<endl;
    return 0;
}
