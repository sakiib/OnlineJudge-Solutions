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

inline string Int_String (int num) {
    string res; stringstream convert;
    convert<<num; res=convert.str();
    return res;
}
int ara[N][10];

void digit(int x) {
    int temp=x;
    while(x) {
        int rem=x%10;
        x/=10;
        ara[temp][rem]++;
    }
}
void calc() {
    for(int i=1;i<=100000;i++) {
        digit(i);
    }
    for(int i=1;i<=100000;i++) {
        for(int j=0;j<=9;j++) {
           ara[i][j]+=ara[i-1][j];
        }
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=9;i++) {
            if(i==0) printf("%d",ara[n][i]);
            else printf(" %d",ara[n][i]);
        }
        printf("\n");
    }
    return 0;
}



