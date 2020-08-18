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

LL Remove( LL x ) {
    LL ret = 0LL;
    vector < LL > V;
    while( x ) {
       LL rem = x%10;
       if( rem != 0 ) V.push_back( rem );
       x /= 10;
    }
    reverse( V.begin() , V.end() );
    LL res = 0LL;
    for( auto x : V ) res = res*10+x;
    return res;
}
int main( int argc, char const *argv[] ) {
    LL a , b;
    cin >> a >> b;
    LL c = a+b;
    LL x = Remove( a );
    LL y = Remove( b );
    LL z = Remove( c );
    cout << ( x+y == z ? "YES" : "NO" ) << endl;
    return 0;
}

