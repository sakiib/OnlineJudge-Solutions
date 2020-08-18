#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(int argc,char const *argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,a,b,p,q;
    ll ans=0,cnt1=0,cnt2=0;

    set<ll> S;
    map<ll,ll> M;
    map<ll,bool> used;

    cin>>n>>a>>b>>p>>q;
    for(ll i=a;i<=n;i+=a) {
       S.insert(i);
       M[i]++;
    }
    for(ll i=b;i<=n;i+=b) {
        S.insert(i);
        M[i]++;
    }
    set<ll> :: iterator it;
    for(it=S.begin();it!=S.end();it++) {
        ll x=*it;
        if(M[x]==2) ans+=max(p,q);

    }
    cout<<ans<<endl;
    return 0;
}
