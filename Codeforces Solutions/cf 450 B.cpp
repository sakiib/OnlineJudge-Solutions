#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const  int inf = 1e9;
const  LL INF = 1e18;
const  int N = 100005;
const  int MOD = 1e9+7;
const  double EPS = 1e-6;
const  double PI = acos(-1.0);

#define FOR1(i,a,b)     for(int i = a; i <= b ; i++)
#define FOR0(i,a)       for(int i = 0; i < a ; i++)
#define CLR(a,n)        FOR0(i,n) a[i].clear()
#define MEM(a,x)        memset(a, x ,sizeof( a ))
#define Read            freopen( "input.txt", "r" ,stdin )
#define Write           freopen( "output.txt", "w" ,stdout )

int main( int argc,char const *argv[] ) {
    int x,y,c;
    cin>>x>>y>>c;
    vector<int> V;
    int t=100000;
    while(t--) {
        int a=x%y;
        x=a*10;
        V.push_back(x/y);
    }
    for(int i=0;i<V.size();i++) {
        if(V[i]==c) {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}



