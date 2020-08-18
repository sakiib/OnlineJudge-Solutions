#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll ara[100010];
        ll mn=(ll)(1e10);
        for(int i=1;i<=n;i++) {
            cin>>ara[i];
        }
        sort(ara+1,ara+n+1);
        for(int i=1;i<n;i++) {
            mn=min(ara[i+1]-ara[i],mn);
        }
        cout<<mn<<endl;
    }
    return 0;
}
