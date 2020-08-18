#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[100010];

void check(ll *ara) {
    for(int i=1;i<=50;i++) {
        cerr<<ara[i]<<endl;
    }
}
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ara[0]=0,ara[1]=1;
    for(int i=2;i<=50;i++) {
        ara[i]=ara[i-1]+ara[i-2];
    }
    check(ara);
    if(n==0) {
        cout<<"0 0 0"<<endl;
        return 0;
    }
    if(n==1) {
        cout<<"1 0 0"<<endl;
        return 0;
    }
    if(n==2) {
        cout<<2<<" "<<0<<" "<<0<<endl;
        return 0;
    }
    for(int i=0;i<=50;i++) {
        if(ara[i]==n) {
            cout<<ara[i-1]<<" "<<ara[i-3]<<" "<<ara[i-4]<<endl;
            return 0;
        }
    }
    return 0;
}
