#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL N=100005+50005;
LL ara[N];
LL BIT[N];

void Update(LL idx,LL val) {
    while(idx<=N) {
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}
LL Query(LL idx) {
    LL sum=0;
    while(idx>0) {
        sum+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
LL Binary_Search(LL val) {
    LL lo=1,hi=N,ret=-1;
    while(lo<=hi) {
        LL mid=(lo+hi)/2;
        if(Query(mid)>=val) {
            ret=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        LL n,q;
        scanf("%lld%lld",&n,&q);
        for(LL i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
            Update(i,1);
        }
        LL tot=n;
        LL temp=n;
        char str[10];
        LL add;

        printf("Case %d:\n",tc);

        while(q--) {

          scanf("%s %lld",str,&add);
          if(str[0]=='c') {
            if(add>tot) {
             printf("none\n");
             continue;
            }
            else {
             LL pos=Binary_Search(add);
             printf("%lld\n",ara[pos]);
             tot--;
             Update(pos,-1);
            }
          }
          else if(str[0]=='a') {
            ara[++temp]=add;
            Update(temp,1);
            tot++;
          }
        }
        memset(BIT,0,sizeof(BIT));
    }
    return 0;
}
