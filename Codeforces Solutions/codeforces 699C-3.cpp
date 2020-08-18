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

int n;
int ara[ 105 ];
int dp[ 105 ][ 10 ];

int solve( int idx , int prev ) {
    if( idx > n ) return 0;
    int mx1 = 0 , mx2 = 0 , mx3 = 0 ;
    int cur = ara[idx];
    if( dp[ idx ][ prev ] != -1 ) return dp[ idx ][ prev ];
    if( cur == 0 ) {
        mx1 = solve( idx+1 , 0 );
    }
    if( cur == 1 ) {
        if( prev != 1 ) mx1 = solve( idx+1 , 1 )+1;
        mx2 = solve( idx+1 , 0);
    }
    if( cur == 2 ) {
        if( prev != 2 ) mx1 = solve( idx+1 , 2 )+1;
        mx2 = solve( idx+1 , 0 );
    }
    if( cur == 3 ) {
        if( prev != 2 ) mx1 = solve( idx+1 , 2 )+1;
        if( prev != 1 ) mx2 = solve( idx+1 , 1 )+1;
        mx3 = solve( idx+1 , 0 );
    }
    dp[ idx ][ prev ] = max( mx1 , max( mx2 , mx3 ) );
    return dp[ idx ][ prev ];
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    memset( dp , -1, sizeof( dp ) );
    int mx = solve( 1 , 4 );
    cout << ( n-mx ) << endl;
    return 0;
}

