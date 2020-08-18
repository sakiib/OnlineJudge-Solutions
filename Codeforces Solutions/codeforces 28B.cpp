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

int A[ 105 ] , B[ 105 ];
int parent[ N ];

int Find( int x ) {
    return ( parent[x] == x ? x : parent[x] = Find( parent[x] ) );
}
void Union( int x , int y ) {
    int u = Find( x ) , v = Find( y );
    if( u != v ) parent[ u ] = v;
}
void makeset( int n ) {
    for( int i = 1; i <= n; i++ ) {
        parent[ i ] = i;
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    makeset( n );
    for( int i = 1; i <= n; i++ ) {
        cin >> A[i];
    }
    for( int i = 1; i <= n; i++ ) {
        int x;
        cin >> x;
        if( i+x <= n ) Union( i , i+x );
        if( i-x >= 1 ) Union( i , i-x );
    }
    for( int i = 1; i <= n; i++ ) {
        if( Find( i ) != Find( A[i] ) ) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

