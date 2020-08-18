/**
 * Created by Sakib on 5/30/2018
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int sz = 3005;

struct TV {
    LL s , c;
} ara[ sz ];

int n;
LL dp[ sz ][ 5 ];

LL go( int id , int taken ) {
    if( taken >= 3 ) return 0;
    if( id > n ) return 0;
    LL ret = INF;
    if( dp[id][taken] != -1 ) return dp[id][taken];
    for( int i = id+1; i <= n; i++ ) {
        if( ara[i].s > ara[id].s ) {
            ret = min( ret , go( i , taken+1 )+ara[i].c );
        }
    }
    return dp[id][taken] = ret;
}
int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i].s;
    for( int i = 1; i <= n; i++ ) cin >> ara[i].c;
    memset( dp , -1 , sizeof(dp) );
    LL ans = INF;
    ans = min( ans , go( 0 , 0 ) );
    if( ans == INF ) ans = -1;
    cout << ans << endl;
    return 0;
}








