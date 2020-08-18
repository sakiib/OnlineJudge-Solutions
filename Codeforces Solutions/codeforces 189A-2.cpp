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

int n , a , b , c;
int mx = 0;
int dp[ 4005 ];

int solve( int n ) {
    if( n < 0 ) return -inf;
    if( n == 0 ) return 0;
    if( dp[ n ] != -1 ) return dp[ n ];
    int mx1 = 0 , mx2 = 0 , mx3 = 0;
    mx1 = solve( n-a )+1;
    mx2 = solve( n-b )+1;
    mx3 = solve( n-c )+1;
    return dp[ n ] = max( mx1 , max( mx2 , mx3) );
}
int main( int argc, char const *argv[] ) {
    cin >> n >> a >> b >> c;
    memset( dp , -1 , sizeof( dp ) );
    mx = solve( n );
    cout << mx <<endl;
    return 0;
}

