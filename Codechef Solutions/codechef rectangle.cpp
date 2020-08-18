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

int ara[ 10 ];

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d%d%d%d",&ara[0],&ara[1],&ara[2],&ara[3]);
        sort( ara , ara+4 );
        if( ara[0] == ara[1] && ara[2]== ara[3] ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

