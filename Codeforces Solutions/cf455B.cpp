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

int r = 0 , b = 0 , g = 0;
bool dp[ 205 ][ 205 ][ 205 ];

set <char> ans;

void solve( int r , int b , int g ) {
    if( dp[r][b][g] ) return;
    if( r+b+g == 1 ) {
        //cout << r << " " << b << " " << g <<endl;
        if( r >= 1 ) ans.insert( 'R' );
        if( b >= 1 ) ans.insert( 'B' );
        if( g >= 1 ) ans.insert( 'G' );
        return;
    }
    if( r > 0 && b > 0 ) solve( r-1 , b-1 , g+1 );
    if( r > 0 && g > 0 ) solve( r-1 , b+1 , g-1 );
    if( b > 0 && g > 0 ) solve( r+1 , b-1 , g-1 );
    if( r > 1 ) solve( r-1 , b , g );
    if( b > 1 ) solve( r , b-1 , g );
    if( g > 1 ) solve( r , b , g-1 );
    dp[r][b][g] = true;
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    for( int i = 0; i < str.size(); i++ ) {
        if( str[i] == 'R' ) r++;
        if( str[i] == 'B' ) b++;
        if( str[i] == 'G' ) g++;
    }
    solve( r , b , g );
    for( auto x : ans ) cout << x;
    return 0;
}

