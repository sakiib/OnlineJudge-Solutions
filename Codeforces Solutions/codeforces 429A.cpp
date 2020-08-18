#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector < int > graph[ N ];
int in[ N ], fin[ N ];

int main( int argc , char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ ) {
        int u, v;
        scanf("%d%d",&u,&v);
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d",&in[i]);
    }
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d",&fin[i]);
    }
    return 0;
}
