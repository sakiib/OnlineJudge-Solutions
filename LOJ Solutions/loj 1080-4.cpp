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
#define Read            freopen("input.txt", "r" ,stdin)
#define Write           freopen("output.txt", "w" ,stdout)

#define scanI(a)        scanf("%d",&a)
#define scanI2(a,b)     scanI(a), scanI(b)
#define scanI3(a,b,c)   scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a)        scanf("%lld",&a)
#define scanL2(a,b)     scanL(a), scanL(b)
#define scanL3(a,b,c)   scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

char str[N],s[10];
int BIT[N];

void update(int idx,int val) {
    while(idx<=N) {
        BIT[idx]+=val;
        idx+=(idx & -idx);
    }
}
int query(int idx){
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
       scanf("%s",str);
       int q;
       scanI(q);
       printf("Case %d:\n",tc);
       for(int i=1;i<=q;i++) {
         scanf("%s",s);
         if(s[0]=='I') {
            int l,r;
            scanI2(l,r);
            update(l,1);
            update(r+1,-1);
         }
         else {
            int pos;
            scanI(pos);
            int ans=query(pos);
            if(ans%2==0) {
                printf("%c\n",str[pos-1]);
            }
            else {
                if(str[pos-1]=='1') printf("0\n");
                else printf("1\n");
            }
         }
       }
       MEM(BIT,N-1);
    }
    return 0;
}



