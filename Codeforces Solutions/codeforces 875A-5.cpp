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
vector <LL> ans;

LL SumofDigit( LL x ) {
    LL ret = 0;
    while( x ) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}
void solve( ) {
    LL lo = max( 0LL , n-100 );
    LL hi = n;
    for( LL i = lo ; i <= n; i++ ) {
        if( i+SumofDigit(i) == n ) {
            ans.push_back( i );
        }
    }
    cout << ans.size() <<endl;
    for( auto x : ans ) cout << x << endl;
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    solve( );
    return 0;
}

