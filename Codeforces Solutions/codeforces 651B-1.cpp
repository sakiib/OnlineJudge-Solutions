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
bool visited[N];

/*
int Binary_Search(int lo,int hi,int val) {
    int ret=-1;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(ara[mid]<=val) lo=mid+1;
        if(ara[mid]>val) {
            ret=mid;
            hi=mid-1;
        }
    }
    return ret;
}*/
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
       scanf("%d",&ara[i]);
    }
    sort(ara+1,ara+n+1);
    int ans=0;
    /*
    for(int i=1;i<=n;i++) {
        int pos=Binary_Search(i+1,n,ara[i]);
        if(pos==-1) continue;
        else ans++;
        //printf("i : %d , pos : %d\n",i,pos);
    }*/
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(!visited[j]) {
                if(ara[j]>ara[i]) {
                    visited[j]=true;
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}



