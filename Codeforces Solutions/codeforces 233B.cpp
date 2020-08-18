#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dig_sum(ll x) {
    ll ret=0;
    while(x) {
        ll k=x%10;
        ret+=k;
        x/=10;
    }
    return ret;
}
ll calc(ll num) {
    ll d=dig_sum(num);
    return (d*num+num*num);
}
ll solve(ll n) {
    ll hi=sqrt(n);
    ll lo=max(0LL,(hi-1000));
    while(lo<=hi) {
        ll val=calc(lo);
        if(val==n) return lo;
        lo++;
    }
    return -1;
}
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll ans=solve(n);
    cout<<ans<<endl;
    return 0;
}
