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

int cost[N];
bool used[N];
int path[N];

inline int String_Int (string &str) {
    int num; stringstream st(str);
     st>>num; return num;
}
inline string Int_String (int num) {
    string res; stringstream convert;
    convert<<num; res=convert.str();
    return res;
}
bool prime(int x) {
    if(x<2) return false;
    int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {
        if(x%i==0) return false;
    }
    return true;
}
void bfs(string &a,string &b) {
    for(int i=100;i<=99999;i++) {
        cost[i]=inf;
    }
    int s=String_Int(a);
    cost[s]=0;
    queue<int> Q;

    Q.push(s);

    while(!Q.empty()) {
        int f=Q.front();
        Q.pop();
        string st=Int_String(f);
        if(st==b) break;
        for(int i=0;i<4;i++) {
            for(int j=0;j<=9;j++) {
              string n=st;
              n[i]=(j+'0');
              if(!prime(String_Int(n))||(String_Int(n)<1000)) continue;
              if(cost[String_Int(n)]==inf) {
                cost[String_Int(n)]=cost[f]+1;
                Q.push(String_Int(n));
              }
           }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        string a,b;
        cin>>a>>b;
        bfs(a,b);
        int nb=String_Int(b);
        if(cost[nb]==inf) printf("Impossible\n");
        else printf("%d\n",cost[nb]);
    }
    return 0;
}



