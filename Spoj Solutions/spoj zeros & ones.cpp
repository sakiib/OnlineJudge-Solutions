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

vector <LL> V;

void dfs( LL x ) {
    if( x > 100000000000000000 ) return;
    V.push_back( x );
    dfs( x*10+1 );
    dfs( x*10+0 );
}
int main( int argc, char const *argv[] ) {
    dfs( 1 );
    sort( V.begin() , V.end() );
    //for( auto x : V ) cout << x << " ";
    int t;
    scanf("%d",&t);
    while( t-- ) {
        LL n;
        scanf("%lld",&n);
        for( int i = 0; i < V.size(); i++ ) {
            if( V[i]%n == 0 ) {
                printf("%lld\n",V[i]);
                break;
            }
        }
    }
    return 0;
}

