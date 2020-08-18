#include<bits/stdc++.h>
using namespace std;

#define sc1(a)   scanf("%I64d",&a)
#define sc2(a,b) scanf("%I64d%I64d",&a,&b)
#define pf1(a)   printf("%I64d\n",a)
#define ll long long
set<pair<ll,ll> > S;
map<ll,ll> M,N;
map<pair<ll,ll>,ll> B;

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,x,y;
    sc1(n);
    for(int i=1;i<=n;i++) {
        sc2(x,y);
        S.insert(make_pair(x,y));
        M[x]++; N[y]++; B[make_pair(x,y)]++;
    }
    //cout<<S.size()<<endl;
    ll ans=0;
    for(auto &it : M) {
        if(it.second>=2) {
            ll k=it.second; ans+=(k*(k-1)/2);
        }
    }
    //cerr<<ans<<endl;
    for(auto &it : N) {
        if(it.second>=2) {
            ll k=it.second; ans+=(k*(k-1)/2);
        }
    }
    //cerr<<ans<<endl;
    ll bad=0;
    for(auto &it : B) {
        pair<ll,ll> p=it.first;
        cerr<<p.first<< " "<<p.second<< " "<<it.second<<endl;
        if(it.second>=2) {ll y=it.second; bad+=(y*(y-1)/2);}
    }
    //cerr<<bad<<endl;
    pf1(ans-bad);
    return 0;
}
