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

const int k = 30;
int n;
int ara[ N ];
int Table[ N ][ k ];
int lg[ N ];

void Build_Table( ) {
    for( int i = 1; i <= N; i++ ) Table[i][0] = ara[i];
    for( int i = 2; i <= N; i++ ) lg[i] = lg[i/2] + 1;
    for( int j = 1; j <= 20; j++ ) {
        for( int i = 1; i+( 1 << j )-1 <= N; i++ ) {
            Table[i][j] = min( Table[i][j-1] , Table[i+( 1 << (j-1))][j-1] );
        }
    }
}
int Query( int l , int r ) {
    if( l > r ) swap( l , r );
    int k = lg[r-l+1];
    return min( Table[l][k] , Table[r-( 1 << k )+1][k] );
}
int main( int argc, char const *argv[] ) {

    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];

    Build_Table( );

    int q;
    cin >> q;
    while( q-- ) {
        int l , r;
        cin >> l >> r;
        cout << Query( l+1 , r+1 ) << endl;
    }
    return 0;
}

