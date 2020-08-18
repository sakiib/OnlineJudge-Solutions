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

int ara[ 10*N ];

struct data {
    int mx , mn;
} A[ 10*N ];

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        int mxx = 0;
        A[1].mx = ara[1];
        for( int i = 2; i <= n; i++ ) {
            A[i].mx = max( A[i-1].mx , ara[i] );
        }
        A[n].mn = ara[n];
        for( int i = n-1; i >= 1; i-- ) {
            A[i].mn = min( A[i+1].mn , ara[i] );
        }
        int ans = 0;
        for( int i = 2; i < n; i++ ) {
            if( ara[i] >= A[i].mx && ara[i] <= A[i].mn ) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

