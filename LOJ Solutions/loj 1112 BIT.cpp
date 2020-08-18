#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int ara[N];
int BIT[N];

void Update(int idx,int val) {
    while(idx<=N) {
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int Query(int idx) {
    int sum=0;
    while(idx>0) {
        sum+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            Update(i,ara[i]);
        }
        printf("Case %d:\n",tc);
        for(int i=1;i<=q;i++) {
            int op;
            scanf("%d",&op);
            if(op==1) {
                int pos;
                scanf("%d",&pos);
                pos++;
                printf("%d\n",ara[pos]);
                Update(pos,-ara[pos]);
                ara[pos]=0;
            }
            else if(op==2) {
                int pos,add;
                scanf("%d%d",&pos,&add);
                pos++;
                Update(pos,add);
                ara[pos]+=add;
            }
            else if(op==3) {
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                printf("%d\n",Query(r)-Query(l-1));
            }
        }
        memset(BIT,0,sizeof(BIT));
    }
    return 0;
}
