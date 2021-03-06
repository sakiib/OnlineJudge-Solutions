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

int tree[3*4*N];
int ans[3*N]={0};

void update(int node,int b,int e,int i,int j,int winner) {
    if(i>e||j<b||tree[node]==inf) return;
    if(b==e) {
        if(b==winner) return;
        tree[node]=inf;
        ans[b]=winner;
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    update(left,b,mid,i,j,winner);
    update(right,mid+1,e,i,j,winner);
    tree[node]=min(tree[left],tree[right]);
}
int main(int argc,char const *argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int l,r,winner;
        scanf("%d%d%d",&l,&r,&winner);
        update(1,1,n,l,r,winner);
    }
    for(int i=1;i<=n;i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}


