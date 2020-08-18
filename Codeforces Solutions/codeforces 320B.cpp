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

int n;
int id = 0;
int a[ 105 ], b[ 105 ];
bool visited[ 105 ];

void dfs( int s ) {
    visited[s] = true;
    for( int i = 1; i <= n; i++ ) {
        if( visited[i] ) continue;
        if( a[s] > a[i] && a[s] < b[i] ) dfs( i );
        else if( b[s] > a[i] && b[s] < b[i] ) dfs( i );
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        int op , l , r;
        cin >> op >> l >> r;
        if( op == 1 ) {
            a[++id] = l , b[++id] = r;
        }
        else {
            memset( visited , false , sizeof( visited ) );
            dfs( l );
            if( visited[r] ) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}

