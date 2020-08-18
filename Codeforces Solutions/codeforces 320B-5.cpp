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

int l[ N ] , r[ N ];
bool visited[ N ];
int n , idx ;

void dfs( int start ) {
    if( visited[start] ) return;
    visited[ start ] = true;
    for( int i = 1; i <= idx; i++ ) {
        if( l[start] > l[i] && l[start] < r[i] ) dfs( i );
        if( r[start] > l[i] && r[start] < r[i] ) dfs( i );
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        int op , f , t;
        cin >> op >> f >> t;
        if( op == 1 ) {
            idx++;
            l[idx] = f , r[idx] = t;
            continue;
        }
        memset( visited , false , sizeof(visited) );
        dfs( f );
        if( visited[t] ) puts("YES");
        else puts("NO");
    }
    return 0;
}

