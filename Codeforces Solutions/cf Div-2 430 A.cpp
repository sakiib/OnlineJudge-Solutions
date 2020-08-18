#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    for(ll i=x;i<=y;i++) {
        ll val=1LL*i*k;
        if(val>=l&&val<=r) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

