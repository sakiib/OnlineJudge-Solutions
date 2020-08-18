#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(ll x) {
    if(x==0) return 0;
    if(x==1) return 1;
    if(x%2==0) {
        return solve(x/2);
    }
    if(x%2==1) {
        return (1+solve(x/2));
    }
    cerr<<"Problem if it comes here..."<<endl;
}
int main(int argc,char const *argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n;
    cin>>n;
    ll ara[100010];

    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    map<ll,ll> M;
    for(int i=0;i<n;i++) {
        ll a=solve(ara[i]);
        M[a]++;
    }
    ll ans=0;
    map<ll,ll> :: iterator it;
    for(it=M.begin();it!=M.end();it++) {
        ll k=it->second;
        if(k>=2) {
            ans+=(k*(k-1)/2);
        }
    }
    cout<<ans<<endl;
    return 0;
}
