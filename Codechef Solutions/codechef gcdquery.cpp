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

LL ara[ N ];

vector < LL > sum[ N ];

void go( LL num , int id ) {
    LL sq = sqrt( num );
    for( LL i = 1; i <= sq; i++ ) {
        if( num%i == 0 ) {
            sum[id].push_back( i );
            if( num/i != i ) sum[id].push_back( num/i );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        go( ara[i] , i );
    }
    for( int i = 1; i <= n; i++ ) {
        for( int j = 0; j < sum[i].size(); j++ ) {
            M[i][ sum[i][j] ]++;
            M[i][ sum[i][j] ] += M[i-1][sum[i][j]];
        }
    }
    while( q-- ) {
        int l , r;
        scanf("%d %d",&l,&r);
        cout << M[l]
    }
    return 0;
}

