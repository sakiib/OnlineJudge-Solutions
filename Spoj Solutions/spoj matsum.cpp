#include<bits/stdc++.h>
using namespace std;

const int N=1200;
int BIT[N][N];


void update(int idx,int idy,int val) {
    while(idx<=N) {
        while(idy<=N) {
            BIT[idx][idy]+=val;
            idy+=(idy & -idy);
        }
        idx+=(idx & -idx);
    }
}
int query(int idx,int idy) {
    int sum=0;
    while(idx>0) {
        while(idy>0) {
            sum+=BIT[idx][idy];
            idy-=(idy & -idy);
        }
        idx-=(idx & -idx);
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                BIT[i][j]=0;
            }
        }
        while(true) {
        char str[10];
        scanf("%s",str);
        if(strcmp(str,"SUM")==0) {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1++, y1++, x2++, y2++;
            int ans=0;
            ans+=query(x2,y2);
            ans+=query(x1-1,y1-1);
            ans-=query(x1-1,y2);
            ans-=query(x2,y1-1);
            printf("%d\n",ans);
        }
        if(strcmp(str,"SET")==0) {
            int x,y,val;
            scanf("%d%d%d",&x,&y,&val);
            x++, y++;
            update(x,y,val);
        }
        if(strcmp(str,"END")==0) break;
        }
    }
    return 0;
}
