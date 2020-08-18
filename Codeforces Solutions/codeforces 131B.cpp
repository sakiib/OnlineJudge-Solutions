#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<LL,LL> cnt;
map<LL,bool> used;
LL ara[100010];

int main(int argc,char const *argv[]) {
    LL n;
    cin>>n;
    LL ans=0,zer=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        cnt[ara[i]]++;
        if(ara[i]==0) zer++;
    }
    ans+=(zer*(zer-1)/2);
    for(int i=1;i<=n;i++) {
        if(!used[ara[i]]&&ara[i]!=0) {
            used[ara[i]]=true;
            LL match=-ara[i];
            used[match]=true;
            ans+=(cnt[ara[i]]*cnt[match]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
