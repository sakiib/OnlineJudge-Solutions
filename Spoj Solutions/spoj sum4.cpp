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

const int sz = 3000;

int a[ sz ] , b[ sz ] , c[ sz ] , d[ sz ];
vector <int> V;
unordered_map <int,int> M;
int n;
int ans = 0;

void calc( ) {
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            int sum = c[i]+d[j];
            V.push_back( sum );
        }
    }
    sort( V.begin() , V.end() );
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    calc( );

    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            int res = a[i]+b[j];
            res = -res;
            int u = upper_bound( V.begin() , V.end() , res )-V.begin();
            u--;
            int l = lower_bound( V.begin() , V.end() , res )-V.begin();
            int len = u-l+1;
            ans += len;
        }
    }
    printf("%d\n",ans);
    return 0;
}

