#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL INF=10000000000;
LL ara[100010];

int main(int argc,char const *argv[]) {
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    LL ans=0,sum=0;
    ara[0]=0LL;
    for(int i=1;i<=n;i++) {
        if(ara[i]>ara[i-1]) {
            ans+=sum;
            sum=0;
        }
        else {
            sum+=(ara[i-1]-ara[i]);
        }
    }
    if(sum!=0) ans+=sum;
    cout<<ans<<endl;
    return 0;
}
