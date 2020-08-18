#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll lcm(ll a,ll b) {
    return (a*b)/(__gcd(a,b));
}
int main(int argc,char const *argv[]) {
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    ll ans1=(n/a)*p;
    ll ans2=(n/b)*q;
    ll g=n/lcm(a,b);
    //cerr<<ans1<< " " <<ans2<<endl;
    cout<<ans1+ans2-g*min(p,q)<<endl;
    return 0;
}
