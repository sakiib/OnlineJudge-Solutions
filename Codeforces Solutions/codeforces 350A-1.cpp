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
    int n;
    while(scanf("%d",&n)) {
        if(n==0) break;
        int ara[N];
        priority_queue<int,vector<int>,greater<int> > Q;
        for(int i=0;i<n;i++) {
            scanf("%d",&ara[i]);
            Q.push(ara[i]);
        }
        int sum=0,ans=0;
        while( !Q.empty() ) {
            int tp=Q.top();
            Q.pop();
            if(Q.empty()) break;
            sum=tp;
            sum+=Q.top();
            Q.pop();
            ans+=sum;
            Q.push(sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}



