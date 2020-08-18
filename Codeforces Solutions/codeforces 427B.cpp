#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[200010];

int main(int argc,char const *argv[]) {
    ll n,t,c;
    cin>>n>>t>>c;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    ll cnt=0,ans=0,temp=0;
    for(int i=1;i<=n;i++) {
        if(ara[i]>t) {
            temp=cnt-c+1;
            cnt=0;
            if(temp>0) ans+=temp;
        }
        else cnt++;
    }
    temp=cnt-c+1;
    if(temp>0) ans+=temp;
    cout<<ans<<endl;
    return 0;
}
