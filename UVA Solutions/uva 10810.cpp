#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[500010];

int main(int argc,char const *argv[]) {
    ll n;
    while(cin>>n) {
        if(n==0) break;
        for(ll i=1;i<=n;i++) {
            cin>>ara[i];
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++) {
            for(ll j=i+1;j<=n;j++) {
                if(ara[i]>ara[j]) swap(ara[i],ara[j]),cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
