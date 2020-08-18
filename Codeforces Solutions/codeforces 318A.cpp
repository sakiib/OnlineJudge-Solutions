#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve1(ll n,ll k) {
    ll x=n/2;
    if(k<=x) {
        cout<<2*k-1<<endl;
    }
    else {
        k%=x;
        cout<<k*2<<endl;
    }
    exit(0);
}
void solve2(ll n,ll k) {
    ll x=(ceil)(n*1.0/2);
    if(k<=x) {
        cout<<2*k-1<<endl;
    }
    else {
        k%=x;
        cout<<k*2<<endl;
    }
    exit(0);
}
int main(int argc,char const *argv[]) {
    ll n,k;
    cin>>n>>k;
    if(n==1) {
        cout<<1<<endl; return 0;
    }
    if(n%2==0) {
        if(k==n) {
            cout<<n<<endl; return 0;
        }
        solve1(n,k);
    }
    solve2(n,k);
    return 0;
}
