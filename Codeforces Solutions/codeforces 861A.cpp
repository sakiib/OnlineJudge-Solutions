#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc,char const *argv[]) {
    ll n,k;
    cin>>n>>k;
    ll t=1LL;
    for(int i=1;i<=k;i++) {
        t*=10;
    }
    ll res=(n*t);
    res/=(__gcd(n,t));
    cout<<res<<endl;
    return 0;
}
