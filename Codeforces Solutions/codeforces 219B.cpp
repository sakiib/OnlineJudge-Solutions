#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll counter(ll num) {
    int ret=0;
    while(num!=0) {
        int a=num%10;
        if(a==9) ret++;
        else break;
        num=num/10;
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    ll n,p;
    cin>>n>>p;
    ll ara[100];
    ara[1]=10;
    for(ll i=2;i<=18;i++) {
        ara[i]=ara[i-1]*10;
    }
    if(p==0) {
        cout<<n<<endl;
        return 0;
    }
    ll mx=counter(n),val=n;
    for(int i=1;i<=18;i++) {
        ll ans=n-n%ara[i]-1;
        if(ans<(n-p)) continue;
        //cout<<ans<<endl;
        ll calc=counter(ans);
        if(calc>mx) {
            mx=calc;
            val=ans;
        }
    }
    cout<<val<<endl;
    return 0;
}
