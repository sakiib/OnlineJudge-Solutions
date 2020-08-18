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

struct data {
    int u , v , w;
    bool operator<( const data &q ) const {
        return ( w < q.w );
    }
};

vector <data> V;
int val[ N ] , parent[ N ];
vector <int> ans;
bool has[ N ];
int res = 0;

int Find( int x ) {
    return (parent[ x ] == x ? x : parent[x] = Find( parent[x] ) );
}
void Union( int x , int y ) {
    int u = Find( x ) , v = Find( y );
    if( u != v ) parent[ u ] = v;
}
void MST_Kruskal( ) {
    sort( V.begin() , V.end() );
    for( int i = 0; i < V.size(); i++ ) {
        int x = V[i].u , y = V[i].v , cost = V[i].w;
        if( Find( x ) != Find( y ) && !has[ y ] ) {
            Union( x , y );
            has[ y ] = true;
            res += cost;
            ans.push_back( cost );
        }
    }
}
void makeset( int n ) {
    for( int i = 1; i <= n; i++ ) {
        parent[ i ] = i;
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> val[i];
    }
    int q;
    cin >> q;
    while( q-- ) {
        int  u , v , w;
        cin >> u >> v >> w;
        V.push_back( {u,v,w} );
    }
    makeset( n );
    MST_Kruskal();
    if( ans.size() == n-1 ) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}

