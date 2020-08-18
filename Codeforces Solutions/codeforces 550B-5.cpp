#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const int MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );
#define endl                   '\n'
#define ii                     pair < int, int >
#define iii                    pair < int, ii >
#define pll                    pair < LL, LL >
#define ff                     first
#define ss                     second
#define mp                     make_pair
#define pb                     push_back
#define Fix( x )               setprecision( x ) << fixed
#define MEM( a , x )           memset( a, x, sizeof( a ) )
#define ONBit( N , p )         ( N = N | ( 1 << p ) )
#define OFFBit( N , p )        ( N = N & ~( 1 << p ) )
#define CheckBit( N , p )      ( !( ( N & ( 1 << p ) ) == 0 ) )

int n , l , r , x;
int prob[ 20 ];
int ans = 0;

void solve( int mn , int mx , int tot , int taken , int id ) {
    if( id > n ) {
        if( ( tot >= l && tot <= r ) && abs( mx-mn ) >= x ) ans++;
        return;
    }
    solve( mn , mx , tot , taken , id+1  );
    solve( min( mn , prob[id] ), max( mx , prob[id] ) , tot+prob[id] , taken+1 , id+1 );
}
int main( int argc , char const *argv[] ) {
    scanf("%d %d %d %d",&n,&l,&r,&x);
    for( int i = 1; i <= n; i++ ) scanf("%d",&prob[i]);
    solve( inf+10 , 0 , 0 , 0 , 1 );
    printf("%d\n",ans);
    return 0;
}


