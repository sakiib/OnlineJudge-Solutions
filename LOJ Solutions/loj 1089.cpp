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

int BIT[ 5*N ] , Q[ 5*N ];

void Update( int idx , int val ) {
    for( ; idx <= 5*N ; idx += ( idx & -idx ) ) {
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
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        set <int> S;
        vector <ii> V;
        map <int,int> M;
        int n , q;
        scanf("%d%d",&n,&q);
        for( int i = 1; i <= n; i++ ) {
            int x , y;
            scanf("%d%d",&x,&y);
            V.push_back(make_pair(x,y) );
            S.insert( x );
            S.insert( y );
        }
        for( int i = 1; i <= q; i++ ) {
            scanf("%d",&Q[i]);
            S.insert( Q[i] );
        }
        int id = 0;
        set <int> :: iterator it;
        for( it = S.begin(); it != S.end(); it++ ) {
            int k = *it;
            M[ k ] = ++id;
        }
        for( int i = 0; i < V.size(); i++ ) {
            if( V[i].first > V[i].second ) swap( V[i].first , V[i].second );
            Update( M[V[i].first] , 1 );
            Update( M[V[i].second]+1 , -1 );
        }
        printf("Case %d:\n",tc);
        for( int i = 1; i <= q; i++ ) {
            int val = M[ Q[i] ];
            printf("%d\n",Query( val ) );
        }
        memset( BIT , 0 , sizeof( BIT ) );
        S.clear(); V.clear(); M.clear();
    }
    return 0;
}

