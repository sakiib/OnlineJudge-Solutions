#include <bits/stdc++.h>
using namespace std;

const int N = 2*100005;
int bef[ N ], af[ N ];
vector< pair<int,int> > V;

int main( int argc, char const *argv[] ) {
    int n , k;
    scanf("%d%d",&n,&k);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d",&bef[i]);
    }
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d",&af[i]);
    }
    for( int i = 1; i <= n; i++ ) {
        V.push_back( {bef[i]-af[i],i} );
    }
    sort( V.begin(), V.end() );
    int ans = 0;
    for( int i = 0; i < V.size(); i++ ) {
        if( i < k ) ans += bef[ V[i].second ];
        else ans += min( bef[ V[i].second ], af[ V[i].second ] );
    }
    printf("%d\n",ans);
    return 0;
}
