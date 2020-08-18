#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc,char const *argv[]) {
    ll n,k,t;
    cin>>n>>k>>t;
    if(t<=k) {
        cout<<t<<endl; return 0;
    }
    if(t<=n) {
        cout<<k<<endl; return 0;
    }
    ll temp=n+k;
    ll ans=temp-t;
    cout<<ans<<endl;
    return 0;
}
