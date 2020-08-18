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

int ara[N];
int n;

int check(int idx) {
    int cnt=1;
    int mn=ara[idx];
    for(int i=idx-1;i>=1;i--) {
        if(ara[i]<=mn) {
            mn=ara[i]; cnt++;
        }
        else break;
    }
    mn=ara[idx];
    for(int i=idx+1;i<=n;i++) {
        if(ara[i]<=mn) {
            mn=ara[i]; cnt++;
        }
        else break;
    }
    return cnt;
}
int main(int argc,char const *argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    int mx=0;
    for(int i=1;i<=n;i++) {
        mx=max(mx,check(i));
        //cout<<"here : "<<mx<<endl;
    }
    printf("%d\n",mx);
    return 0;
}



