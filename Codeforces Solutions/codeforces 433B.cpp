#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll a[100010],b[100010];
    a[0]=0; b[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++) {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    ll query;
    cin>>query;
    while(query--) {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1) {
            cout<<a[y]-a[x-1]<<endl;
        }
        else {
            cout<<b[y]-b[x-1]<<endl;
        }
    }
    return 0;
}
