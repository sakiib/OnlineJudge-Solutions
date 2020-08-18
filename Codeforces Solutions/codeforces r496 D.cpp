#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define bug( a , b ) cerr<< #a <<" = "<<a<<" , "<< #b <<" = "<<b<<"\n";
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define FOR( i , a , b ) for( int i = a; i <= b; i++ )
#define ROF( i , a , b ) for( int i = a; i >= b; i-- )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Found( S , val ) S.find( val ) != S.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , m;
int cnt[ 2*N ];
int a[ 2*N ];
int sm[ 2*N ] , bg[ 2*N ];
int pos;
LL ans;

int main( int argc, char const *argv[] ) {
        fast_io;
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i] , cnt[ a[i] ]++;
                if( a[i] == m ) pos = i;
        }
        for( int i = 1; i <= n; i++ ) {
                if( a[i] < m ) sm[i] = sm[i-1]+1;
                else sm[i] = sm[i-1];
                if( a[i] >= m ) bg[i] = bg[i-1]+1;
                else bg[i] = bg[i-1];
        }
        for( int i = 1; i <= pos; i++ ) {
                int lsm = sm[pos] - sm[i-1];
                int lbg = bg[pos] - bg[i-1];
                if( lsm == lbg || lsm+1 == lbg ) ans++;
                int lo = pos+1 , hi = n;
                cout << lsm << " " << lbg << endl;
        }
        return 0;
}






