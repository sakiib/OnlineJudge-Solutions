#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int ara[ 2*N ];
int cnt[ 2*N ];
int n;
vector < int > need;

int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i] , cnt[ ara[i] ]++;
    for( int i = 1; i <= n; i++ ) {
        if( cnt[ i ] == 0 ) need.push_back( i );
    }
    int id = 0;
    int change = 0;
    for( int i = 1; i <= n; i++ ) {
        if( cnt[ara[i]] == 1 ) continue;

    }
    return 0;
}






