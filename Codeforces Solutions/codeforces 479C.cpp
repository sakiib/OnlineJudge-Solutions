#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    vector<pair<ll,ll> > V;
    for(int i=1;i<=n;i++) {
        ll a,b;
        cin>>a>>b;
        V.push_back({a,b});
    }
    sort(V.begin(),V.end());
    /*for(auto &x:V) {
        cout<<x.first<< " " <<x.second<<endl;
    }*/
    ll ans=-1;
    for(int i=0;i<V.size();i++) {
        if(ans<=V[i].second) {
            ans=V[i].second;
        }
        else ans=V[i].first;
    }
    cout<<ans<<endl;
    return 0;
}
