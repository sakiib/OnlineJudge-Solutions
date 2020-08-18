#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int k,ah,am;
        scanf("%d",&k);
        scanf("%d:%d",&ah,&am);
        int tot1=ah*60+am;
        int mn=1000000000,tot=0;
        for(int i=1;i<=k;i++) {
            int bh,bm,time;
            scanf("%d:%d%d",&bh,&bm,&time);
            int tot2=bh*60+bm;
            if(tot1<=tot2) tot=(tot2-tot1)+time;
            else tot=(tot2+1440-tot1)+time;
            mn=min(mn,tot);
        }
        printf("Case %d: %d\n",tc,mn);
    }
    return 0;
}
