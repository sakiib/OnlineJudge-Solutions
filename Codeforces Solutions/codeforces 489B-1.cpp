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

int dp[ 105 ];
int n , m;
bool used[ 105 ];
int b[ 105 ] , g[ 105 ];
int ans = 0;

void solve( int idx ) {
    for( int i = 1; i <= m; i++ ) {
        if( !used[i] && abs( b[idx]-g[i] ) <= 1 ) {
            used[i] = true;
            ans ++;
            return ;
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> b[i];
    }
    cin >> m;
    for( int i = 1; i <= m; i++ ){
        cin >> g[i];
    }
    sort( b+1 , b+n+1 );
    sort( g+1 , g+m+1 );
    for( int i = 1; i <= n; i++ ) {
        solve( i );
    }
    cout << ans << endl;
    return 0;
}

