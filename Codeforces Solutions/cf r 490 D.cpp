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
LL a[ 2*N ];
pair < LL , int > rem[ 2*N ];
LL add[ 2*N ];
LL tot;
vector < pair <LL,int> > V;
vector < pair<LL,int> > x[ 2*N ];

bool cmp( pair <LL,int> x , pair <LL,int> y ) {
    return ( x.first < y.first );
}
int main( int argc, char const *argv[] ) {
        fast_io;
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , rem[i].first = a[i]%m , rem[i].second = i;
        LL need = n/m;
        for( int i = 1; i <= n; i++ ) {
            if( x[ rem[i].first ].size() >= need ) V.pb( rem[i] );
            else x[ rem[i].first ].push_back( rem[i] );
        }
        //cout << sz(x[0]) << " " << sz(x[1]) <<" "<< sz(x[2]) <<" "<<sz(x[3]) << endl;
        sort( all(V) , cmp );
        int pos = 0;
        for( LL i = 0; i <= m-1; i++ ) {
            if( x[ i ].size() == need ) continue;
            //cout << "here : "<<i << endl;
            LL req = need - x[i].size();
            for( int j = pos; j < V.size(); j++ ) {
                if( req <= 0 ) {
                    pos = j;
                    break;
                }
                add[ V[j].second ] += abs( i-V[j].first );
                tot += abs( i-V[j].first );
                req--;
            }
        }
        cout << tot << endl;
        for( int i = 1; i <= n; i++ ) cout << a[i]+add[i] << " ";
        return 0;
}



