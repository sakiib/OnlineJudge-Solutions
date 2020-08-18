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

vector < LL > V;

void dfs( LL x ) {
    V.push_back( x );
    if( x > inf ) return;
    dfs( 10*x+4 );
    dfs( 10*x+7 );
}
LL Binary_Search( LL val ) {
    LL lo = 0 , hi = V.size()-1;
    LL ret = 0;
    while( lo <= hi ) {
        LL mid = (lo+hi)>>1;
        if( V[mid] >= val ) {
            ret = V[mid];
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    dfs( 0 );
    sort( V.begin() ,V.end() );
    LL l , r;
    cin >> l >> r;
    LL ans = 0;
    while( l <= r ) {
        LL val = Binary_Search( l );
        ans += ( min( val , r)-l+1 )*val;
        l = min( val , r )+1;
    }
    cout << ans <<endl;
    return 0;
}

