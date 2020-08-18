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


vector<LL> prime;
vector<bool> isprime(10000010,true);

inline void sieve() {
     isprime[0]=false,isprime[1]=false;
     prime.push_back(2);

     for(LL i=4;i<=10000000;i+=2) {
         isprime[i]=false;
     }
     LL sq=sqrt(10000000);
     for(LL i=3;i<=sq;i+=2) {
        if(isprime[i]) {
            for(LL j=i*i;j<=10000000;j+=2*i) {
                isprime[j]=false;
            }
        }
     }
    for(LL i=3;i<=10000000;i+=2) {
       if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        printf("%lld ",prime[i]);
    }
    return 0;
}



