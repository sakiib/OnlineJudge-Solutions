#include <bits/stdc++.h>

using namespace std;

string str;
int dp[ 1005 ][ 1005 ];
int l;

int solve( int x , int y ) {
    if( x > y || x >= l || y < 0 ) return 0;
    if( x == y ) return 1;
    if( dp[x][y] != -1 ) return dp[x][y];
    int ans = 0;
    if( str[x] == str[y] ) {
        ans = 2+solve( x+1 , y-1 );
    }
    else {
        int op1 = 0 , op2 = 0;
        op1 = solve( x+1 , y );
        op2 = solve( x , y-1 );
        ans = max( op1 , op2 );
    }
    return dp[x][y] = ans;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    cin.ignore( );
    while( t-- ) {
        getline( cin , str );
        memset( dp , -1 , sizeof(dp) );
        l = str.size();
        if( l == 0 ) {
            printf("0\n");
            continue;
        }
        printf("%d\n",solve( 0 , l-1 ) );
    }
    return 0;
}



