#include <bits/stdc++.h>

using namespace std;

string a , b;
int la , lb;

int dp[ 1005 ][ 1005 ];

int solve( int i , int j ) {
    if( i >= la || j >= lb ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];
    int ans = 0;
    if( a[i] == b[j] ) ans = 1+solve( i+1 , j+1 );
    else {
        int op1 = 0 , op2 = 0;
        op1 = solve( i+1 , j );
        op2 = solve( i , j+1 );
        ans = max( op1 , op2 );
    }
    return dp[i][j] = ans;
}
int main( int argc, char const *argv[] ) {
    while( true ) {
        cin >> a;
        if( a == "#" ) break;
        cin >> b;
        la = a.size();
        lb = b.size();
        memset( dp , -1 , sizeof(dp) );
        int ans = solve( 0 , 0 );
        cout << (la-ans)*15+(lb-ans)*30 << endl;
    }
    return 0;
}




