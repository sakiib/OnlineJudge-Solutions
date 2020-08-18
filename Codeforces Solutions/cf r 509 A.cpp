#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
LL h;
LL x[ 2*N ] , y [ 2*N ];

LL calc( int id ) {
        LL X = x[id] , Y = h;
        LL d = 0;
        for( int i = id; i <= n; i++ ) {
                d += ( y[i] - x[i] );
                if( Y <= 0 ) break;
                if( i != n ) {
                        LL dif = x[i+1] - y[i];
                        if( Y <= dif ) {
                                d += Y;
                                Y = 0;
                                break;
                        }
                        else {
                                Y -= dif;
                                d += dif;
                        }
                }
        }
        if( abs(d-X) > inf ) return d;
        if( Y > 0 ) d += Y;
        return d;
}
LL TernarySearch( ) {
        int t = 750;
        int lo = 1 , hi = n;
        LL ret = -INF;
        while( t-- ) {
              LL midL = ( 2*lo + hi )/3 , midR = ( lo + 2*hi )/3;
              LL x = calc( midL ) , y = calc( midR );
              if( x > y )  ret = max( ret , x ) , hi = midR;
              else ret = max( ret , y ) , lo = midL;
        }
        for( int i = lo; i <= hi; i++ ) ret = max( ret , calc( i ) );
        //ret = max( ret , max( calc( lo ) , calc( hi ) ) );
        return ret;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n >> h;
        for( int i = 1; i <= n; i++ ) cin >> x[i] >> y[i];
        //cout << calc( 1 ) << endl;
        cout << TernarySearch() << endl;
        return 0;
}





