#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

int a[ 20 ];

LL LCM( LL a , LL b ) {
        return a * b / __gcd( a , b );
}
int main( ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL val;
                int n;
                scanf("%lld %d",&val,&n);
                for( int i = 0; i < n; i++ ) scanf("%d",&a[i]);
                LL ans = 0;
                for( int i = 0; i < ( 1 << n ); i++ ) {
                        vector <int> V;
                        for( int j = 0; j < n; j++ ) {
                                if( i&( 1 << j ) ) {
                                        V.push_back( a[j] );
                                }
                        }
                        int sz = __builtin_popcount( i );
                        LL lcm = 1;
                        for( int i = 0; i < V.size(); i++ ) lcm = LCM( lcm , V[i] );
                        if( sz%2 == 0 ) ans += val/lcm;
                        else ans -= val/lcm;
                }
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}
