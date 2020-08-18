#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#define endl "\n"
#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

int p[ 2*N ];

int main( int argc , char const *argv[] ) {
        FastIO;
        int n;
        cin >> n;
        for( int i = 2; i <= n; i++ ) {
                int x;
                cin >> x;
                p[i] = x;
        }
        int k = n;
        vector <int> V;
        V.push_back( k );
        while( 1 ) {
                if( k == 1 ) break;
                k = p[k];
                V.push_back( k );
        }
        for( int i = V.size()-1; i >= 0; i-- ) cout << V[i] << " ";
        cout << endl;
        return 0;
}







