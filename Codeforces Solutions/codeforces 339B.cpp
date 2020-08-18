#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll n,m;
    cin>>n>>m;
    int ara[100010];
    for(int i=1;i<=m;i++) {
        cin>>ara[i];
    }
    ll ans=0,in=1;
    for(int i=1;i<=m;i++) {
        if(ara[i]>in) {
            ans+=(ara[i]-in);
            in=ara[i];
        }
        else if(in>ara[i]) {
            ans+=(n-in+1)+(ara[i]-1);
            in=ara[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
