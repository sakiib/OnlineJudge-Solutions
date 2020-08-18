#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 998244353;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

LL P[ 2*N ];
int on[ 2*N ];
LL ans;

void genPow( ) {
        P[0] = 1LL;
        for( int i = 1; i <= 2*N-1; i++ ) P[i] = ( P[i-1]%MOD * 2LL%MOD ) % MOD;
}
int main( int argc , char const *argv[] ) {
        FastIO;
        genPow( );
        int n , m;
        string a , b;
        cin >> n >> m;
        cin >> a >> b;
        while( n < m ) a = '0' + a , n++;
        while( m < n ) b = '0' + b , m++;
        for( int i = 0; i < m; i++ ) {
                if( i == 0 ) on[i] = ( b[i] == '1' );
                else on[i] += on[i-1] + ( b[i] == '1' );
        }
        for( int i = 0 , p = n-1; i < m; i++ , p-- ) {
                if( a[i] == '1' ) {
                        ans = ( ans%MOD + on[i]%MOD * P[p]%MOD ) % MOD;
                }
        }
        cout << ans << endl;
        return 0;
}







