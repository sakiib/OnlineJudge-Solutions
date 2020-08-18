#include<bits/stdc++.h>
using namespace std;


#define ll long long
ll ara[200010],keep[200010];

int main(int arc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        ara[i]+=ara[i-1];
        keep[i]+=(ara[i]);
    }
    for(int i=k;i<=n;i++) {
       keep[i]=ara[i]-ara[i-k];
    }
    /*for(int i=1;i<=n;i++) {
       cout<<keep[i]<< " ";
    }*/
    ll mx=0,l,r;
    for(int i=n-k+1;i>k;i--) {
        if(keep[i+k-1]>=mx) {
            mx=keep[i+k-1];
            r=i;
        }
    }
    ll mx1=0;
    for(int i=1;i+k-1<r;i++) {
        if(keep[i+k-1]>mx1) {
            mx1=keep[i+k-1];
            l=i;
        }
    }
    cout<<l<< " "<<r<<endl;
    return 0;
}
