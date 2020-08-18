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

map<char,int> M;

int main(int argc,char const *argv[]) {
    string a,b,c;
    cin>>a>>b>>c;
    if(a[1]=='>') M[a[0]]++;
    else M[a[2]]++;
    if(b[1]=='>') M[b[0]]++;
    else M[b[2]]++;
    if(c[1]=='>') M[c[0]]++;
    else M[c[2]]++;
    //cout<<M['A']<<" "<<M['B']<<" "<<M['C']<<endl;
    if(M['A']==2&&M['B']==1&&M['C']==0) cout<<"CBA"<<endl;
    else if(M['A']==2&&M['C']==1&&M['B']==0) cout<<"BCA"<<endl;
    else if(M['B']==2&&M['A']==1&&M['C']==0) cout<<"CAB"<<endl;
    else if(M['B']==2&&M['C']==1&&M['A']==0) cout<<"ACB"<<endl;
    else if(M['C']==2&&M['A']==1&&M['B']==0) cout<<"BAC"<<endl;
    else if(M['C']==2&&M['B']==1&&M['A']==0) cout<<"ABC"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}



