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

LL ExtGCD( LL a , LL b , LL &p , LL &q ) {
        if( b == 0 ) { p = 1 , q = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        p = y1;
        q = x1-(a / b)*y1;
        return gcd;
}
LL CRT( vector <LL> A , vector <LL> M ) {
        if( A.size() != M.size() ) return -1;
        LL mul = 1 , ret = 0;
        int l = A.size();
        for( int i = 0; i < l; i++ ) mul *= M[i];
        for( int i = 0; i < l; i++ ) {
                LL p , q;
                ExtGCD( M[i] , mul/M[i] , p , q );
                ret += ( A[i] * q * ( mul/M[i] ) );
                ret %= mul;
        }
        if( ret < 0 ) ret += mul;
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                cin >> n;
                vector <LL> A , M;
                for( int i = 1; i <= n; i++ ) {
                        LL a , m;
                        cin >> m >> a;
                        A.push_back( a ) , M.push_back( m );
                }
                LL ans = CRT( A , M );
                if( ans == -1 ) cout << "Case " << tc << ": " << "Impossible" << endl;
                cout << "Case " << tc << ": " << ans << endl;
        }
        return 0;
}






