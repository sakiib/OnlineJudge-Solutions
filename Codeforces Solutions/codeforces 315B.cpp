#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll extra=0;
void see(ll *ara) {
    for(int i=1;i<=10;i++) {
        cout<<ara[i]+extra<< " ";
    }
    cout<<endl;
    return;
}
int main(int argc,char const *argv[]) {
    ll n,m,t,v,x,q,add=0;
    ll ara[100010];
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    while(m--) {
        cin>>t;
        if(t==1) {
            cin>>v>>x;
            ara[v]=x-extra;
            //cerr<<"here"<<ara[v]<<endl;
            //see(ara);
        }
        else if(t==3) {
            cin>>q;
            cout<<ara[q]+extra<<endl;
            //see(ara);
        }
        else if(t==2) {
            cin>>add;
            extra+=add;
            //see(ara);
        }
    }
    return 0;
}
