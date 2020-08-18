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

vector < LL > V;
LL ara[ N ] , cnt[ 100 ] = {0};

void dfs( LL x ) {
    if( x%90 == 0 ) V.push_back( x );
    if( x > INF ) return;
    dfs( 10*x+0 );
    dfs( 10*x+5 );
}
int main( int argc, char const *argv[] ) {
    /*dfs( 5 );
    sort( V.begin() , V.end() );
    for( int i = 0; i < V.size(); i++ ) {
        cout <<i <<" "<< V[i] <<endl;
    }*/
    int n , z = 0;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        cnt[ ara[i] ]++;
        if( !ara[i] ) z++;
    }
    LL nine = cnt[5]/9;
    if( nine == 0 && z != 0 ) {
        cout << 0 << endl;
        return 0;
    }
    if( z == 0 ) {
        cout << -1 << endl;
        return 0;
    }
    string s = "555555555";
    while( nine -- ) cout << s;
    while( z-- ) cout << "0";
    return 0;
}

