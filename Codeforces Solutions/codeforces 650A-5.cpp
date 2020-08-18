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

LL A[ 2*N ] , B[ 2*N ];
map <LL,LL> X , Y;
map <pair<LL,LL>,LL> P;

LL SQ( LL x ) {
    return x*x;
}
LL Dist1( LL x1 , LL y1 , LL x2 , LL y2 ) {
    return SQ(x1-x2)+SQ(y1-y2);
}
LL Dist2( LL x1 , LL y1 , LL x2 , LL y2 ) {
    return abs( x1-x2 )+abs( y1-y2 );
}
int main( int argc, char const *argv[] ) {
    LL n;
    scanf("%lld",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld%lld",&A[i],&B[i]);
        X[ A[i] ] ++ , Y[ B[i] ]++;
        P[ {A[i],B[i]} ] ++;
        //X[ A[i] ] = true , Y[ B[i] ] = true;
    }
    /*
    for( int i = 1; i <= n; i++ ) {
        for( int j = i+1; j <= n; j++ ) {
            LL d = Dist1( A[i] , B[i] , A[j] , B[j] );
            LL c = Dist2( A[i] , B[i] , A[j] , B[j] );
            if( SQ(c) == d ) {
                cout << A[i] << " " << B[i] <<" "<<A[j] <<" "<<B[j] <<endl;
            }
        }
        cout << endl;
    }
    */
    LL ans = 0;
    for( auto x : X ) ans += (x.second*(x.second-1)/2);
    for( auto x : Y ) ans += (x.second*(x.second-1)/2);
    for( auto x : P ) ans -= (x.second*(x.second-1)/2);
    printf("%lld\n",ans);
    return 0;
}

