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
int ara[ 105 ][ 105 ];
int temp[ 105 ];

int Max_Sum_SubArray( ) {
    int ret = -inf;
    int sum = 0;
    for( int i = 1; i <= n; i++ ) {
        if( sum < 0 ) sum = 0;
        else sum += temp[i];
        ret = max( ret , sum );
    }
    return ret;
}
int Max_Sum_SubMatrix( ) {
    int mx = -inf;
    for( int i = 1; i <= n; i++ ){
        memset( temp , 0 , sizeof(temp) );
        for( int j = i ; j <= n; j++ ) {
            for( int k = 1; k <= n; k++ ) {
                temp[k] += ara[k][j];
            }
            mx = max( mx , Max_Sum_SubArray( ) );
        }
    }
    return mx;
}
int main( int argc, char const *argv[] ) {
    while( scanf("%d",&n) != EOF ){
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                scanf("%d",&ara[i][j]);
            }
        }
        int ans = Max_Sum_SubMatrix( );
        printf("%d\n",ans);
    }
    return 0;
}

