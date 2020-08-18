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

int ara[2*N];
int BIT[2*N];
int ans[2*N];

void update(int idx,int val) {
    while(idx<=2*N) {
        BIT[idx]+=val;
        idx+=(idx & -idx);
    }
}
int query(int idx) {
    int sum=0;
    while(idx>0) {
        sum+=BIT[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    int t;
    scanI(t);
    for(int tc=1;tc<=t;tc++) {
        int n;
        scanI(n);
        for(int i=1;i<=n;i++) {
            scanI(ara[i]);
        }
        for(int i=n;i>=1;i--) {
            int lo=1,hi=n;
            while(lo<=hi) {
                int mid=(lo+hi)/2;
                if(i-mid+query(mid)<=ara[i]) hi=mid-1;
                else lo=mid+1;

            }
            ans[i]=lo;
            update(lo,1);
        }
        for(int i=1;i<=n;i++) {
            if(i==1) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        printf("\n");
        MEM(BIT,0);
    }
    return 0;
}



