#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int ah,am,bh,bm;
    while(scanf("%d%d%d%d",&ah,&am,&bh,&bm)) {
        if(ah==0&&am==0&&bh==0&&bm==0) break;
        if(ah==0) ah=24;
        if(bh==0) bh=24;
        int cur=ah*60+am;
        int alrm=bh*60+bm;
        if(cur<=alrm) printf("%d\n",(alrm-cur));
        else printf("%d\n",1440-cur+alrm);
    }
    return 0;
}
