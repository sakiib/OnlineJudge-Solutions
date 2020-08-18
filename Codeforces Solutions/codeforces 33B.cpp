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

int cost[ 100 ][ 100 ];

void process( ) {
    for( int  i = 0; i < 26; i++ ) {
        for( int j = 0; j < 26; j++ ) {
            if( i != j ) cost[i][j] = inf;
            else cost[i][j] = 0;
        }
    }
}
void FloydWarshall( ) {
    for( int k = 0; k < 26; k++ ) {
        for( int i = 0; i < 26; i++ ) {
            for( int j = 0; j < 26; j++ ) {
                cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j] );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    process();
    string a , b;
    cin >> a >> b;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        string x , y;
        int w;
        cin >> x >> y >> w;
        char f = x[0];
        char t = y[0];
        cost[ f-'a' ][ t-'a' ] = min( w , cost[ f-'a' ][ t-'a' ] );
    }
    FloydWarshall();
    if( a.size() != b.size() ) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    string ans = "";
    for( int i = 0; i < a.size(); i++ ) {
        char x = a[i];
        char y = b[i];
        if( x == y ) {
            ans += x;
            continue;
        }
        int mn = inf , idx = 0;
        for( int k = 0; k < 26; k++ ) {
            if( cost[ x-'a' ][k]+cost[ y-'a' ][k] < mn ) {
                mn = cost[ x-'a' ][k]+cost[ y-'a' ][k];
                idx = k;
            }
        }
        if( mn >= inf ) {
            cout << -1 << endl;
            return 0;
        }
        res += mn;
        ans +=( 'a'+idx );
    }
    cout << res << endl;
    cout << ans <<endl;
    return 0;
}

