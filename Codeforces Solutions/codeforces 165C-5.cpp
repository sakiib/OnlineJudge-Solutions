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

int k;
string str;
int len;
LL dp[ 10*N ];

LL solve( int idx , LL cur ) {
    if( cur == k ) return 1;
    if( cur > k ) return 0;
    if( idx > len ) return 1;
    if( dp[idx] != -1 ) return dp[idx];
    LL ret = 0;
    for( int i = idx; i < len; i++ ) {
        if( str[i] == '1' ) ret += solve( idx+1 , cur+1 );
        else ret += solve( idx+1 , cur );
    }
    return dp[idx] = ret;
}
int main( int argc, char const *argv[] ) {
    cin >> k;
    cin >> str;
    len = str.size()-1;
    memset( dp , -1 , sizeof(dp) );
    cout << solve( 0 , 0 ) << endl;
    return 0;
}

