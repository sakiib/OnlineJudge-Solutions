#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100005;
const int mod = 100000007;

int val[ N ];
int way[ N ];
int has[ N ];

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , k;
        scanf("%d %d",&n,&k);
        for( int i = 1; i <= n; i++ ) scanf("%d",&val[i]);
        memset( way , 0 , sizeof(way) );
        way[0] = 1;
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= 10000; j++ ) {
                if( val[i] <= j ) way[j] = ( way[j]%mod+way[ j-val[i] ]%mod )%mod;
            }
        }
        printf("Case %d: %d\n",tc,way[k] );
    }
    return 0;
}

