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

int BIT[ 20 ][ 105 ][ 105 ];
int n , q , c;

void Update( int time , int idx , int idy , int val ) {
    int y = idy;
    for( ; idx <= 105 ; idx += ( idx & -idx ) ) {
        idy = y;
        for( ; idy <= 105 ; idy += ( idy & -idy ) ) {
            BIT[ time ][ idx ][ idy ] += val;
        }
    }
}
int Query( int time , int idx , int idy ) {
    int y = idy;
    int sum = 0;
    for( ; idx > 0 ; idx -= ( idx & -idx ) ) {
        idy = y;
        for( ; idy > 0 ; idy -= ( idy & -idy ) ) {
            sum += BIT[ time ][ idx ][ idy ];
        }
    }
    return sum;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> q >> c;
    ++c;
    for( int i = 1; i <= n; i++ ) {
        int x , y , s;
        cin >> x >> y >> s;
        for( int i = 0; i < c; i++ ) {
            Update( i , x , y , s );
            s++;
            if( s >= c ) s = 0;
        }
    }
    while( q-- ) {
        int t , x1 , y1 , x2 , y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= c;
        int ans  = Query( t , x2 , y2 );
            ans -= Query( t , x2 , y1-1 );
            ans -= Query( t , x1-1 , y2 );
            ans += Query( t  , x1-1 , y1-1 );
        cout << ans << endl;
    }
    return 0;
}

