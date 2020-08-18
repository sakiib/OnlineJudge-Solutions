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

string str[ 2005 ];
int r , c , k;
int sum[ 2005 ][ 2005 ];

LL nC2( int x ) {
    return x*(x-1)/2;
}
int main( int argc, char const *argv[] ) {
    cin >> r >> c >> k;
    for( int i = 0; i < r; i++ ) {
        cin >> str[i];
    }
    LL ans = 0;
    for( int i = 0; i < r; i++ ) {
        int cntr = 0;
        for( int j = 0; j < c; j++ ) {
            if( str[i][j] == '.' ) {
                cntr++;
            }
            if( cntr >= k ) {
                ans += nC2( cntr );
                cntr = 1;
            }
            else if( str[i][j] == '*' ) {
                if( cntr >= k ) ans += nC2( cntr );
                cntr = 0;
            }
        }
    }
    for( int i = 0; i < c; i++ ) {
        int cntl = 0;
        for( int j = 0; j < r; j++ ) {
            if( str[i][j] == '.' ) {
                cntl++;
            }
            if( cntl >= k ) {
                ans += nC2( cntl );
            }
            else if( str[i][j] == '*' ) {
                if( cntl >= k ) ans += nC2( cntl );
                cntl = 0;
            }
        }
    }
    if( k == 1 ) ans /= 2;
    cout << ans << endl;
    return 0;
}
