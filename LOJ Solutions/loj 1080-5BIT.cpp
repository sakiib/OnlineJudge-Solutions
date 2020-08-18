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

char str[ N ] , s[ 10 ];
int ara[ N ] , BIT[ N ];

void Update( int idx ,int val ) {
    for( ; idx <= N; idx += ( idx & -idx ) ) {
        BIT[idx] += val;
    }
}
int Query( int idx ) {
    int sum = 0;
    for( ; idx > 0; idx -= ( idx & -idx ) ) {
        sum += BIT[idx];
    }
    return sum;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%s",str);
        printf("Case %d:\n",tc);
        int q;
        scanf("%d",&q);
        while( q-- ) {
            scanf("%s",s);
            if( s[0] == 'I' ) {
                int l , r;
                scanf("%d%d",&l,&r);
                Update( l , +1 );
                Update( r+1 , -1 );
            }
            else {
                int pos;
                scanf("%d",&pos);
                int tot = Query( pos );
                --pos;
                if( tot%2 == 0 ) {
                    printf("%c\n",str[pos]);
                }
                else {
                    if( str[pos] == '1' ) printf("0\n");
                    else printf("1\n");
                }
            }
        }
        memset( BIT , 0 , sizeof( BIT ) );
    }
    return 0;
}


