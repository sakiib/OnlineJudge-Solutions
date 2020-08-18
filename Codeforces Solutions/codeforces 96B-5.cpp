#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
#define endl         '\n'
#define EPS          1e-6
#define F            first
#define S            second
#define PI           acos(-1.0)
#define pb           push_back
#define mp           make_pair
#define pp           pop_back
#define SQ(x)        (((x)*(x)))
#define CU(x)        ((x)*(x)*(x))
#define ii           pair<int,int>
#define iii          pair<int,ii>
#define clr(V)       V.clear()
#define sz(V)        V.size()
#define All(V)       V.begin(),V.end()
#define SORT(V)      sort( V.begin(), V.end() )
#define REV(V)       sort( V.rbegin(), V.rend() )
#define MEM(a,x)     memset( a, x, sizeof(a) )
#define RIGHTMOST    __builtin_ctzll
#define POPCOUNT     __builtin_popcountll
#define LEFTMOST(x)  ( 63-__builtin_clzll((x)) )
#define CLR(a,n)     for(int i=0;i<n;i++) a[i].clear()
#define debug(x)     cerr << "X is : " << x << endl
#define FOR(i,a,b)   for( int i = a; i <= b; i++ )
#define ROF(i,a,b)   for( int i = b; i >= a; i-- )
#define REP(i,a)     for( int i = 0; i < a; i++ )
#define Read         freopen( "input.txt", "r", stdin )
#define Write        freopen( "output.txt", "w", stdout )
#define PQ(x)        priority_queue< x, vector<x>, greater<x> >
#define Unique(a)    sort(All(a)), a.erase(unique(All(a)), a.end())
#define UB(a,key)    upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)    lower_bound( a.begin(), a.end(), key )-a.begin()

vector < LL > V;

bool ok( LL x ) {
    int cnt[ 10 ] = {0};
    while( x ) {
        cnt[x%10]++;
        x /= 10;
    }
    return ( cnt[4] == cnt[7] );
}
void calc( LL x ) {
    if( x > INF ) return;
    if( x > 0 && ok( x ) ) V.pb( x );
    calc( 10*x+4 );
    calc( 10*x+7 );
}
int main(int argc,char const *argv[]) {
    calc( 0 );
    SORT( V );
    LL n;
    scanf("%lld",&n);
    LL pos = UB( V , n );
    if( V[pos] == n ) printf("%lld\n",n);
    else if( pos == 0 ) printf("%lld\n",V[pos]);
    else if( V[pos-1] < n ) printf("%lld\n",V[pos]);
    else printf("%lld\n",V[pos-1]);
    return 0;
}


