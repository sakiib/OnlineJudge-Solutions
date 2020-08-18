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

vector <int> graph[ N ];
int a[ N ] , indegree[ N ];
bool visited[ N ];

int dfs( int s ) {
    int ret = 1;
    if( visited[ s ] ) return 1;
    visited[ s ] = true;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            ret = dfs( next )+1;
        }
    }
    return ret;
}
LL LCM( LL a , LL b ) {
    return (a*b/__gcd(a , b));
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
        a[i]--;
        graph[ i ].push_back( a[i] );
        indegree[ a[i] ]++;
    }
    LL ans = 1;
    for( int i = 0; i < n; i++ ) {
        if( indegree[ a[i] ] != 1 ) {
            cout << -1 <<endl;
            return 0;
        }
        if( !visited[ i ] ) {
            int cycle = dfs( i );
            if( cycle%2 == 0 ) cycle /= 2;
            ans = LCM( ans , cycle );
        }
    }
    cout << ans << endl;
    return 0;
}

