#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF=99999999999LL;
ll ara[200010];
ll mx=-INF;
ll mn=INF;
map<ll,ll> M;

int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        mn=min(mn,ara[i]);
        mx=max(mx,ara[i]);
        M[ara[i]]++;
    }
    if(mx==mn) {
        cout<<mx-mn<< " " <<n*(n-1)/2<<endl;
        return 0;
    }
    cout<<mx-mn<< " "<<M[mx]*M[mn]<<endl;
    return 0;
}
