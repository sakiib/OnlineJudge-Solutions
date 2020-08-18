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


int ara[N], n;
bool in;
bool de;
vector<int> a,b;

bool inc(int *ara) {
    for(int i=2;i<=n;i++) {
        if(ara[i]>=ara[i-1]) continue;
        else return false;
    }
    in=true;
    return true;
}
bool dec(int *ara) {
    for(int i=1;i<n;i++) {
        if(ara[i]>=ara[i+1]) continue;
        else return false;
    }
    return true;
    de=true;
}
int main(int argc,char const *argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    if(n==1||n==2) {
        printf("-1\n");
        return 0;
    }
    in=false;
    de=false;

    inc(ara); dec(ara);

    if(in&&de) {
        cout<<-1<<endl;
        return 0;
    }
    if(in) {
        for(int i=1;i<n;i++) {
            if(ara[i]<ara[i+1]) {
                cout<<i<<" "<<i+1<<endl;
                return 0;
            }
        }
    }
    if(de) {
        for(int i=1;i<n;i++) {
            if(ara[i]>ara[i+1]) {
                cout<<i<<" "<<i+1<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<n;i++) {
        if(ara[i]!=ara[i+1]) {
            swap(ara[i],ara[i+1]);
            if(inc(ara)||dec(ara)) {
                swap(ara[i],ara[i+1]);
            }
            else {
                cout<<i<<" "<<i+1<<endl;
                return 0;
            }
        }
    } cout<<-1<<endl;
    return 0;
}



