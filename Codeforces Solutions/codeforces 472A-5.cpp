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

map < string,int > M;

int cost[ 10 ][ 10 ];

void calc( ) {
    M[ "Dhaka" ] = 1 , M[ "Chittagong" ] = 2;
    M[ "Rajshahi" ] = 3 , M[ " Kathmandu" ] = 4;
    M[ "Butwal" ] = 5;

    cost[1][2] = cost[2][1] = 200;
    cost[1][3] = cost[3][1] = 300;
    cost[2][4] = cost[4][2] = 3000;
    cost[2][5] = cost[5][2] = 8000;

    for( int k = 1; k <= 5; k++ ) {
        for( int i = 1; i <= 5; i++ ) {
            for( int j = 1; j <= 5; j++ ) {
                cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j] );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    calc( );
    int t;
    scanf("%d",&t);
    while( t-- ) {
        string a , b;
        cin >> a >> b;
        printf("%d\n",cost[ M[a] ][ M[b] ] );
    }
    return 0;
}

