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

int ara[100];
pair<int,int> P[100];

int main(int argc,char const *argv[]) {
    int n;
    scanI(n);
    int mn=inf,dig=inf;
    for(int i=1;i<=9;i++) {
        scanI(ara[i]);
        if(ara[i]<=mn) {
           mn=ara[i];
           dig=i;
        }
    }
    if(n==0) {
        printf("-1\n");
        return 0;
    }
    int len=n/mn;
    //printf("%d %d\n",len,dig);
    string ans="";
    for(int i=1;i<=len;i++) {
        ans+=(dig+'0');
    }
    if(ans.size()==0) {
        printf("-1\n");
        return 0;
    }
    //cout<<ans<<endl;
    int left=mn+n%mn;

    //printf("%d\n",left);

    for(int i=0;i<ans.size();i++) {
        for(int j=9;j>=1;j--) {
            if(ans[i]-'0'<j) {
                if(left>=ara[j]) {
                    ans[i]=j+'0';
                    left+=mn;
                    left-=ara[j];
                    break;
                }
            }
        }
    } cout<<ans<<endl;
    return 0;
}



