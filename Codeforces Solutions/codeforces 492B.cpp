#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll n,l;
    cin>>n>>l;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+n+1);
    double mx=0.0;
    ll st=0.0,en=l*1.0;
    mx=max((double)(ara[1]-st),mx);
    mx=max((double)(l-ara[n]),mx);
    for(int i=1;i<n;i++) {
        mx=max(mx,(double)(ara[i+1]-ara[i])/2.0);
    }
    cout<<setprecision(10)<<fixed;
    cout<<mx<<endl;
    return 0;
}
