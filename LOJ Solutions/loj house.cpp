#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int N = 100005;
const int inf = 100000000;

int n;
int cost[ 100 ][ 5 ];
int dp[ 100 ][ 5 ];

int solve( int id, int col ) {
    if( id > n ) return 0;

    int op1 = 0 , op2 = 0 , op3 = 0 , op4 = 0;

    if( dp[id][col] != -1 ) return dp[id][col];

    if( col == 0 ) {

        op1 = min( solve( id+1 , 1 )+cost[id][1] , min( solve( id+1 , 2 )+cost[id][2] ,
                   solve( id+1 , 3 )+cost[id][3] ) );
    }
    else if( col == 1 ) {

        op2 = min( solve( id+1 , 2 )+cost[id][2] , solve( id+1 , 3 )+cost[id][3] );
    }
    else if( col == 2 ) {

        op3 = min( solve( id+1 , 1 )+cost[id][1] , solve( id+1 , 3 )+cost[id][3] );
    }
    else if( col == 3 ) {

        op4 = min( solve( id+1 , 1 )+cost[id][1] , solve( id+1 , 2 )+cost[id][2] );
    }
    return dp[id][col] = ( op1+op2+op3+op4 );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        memset( dp , -1 , sizeof(dp) );
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d %d %d",&cost[i][1],&cost[i][2],&cost[i][3]);
        }
        printf("Case %d: %d\n",tc,solve( 1 , 0 ));
    }
    return 0;
}

