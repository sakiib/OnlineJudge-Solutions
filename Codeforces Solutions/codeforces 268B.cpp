#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(int argc,char const *argv[]) {
    ll n,k,ara[20000]={0};
    cin>>n;
    k=n;
    ll ans=0;
    ans=n*(n+1)/2;
    ll extra=0;
    for(int j=2;j<n;j++) {
        for(int i=1;i<j;i++) {
            ara[i]+=(k-j);
        }
    }
    for(int i=1;i<=k;i++) {
        extra+=ara[i];
    }
    cout<<ans+extra<<endl;
    return 0;
}

