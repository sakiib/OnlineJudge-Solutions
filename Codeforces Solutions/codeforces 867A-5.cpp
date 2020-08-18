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

int r = 1 , o = 2 , e = 3;
int cur = r;

int cost[ 5 ][ 5 ] = {0};

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    cin >> cost[r][o] >> cost[r][e] >> cost[o][e];
    cost[o][r] = cost[r][o] , cost[e][r] = cost[r][e] , cost[e][o] = cost[o][e];
    int ans = 0;
    --n;
    while( n-- ) {
        if( cur == r ) {
            ans += min( cost[r][e] , cost[r][o] );
            ( cost[r][e] < cost[r][o] ? cur = e : cur = o );
        }
        else if( cur == e ) {
            ans += min( cost[e][o] , cost[e][r] );
            ( cost[e][o] < cost[e][r] ? cur = o : cur = r );
        }
        else {
            ans += min( cost[o][r] , cost[o][e] );
            ( cost[o][r] < cost[o][e] ? cur = r : cur = e );
        }
    }
    cout << ans << endl;
    return 0;
}

