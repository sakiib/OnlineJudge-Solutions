#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> a,b;
set<ll> S;
const ll inf=(ll)(1e15);
ll mx=-inf;
ll ans=-inf;

int main(int argc,char const *argv[]) {
    ll n,m;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int num;
        cin>>num;
        a.push_back(num);
        S.insert(num);
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        int num;
        cin>>num;
        b.push_back(num);
        S.insert(num);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    S.insert(0);
    set<ll> :: iterator it;
    for(it=S.begin();it!=S.end();it++) {

        ll x=upper_bound(a.begin(),a.end(),*it)-a.begin();
        ll y=upper_bound(b.begin(),b.end(),*it)-b.begin();
        cerr<<x<<" "<<y<<endl;
        ll val_a=x*2+(n-x)*3;
        ll val_b=y*2+(m-y)*3;
        if((val_a-val_b==mx&&val_a>ans)||(val_a-val_b)>mx) {
            mx=val_a-val_b;
            ans=val_a;
        }
        cerr<<*it<<" "<<val_a<<" "<<val_b<<endl;
    }
    cout<<ans<<":"<<ans-mx<<endl;
    return 0;
}
