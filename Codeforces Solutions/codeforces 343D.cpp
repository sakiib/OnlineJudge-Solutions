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

vector < int > graph[ 5*N ];
int Start[ 5*N ] , Finish[ 5*N ];
int Time = 0;
int Tree[ 5*N ] , Lazy[ 5*N ];

void dfs( int s , int p ) {
    Start[s] = ++Time;
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( p != next ) dfs( next , s );
    }
    Finish[s] = Time;
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i < n; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( v ) , graph[v].push_back( u );
    }
    dfs( 1 , 0 );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        int op;
        scanf("%d",&op);
        if( op == 1 ) Update( 1 , 1 , n , Start[op] , Finish[op] );

    }
    return 0;
}

