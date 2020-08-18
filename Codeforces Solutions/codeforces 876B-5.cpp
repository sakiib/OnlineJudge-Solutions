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

LL n , m , k;
LL ara[ N ];
vector <LL> V[ N ];

int main( int argc, char const *argv[] ) {
    scanf("%lld %lld %lld",&n,&k,&m);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        V[ ara[i]%m ].push_back( ara[i] );
    }
    for( int i = 0; i < m; i++ ) {
        if( (int)V[i].size() >= k ) {
            puts("Yes");
            for( int j = 0; j < k; j++ ) {
                printf("%lld ",V[i][j] );
            }
            return 0;
        }
    }
    puts("No");
    return 0;
}

