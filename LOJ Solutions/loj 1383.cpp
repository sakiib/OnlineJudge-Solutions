#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;
const int inf = 1e9;

int n;
LL k , s , d;
pair <LL,LL> x[ N ];

int main( ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%lld %d %lld %lld",&k,&n,&s,&d);
                for( int i = 1; i <= n; i++ ) {
                        scanf("%lld %lld",&x[i].first,&x[i].second);
                }
                LL lo = -inf , hi = inf , ans = -inf;
                while( lo <= hi ) {

                }
        }
        return 0;
}








