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

const int sz = 105;
vector <int> graph[ sz ];
int done[ sz ][ sz ];
bool visited[ sz ];
int cnt;

void dfs( int s ) {
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( !visited[next] ) {
            visited[next] = true;
            cnt++;
            dfs( next );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    while( scanf("%d",&n) ) {
        if( n == 0 ) break;
        int from;
        while( scanf("%d",&from) ) {
            if( from == 0 ) break;
            int to;
            while( scanf("%d",&to) ) {
                if( to == 0 ) break;
                graph[ from ].push_back( to );
            }
        }
        int q;
        scanf("%d",&q);
        while( q-- ) {
            int node;
            scanf("%d",&node);
            memset( visited , false , sizeof( visited ) );
            cnt = 0;
            dfs( node );
            printf("%d",n-cnt);
            for( int i = 1; i <= n; i++ ) {
                if( !visited[i] ) printf(" %d",i);
            }
            printf("\n");
        }
        for( int i = 1; i < sz; i++ ) {
            graph[i].clear();
        }
    }
    return 0;
}

