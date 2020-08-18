#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int ara[100010];
    //cout<<__gcd(0,100)<<endl;
    //cout<<__gcd(0,0)<<endl;
    while(scanf("%d",&ara[1])) {
        int t=1;
        int mx=0;
        ara[1]=abs(ara[1]);
        if(ara[1]==0) break;
        for(int i=2; ; i++) {
            scanf("%d",&ara[i]);
            if(ara[i]==0) break;
            t++;
        }
        int ans=0;
        for(int i=1;i<=t;i++) {
            for(int j=i+1;j<=t;j++) {
                int k=abs(ara[i]-ara[j]);
                if(k==0) continue;
                ans=__gcd(ans,k);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
