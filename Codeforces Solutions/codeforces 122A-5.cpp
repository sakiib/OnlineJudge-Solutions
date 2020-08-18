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

vector <int> V;

void dfs( int x ) {
    if( x > 0 ) V.push_back( x );
    if( x > 1000 ) return;
    dfs( 10*x+4 );
    dfs( 10*x+7 );
}
int main( int argc, char const *argv[] ) {
    dfs( 0 );
    sort( V.begin() , V.end() );
    int n;
    cin >> n;
    for( auto x : V ) {
        if( n%x == 0 ) {
            cout << "YES" <<endl;
            return 0;
        }
    }
    cout << "NO" <<endl;
    return 0;
}

