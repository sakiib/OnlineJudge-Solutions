#include<bits/stdc++.h>
using namespace std;

int cook[100001];
int n,prata;

int can(int time) {
    int res=0;
    for(int i=1;i<=n;i++) {
        int tm=0;
        int nxt=cook[i];
        while(tm+nxt<=time) {
            res++;
            tm+=nxt;
            nxt+=cook[i];
        }
    }
    return res;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d",&prata);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&cook[i]);
        }
        int lo=1,hi=5000000,ans=-1;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            if(can(mid)<prata) lo=mid+1;
            else {
                ans=mid;
                hi=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
