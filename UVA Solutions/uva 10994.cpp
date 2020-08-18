#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[100010000];
ll l,r;

ll calc(ll n) {
    ll ans=0;
    while(n) {
        ll x=n%10;
        n/=10;
        ans+=(n*45+(x*(x+1)/2));
    }
    return ans;
}
int main(int argc,char const *argv[]) {

    while(cin>>l>>r) {
        if(l==-1&&r==-1) break;
        cout<<calc(r)-calc(l-1)<<endl;
    }
    return 0;
}
