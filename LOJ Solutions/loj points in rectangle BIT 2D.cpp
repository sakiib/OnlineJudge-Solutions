#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const  int inf = 1e9;
const  LL INF = 1e18;
const  int N = 100005;
const  int MOD = 1e9+7;
const  double EPS = 1e-6;
const  double PI = acos(-1.0);

#define FOR1(i,a,b)     for(int i=a; i<=b ;i++)
#define FOR0(i,a)       for(int i=0; i<a ;i++)
#define CLR(a,n)        FOR0(i,n) a[i].clear()
#define MEM(a,x)        memset(a, x ,sizeof(a))

#define scanI(a)        scanf("%d",&a)
#define scanI2(a,b)     scanI(a), scanI(b)
#define scanI3(a,b,c)   scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a)        scanf("%lld",&a)
#define scanL2(a,b)     scanL(a), scanL(b)
#define scanL3(a,b,c)   scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define Read            freopen("input.txt", "r" ,stdin)
#define Write           freopen("output.txt", "w" ,stdout)

int BIT[1005][1005];
int ara[1005][1005];

void update(int idx,int idy,int val) {
    int y=idy;
    while(idx<=1003) {
        idy=y;
        while(idy<=1003) {
            BIT[idx][idy]+=val;
            idy+=(idy & -idy);
        }
        idx+=(idx & -idx);
    }
}
int query(int idx,int idy) {
    int sum=0;
    int y=idy;
    while(idx>0) {
        idy=y;
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
    for(int tc=1;tc<=t;tc++) {
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--) {
            int op;
            scanf("%d",&op);
            if(op==0) {
                int x,y;
                scanf("%d%d",&x,&y);
                x++, y++;
                if(ara[x][y]==1) continue;
                else update(x,y,1), ara[x][y]=1;
            }
            else if(op==1) {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++, y1++, x2++, y2++;
                int ans=0;
                ans+=query(x2,y2);
                ans-=query(x1-1,y2);
                ans-=query(x2,y1-1);
                ans+=query(x1-1,y1-1);
                printf("%d\n",ans);
            }
        }
        MEM(BIT,0);
        MEM(ara,0);
    }
    return 0;
}




