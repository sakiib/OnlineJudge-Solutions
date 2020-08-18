#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010]={0},b[200010]={0};
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(q--) {
        ll l,r;
        cin>>l>>r;
        b[l]++;
        b[r+1]--;
    }
    for(int i=1;i<=n;i++) {
        b[i]+=b[i-1];
    }
    /*for(int i=1;i<=n;i++) {
        cout<<b[i]<< " ";
    }*/
    sort(b+1,b+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++) {
        sum+=a[i]*b[i];
    }
    cout<<sum<<endl;
    return 0;
}
