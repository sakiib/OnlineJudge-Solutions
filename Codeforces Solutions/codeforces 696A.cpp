#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
#define ii                       pair < int, int >
#define iii                      pair < int, ii >
#define FOR( i, a, b )           for( int i = a; i <= b; i++ )
#define ROF( i, a, b )           for( int i = a; i >= b; i-- )
#define pb                       push_back
#define mp                       make_pair
#define line                     cerr << "***** here *****" << endl;
#define all( V )                 V.begin(), V.end()
#define Unique( a )              sort(all(a)),a.erase(unique(all(a)),a.end())
#define sc                       scanf
#define pf                       printf
#define Fix( x )                 setprecision( x ) << fixed
#define mem( a, x )              memset( a, x, sizeof( a ) )


map < pair <LL,LL> , LL > M;

LL LCA( LL u , LL v ) {
    while( u != v ) {
        if( u < v ) swap( u , v );
        u /= 2;
    }
    return u;
}
void Update( LL node ,  LL w , LL lca ) {
    if( node == lca ) return;
    while( true ) {
        LL cur = node;
        LL next = cur/2;
        M[ {cur,next} ] += w;
        M[ {next,cur} ] += w;
        node = next;
        if( next == lca ) break;
    }
}
LL Query( LL node , LL lca ) {
    if( node == lca ) return 0;
    LL ret = 0;
    while( 1 ) {
        LL next = node/2;
        ret += M[ {node,next} ];
        node /= 2;
        if( node == lca ) break;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    int q;
    cin >> q;
    while( q-- ) {
        int op;
        cin >> op;
        if( op == 1 ) {
            LL u , v , w;
            cin >> u >> v >> w;
            LL lca = LCA( u , v );
            Update( u , w , lca );
            Update( v , w , lca );
        }
        else {
            LL u , v;
            cin >> u >> v;
            LL lca = LCA( u , v );
            LL ans = 0;
            ans += Query( u , lca ) + Query( v , lca );
            cout << ans << endl;
        }
    }
    return 0;
}






