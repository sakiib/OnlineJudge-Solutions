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

int r,c;
string str[200];

int main(int argc,char const *argv[]) {
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++) {
        cin>>str[i];
    }
    string ans="";
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            int cnt=0;
            for(int m=0;m<r;m++) {
                if(str[m][j]==str[i][j]) cnt++;
            }
            for(int n=0;n<c;n++) {
                if(str[i][n]==str[i][j]) cnt++;
            }
            if(cnt==2) ans+=str[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}



