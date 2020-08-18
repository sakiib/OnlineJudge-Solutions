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

#define FOR1(i,a,b)  for(int i=a; i<=b ;i++)
#define FOR0(i,a)    for(int i=0; i<a ;i++)
#define CLR(a,n)     FOR0(i,n) a[i].clear()
#define MEM(a,x)     memset(a, x ,sizeof(a))
#define Read         freopen("input.txt", "r" ,stdin)
#define Write        freopen("output.txt", "w" ,stdout)


LL ara[N*10];
LL cnt[100*N];
LL val[100*N];
bool visited[100*N];

int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    FOR1(i,1,n) {
        scanf("%lld",&ara[i]);
        cnt[ara[i]]++;
    }
    for(LL i=2;i<=10000000;i++) {
        if(visited[i]) continue;
        for(LL j=i;j<=10000000;j+=i) {
            val[i]+=cnt[j];
            visited[j]=true;
        }
    }
    for(LL i=2;i<=10000000;i++) {
        val[i]+=val[i-1];
    }
    int m;
    scanf("%d",&m);
    while(m--) {
        LL l,r;
        scanf("%lld%lld",&l,&r);
        if(l>r) swap(l,r);
        r=min(r,10000000LL);
        l=min(l,10000000LL);
        printf("%lld\n",val[r]-val[l-1]);
    }
    return 0;
}



