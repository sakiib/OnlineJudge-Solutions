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

int n;
int ara[ 5*N ];

bool carry[ 5*N ] , hide[ 5*N ];

int can( int id , int val ) {
    int lo = id+1 , hi = n , ret = -inf;
    while( lo <= hi ) {
        int mid = (lo+hi)/2;
        if( ara[mid] >= (2*val) && !carry[mid] ) {
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    sort( ara+1 , ara+n+1 );
    for( int i = 1; i <= n/2; i++ ) {
        int idx = can( i , ara[i] );
        if( idx != -inf ) hide[i] = true , carry[idx] = true;
    }
    int ans = n/2;
    if( n&1 ) ans++;
    for( int i = 1; i <= n/2; i++ ) {
        if( !hide[i] ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

