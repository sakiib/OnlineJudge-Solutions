#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll ans=0;

ll lcm(ll a,ll b,ll c) {
    ll x=(a*b/__gcd(a,b));
    ll y=(x*c/__gcd(x,c));
    return y;
}
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    for(ll i=max(1LL,n-50);i<=n;i++) {
        for(ll j=i;j<=n;j++) {
            for(ll k=j;k<=n;k++) {
                ans=max(ans,lcm(i,j,k));
                //cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
