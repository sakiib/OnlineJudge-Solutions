#include<bits/stdc++.h>
using namespace std;

#define ll long long
/// __builtin_popcount(x) = number of one's in binary rep. of x

int main(int argc,char const *argv[]) {
    ll t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        ll n,ans;
        cin>>n;
        ll temp=n+1;
        ll val=__builtin_popcount(n);
        for(ll i=temp; ;i++) {
            ll res=__builtin_popcount(i);
            if(res==val) {
                ans=i;
                break;
            }
        }
        printf("Case %lld: %lld\n",tc,ans);
    }
    return 0;
}
