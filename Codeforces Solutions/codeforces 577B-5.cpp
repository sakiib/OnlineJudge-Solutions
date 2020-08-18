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

int n , m;
int ara[ 10*N ];
bool f = false;
bool dp[ 1005 ][ 1005 ];

void solve( int idx , int cnt , int sum ) {
    if( cnt >= 1 && sum%m == 0 ) {
        f = true;
        return;
    }
    if( idx > n ) return;
    if( dp[idx][sum] ) return;
    solve( idx+1 , cnt , sum );
    solve( idx+1 , cnt+1 , (sum%m+ara[idx]%m)%m );
    dp[idx][sum] = true;
}
int main( int argc, char const *argv[] ) {
    scanf("%d%d",&n,&m);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    if( n > m ) {
        puts("YES");
        return 0;
    }
    solve( 1 , 0 , 0 );
    if( f ) puts("YES");
    else puts("NO");
    return 0;
}

