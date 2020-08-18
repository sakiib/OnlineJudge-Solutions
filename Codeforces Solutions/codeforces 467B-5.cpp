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

int val[ N ];

int main( int argc , char const *argv[] ) {
    int n , m , k;
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1; i <= m+1; i++ ) scanf("%d",&val[i]);
    int ans = 0;
    for( int i = 1; i <= m; i++ ) {
        int fed = val[m+1];
        int frnd = val[i];
        int x = 0;
        for( int i = 0; i <= 20; i++ ) {
            if( CheckBit( fed , i ) && !CheckBit( frnd , i ) ) x++;
            else if( !CheckBit( fed , i ) && CheckBit( frnd , i ) ) x++;
        }
        if( x <= k ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}


