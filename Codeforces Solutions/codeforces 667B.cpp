#include<bits/stdc++.h>
using namespace std;
#define ll long long
void check(ll a,ll b,ll c) {
    if(a+b>c&&b+c>a&&a+c>b) cout<<"yes";
    else cout<<"No"<<endl;
    return;
}
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+n+1);
    reverse(ara+1,ara+n+1);
    ll a=ara[1];
    ll b=0;
    for(int i=2;i<=n;i++) {
        b+=ara[i];
    }
    //cerr<<b<<endl;
    ll c=abs(a-b)+1;
    //check(a,b,c);
    cout<<c<<endl;
    return 0;
}
