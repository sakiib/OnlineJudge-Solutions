
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

LL n;
pair <LL,LL> p[ N ];
LL dp[ N ];

LL solve( LL cur , LL idx ) {
    LL mx1 = 0 , mx2 = 0 , mx3 = 0;
    if( idx == n ) return 1;
    if( idx > n ) return 0;
    if( dp[idx] != -1 ) return dp[idx];
    if( p[idx].first - p[idx].second > cur ) {
        mx1 = solve( p[idx].first , idx+1 )+1;
    }
    else if( p[idx].first + p[idx].second < p[idx+1].first ) {
        mx2 = solve( p[idx].first+p[idx].second , idx+1 )+1;
    }
    else mx3 = solve( p[idx].first , idx+1 );
    return dp[idx] = max( mx1 , max( mx2 , mx3 ) );
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> p[i].first >> p[i].second;
    }
    memset( dp , -1 , sizeof(dp) );
    cout << solve( p[1].first , 2 )+1 << endl;
    return 0;
}
