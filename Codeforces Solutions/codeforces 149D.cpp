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

int n;
int ara[N], sum[N]={0};
int mx=0;
bool visited[N];

int main(int argc,char const *argv[]) {
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
        mx=max(mx,ara[i]);
        tot+=ara[i];
    }
    for(int i=1;i<=n;i++) {
        sum[i]=ara[i];
        sum[i]+=sum[i-1];
    }
    int k=n/2;
    int j=0;
    bool f=false;
    vector<int> A,B;
    for(int i=1;i<n;i++) {
        int team1=sum[k+j]-sum[i-1];
        j++;
        int team2=tot-team1;
        if(abs(team2-team1)<=mx) {
          for(int l=i;l<k+j;l++) {
            A.push_back(l);
            visited[l]=true;
            f=true;
          }
        }
        if(f) break;
    }
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            B.push_back(i);
        }
    }
    cout<<A.size()<<endl;
    for(int i=0;i<A.size();i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<B.size()<<endl;
    for(int i=0;i<B.size();i++) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    return 0;
}



