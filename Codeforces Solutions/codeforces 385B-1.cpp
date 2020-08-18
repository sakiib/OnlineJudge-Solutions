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


int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    if(str.size()<4) {
        printf("0\n");
        return 0;
    }
    string s="bear";
    LL ans=0;
    FOR0(i,str.size()) {
        FOR1(j,i,str.size()-4) {
            if(str.substr(j,4)==s) {
                ans++;
                ans+=(str.size()-(j+4));
                break;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}



