#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n) {
    ll sum=0;
    if(n<10) return n;
    while(n) {
        sum+=(n%10);
        n/=10;
    }
    return solve(sum);
}
int main(int argc,char const *argv[]) {
    ll n;
    while(cin>>n) {
        if(n==0) break;
        ll ans=solve(n);
        cout<<ans<<endl;
    }
    return 0;
}
