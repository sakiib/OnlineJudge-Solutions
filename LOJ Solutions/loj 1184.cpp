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

const int sz = 55;

struct data {
    int hight , age , status;
};
data M[ sz ] , W[ sz ];

int man , woman;
int matched[ sz ];
bool visited[ sz ];
vector <int> graph[ sz ];

bool dfs( int start ) {
    visited[ start ] = true;
    for( int i = 0; i < graph[ start ].size(); i++ ) {
        int node = graph[ start ][ i ];
        int next = matched[ node ];
        if( visited[ next ] ) continue;
        if( next == -1 || dfs( next ) ) {
            matched[ node ] = start;
            return true;
        }
    }
    return false;
}
bool can( int i , int j ) {
    if( abs( M[i].hight-W[j].hight) > 12 ) return false;
    if( abs( M[i].age-W[j].age) > 5 ) return false;
    if( M[i].status != W[j].status ) return false;
    return true;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d%d",&man,&woman);
        for( int i = 1; i <= man; i++ ) {
            scanf("%d%d%d",&M[i].hight,&M[i].age,&M[i].status);
        }
        for( int i = 1; i <= woman; i++ ) {
            scanf("%d%d%d",&W[i].hight,&W[i].age,&W[i].status);
        }
        for( int i = 1; i <= man; i++ ) {
            for( int j = 1; j <= woman; j++ ) {
                if( can( i , j ) ) {
                    graph[ i ].push_back( j );
                }
            }
        }
        int match = 0;
        memset( matched , -1 , sizeof(matched) );
        for( int i = 1; i <= man; i++ ) {
            memset( visited , false , sizeof(visited) );
            if( dfs( i ) ) match++;
            cout << matched[i] << endl;
        }

        for( int i = 1; i <= man; i++ ) {
                cout << i << " " << matched[i] << endl;
        }
        printf("Case %d: %d\n",tc,match);
        for( int i = 1; i < sz; i++ ) graph[i].clear();
    }
    return 0;
}

