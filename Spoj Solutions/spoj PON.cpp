#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

uLL mulmod( uLL a , uLL b , uLL c ) {
        uLL x = 0 , y = a%c;
        while( b > 0 ) {
                if( b&1 ) x = ( x + y ) % c;
                y = ( y << 1 ) % c;
                b = b >> 1;
        }
        return x;
}
uLL modulo( uLL a , uLL b , uLL c ) {
        uLL x = 1 , y = a % c;
        while( b > 0 ) {
                if( b&1 ) x = mulmod( x , y , c );
                y = mulmod( y , y , c );
                b = b >> 1;
        }
        return x;
}
bool miller( uLL p , int iter ) {
        if( p < 2 ) return false;
        if( p == 2 ) return true;
        if( !( p&1 ) ) return false;
        uLL s = p - 1 , a , temp , mod;
        while( !( s&1 ) ) s = s >> 1;
        for( int i = 0; i < iter; i++ ) {
                a = rand( ) % ( p - 1 ) + 1;
                temp = s;
                mod = modulo( a , temp , p );
                while( temp != ( p - 1) && mod != 1 && mod != ( p - 1 ) ) {
                        mod = mulmod( mod , mod , p );
                        temp = temp << 1;
                }
                if( mod != ( p - 1 ) && !( temp&1 ) ) return false;
        }
        return true;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                uLL n;
                scanf("%llu",&n);
                if( miller( n , 1 ) ) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}






