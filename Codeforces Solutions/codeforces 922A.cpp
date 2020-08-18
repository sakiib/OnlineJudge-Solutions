#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define mp          pake_pair
#define CLR(V)      V.clear()
#define SORT(V)     sort( V.begin(), V.end() )
#define REV(V)      sort( V.rbegin(), V.rend() )
#define MEM(a,x)    memset( a, x, sizeof(a) )
#define FOR(i,a,b)  for( int i = a; i <= b; i++ )
#define ROF(i,a,b)  for( int i = b; i >= a; i-- )
#define REP(i,a)    for( int i = 0; i < a; i++ )
#define debug(x)    cerr << "The value is "<< x << endl
#define Unique(a)   sort( all(a)), a.erase( unique( all(a) ), a.end() )
#define UB(a,key)   upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)   lower_bound( a.begin(), a.end(), key )-a.begin()


int main( int argc, char const *argv[] ) {
    LL x , y;
    scanf("%lld %lld",&x,&y);
    if( y == 0 ) return puts("No"),0;
    if( y == 1 && x > 0 ) return puts("No"),0;
    LL rem = x-y+1;
    if( rem < 0 || rem%2 ) return puts("No"),0;
    puts("Yes");
    return 0;
}


