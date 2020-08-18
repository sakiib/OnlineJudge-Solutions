#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000003;
ll dp[100010];
ll calc(ll from,ll to) {
    if()
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,tc;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    for(tc=1;tc<=t;tc++) {
        ll n,r;
        cin>>n>>r;
        if(r==0||n==r) {
            printf("Case %lld: 1\n",tc);
            continue;
        }
        ll a,b;
        if(r>n-r) {
            a=r,b=n-r;
        }
        else {
            a=n-r,b=r;
        }
        //cout<<n-r+1<<endl;
        ll up=calc(n,n-r+1);
        ll down=calc(b,1);
        //cout<<up<<" "<<down<<endl;

        printf("Case %lld: %lld\n",tc,);
    }
    return 0;
}
