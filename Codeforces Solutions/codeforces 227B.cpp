#include<bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll> F,R;

void Build(ll *ara,ll n) {
    for(int i=1;i<=n;i++) {
        F[ara[i]]=i;
        R[ara[i]]=(n-i+1);
    }
}
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    Build(ara,n);
    ll q,num;
    ll x=0,y=0;
    cin>>q;
    while(q--) {
        cin>>num;
        x+=F[num],y+=R[num];
    }
    cout<<x<< " " <<y<<endl;
    return 0;
}
