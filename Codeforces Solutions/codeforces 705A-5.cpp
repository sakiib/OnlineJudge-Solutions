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
#define All(V)      V.begin(),V.end()
#define SORT(V)     sort( V.begin(), V.end() )
#define REV(V)      sort( V.rbegin(), V.rend() )
#define MEM(a,x)    memset( a, x, sizeof(a) )
#define FOR(i,a,b)  for( int i = a; i <= b; i++ )
#define ROF(i,a,b)  for( int i = b; i >= a; i-- )
#define REP(i,a)    for( int i = 0; i < a; i++ )
#define debug(x)    cerr << "The value is "<< x << endl
#define Unique(a)   sort( All(a)), a.erase( unique( All(a) ), a.end())
#define UB(a,key)   upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)   lower_bound( a.begin(), a.end(), key )-a.begin()

inline LL NumDigit ( LL x , LL y ) {return ((LL)(log10((x))/log10((y))))+1;}

LL calc( LL sum ) {
    LL x = 0;
    while( sum ) {
        x = max( x , sum%10 );
        sum /= 10;
    }
    return x;
}
int main( int argc, char const *argv[] ) {
    LL a , b;
    scanf("%lld %lld",&a,&b);
    LL sum = a+b;
    LL base = max( calc( a )+1 , calc( b )+1 );
    LL mx = 0;
    FOR( i , base , 10 ) {
        LL dig = NumDigit( sum , i );
        mx = max( mx , dig );
    }
    printf("%lld\n",mx);
    return 0;
}


