#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll x,y;
    vector<ll> V;
    for(ll i=1;i<=1000000;i++) {
        V.push_back(i*i);
    }
    cin>>x>>y;
    ll ans=0;
    for(int i=0;i<V.size()-1;i++) {
        for(int j=i+1; ;j++) {
            if(V[j]-V[i]>y) break;
            else ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

