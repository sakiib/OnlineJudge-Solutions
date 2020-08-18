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

pair < int , int > P[ N ];
set < ii > S;


int main( int argc, char const *argv[] ) {
    int n;
    while( scanf("%d",&n) ) {
        if( n == 0 ) break;
        for( int i = 1; i <= n; i++ ) {
            scanf("%d %d",&P[i].first,&P[i].second);
        }
        for( int i = 1; i < n; i++ ) {
            for( int j = i+1; j <= n; j++ ) {
               int y = P[j].second-P[i].second;
               int x = P[j].first-P[i].first;
               int g = __gcd( x , y );
               x /= g , y /= g;
               S.insert( make_pair( x , y ) );
            }
        }
        printf("%d\n",(int)(S.size()));
        S.clear( );
    }
    return 0;
}

