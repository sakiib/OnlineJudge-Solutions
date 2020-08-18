#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm(ll x,ll y) {
    return (x*y/(__gcd(x,y)));
}
ll calc(ll n) {
    ll ans=0;
    for(ll i=1;i<=n;i++) {
        for(ll j=i;j<=n;j++) {
            if(lcm(i,j)==n) {
                cout<<"i - j : "<<i<<" "<<j<<endl;
            }
        }
    }
    return ans;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        ll n;
        scanf("%lld",&n);
        cout<<calc(n)<<endl;
    }
    return 0;
}
