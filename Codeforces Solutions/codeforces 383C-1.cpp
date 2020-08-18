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

int ara[ 2*N ];
vector < int > graph[ 2*N ];
int Start[ 2*N ], Finish[ 2*N ], Level[ 2*N ];
int Time = 0;
int BIT[ 2*N ];

void dfs( int s , int par ) {
    Start[ s ] = ++Time;
    Level[ s ] = Level[ par ]+1;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next != par ) {
            dfs( next , s );
        }
    }
    Finish[ s ] = Time;
}
void Update( int idx , int val ) {
    for( ; idx <= 2*N ; idx += ( idx & -idx ) ) {
        BIT[ idx ] += val;
    }
}
int Query( int idx ) {
    int sum = 0;
    for( ; idx > 0 ; idx -= ( idx & -idx ) ) {
        sum += BIT[ idx ];
    }
    return sum;
}
int main( int argc, char const *argv[] ) {
    int n, q;
    scanf("%d%d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    for( int i = 1; i<= n-1; i++ ) {
        int u, v;
        scanf("%d%d",&u,&v);
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    dfs( 1 , 0 );
    for( int k = 1; k <= q; k++ ) {
        int op;
        scanf("%d",&op);
        if(op == 1) {
            int node, val;
            scanf("%d%d",&node,&val);
            if( Level[ node ]%2 == 0 ) {
                Update( Start[ node ] , +val );
                Update( Finish[ node ]+1 , -val );
            }
            else {
               Update( Start[ node ] , -val );
               Update( Finish[ node ]+1 , +val );
            }
        }
        else {
            int node;
            scanf("%d",&node);
            int res = Query( Start[ node ] );
            if( Level[ node ]%2 == 0 ) printf("%d\n",ara[ node ]+res);
            else printf("%d\n",ara[ node ]-res);
        }
    }
    return 0;
}
