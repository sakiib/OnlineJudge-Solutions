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

int ara[ 15 ][ 15 ];

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        ara[1][i] = 1;
    }
    int mx = 1;
    for( int i = 2; i <= n; i++ ) {
        for( int j = 1;j <= n; j++ ) {
            ara[i][j] = ara[i-1][j]+ara[i][j-1];
            mx = max( mx , ara[i][j] );
        }
    }
    cout << mx << endl;
    return 0;
}

