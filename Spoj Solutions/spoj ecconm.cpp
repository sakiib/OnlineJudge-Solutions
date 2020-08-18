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

const int mx = 30;

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
       int n;
       scanf("%d",&n);
       if( n&1 ) { printf("%d\n",n); continue; }
       int highest_bit = 0;
       for( int i = 0; i <= mx; i++ ) {
         if( n&( 1<<i ) ) highest_bit = i;
       }
       int ans = 0;
       for( int i = highest_bit , j = 0; i >= 0; i--, j++ ) {
         if( n&(1<<i) ) ans += ( 1<<j );
       }
       printf("%d\n",ans);
    }
    return 0;
}

