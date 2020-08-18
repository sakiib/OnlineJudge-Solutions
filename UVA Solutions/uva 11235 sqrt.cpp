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

int block;
int n , q;
int ara[ 2*N ] , cnt[ 2*N ] , First[ 2*N ];
int BLOCK[ N ];

int GetID( int index ) {
    return ( index/block );
}
void SetBlock( int index , int val ) {
    int id = GetID( index );
    BLOCK[id] = max( BLOCK[id] , cnt[val] );
}
int GetAns( int l , int r ) {
    int left = GetID( l );
    int right = GetID( r );
    cout << left << " " << right << endl;
    int mx = 0;
    if( left == right ) {
        for( int i = l; i <= r; i++ ) mx = max( mx , cnt[ ara[i] ]-l+First[ ara[i] ]);
        return mx;
    }
    for( int i = l; i < (left+1)*block; i++ ) mx = max( mx , cnt[ ara[i] ]-l+First[ ara[i] ]);
    for( int i = left+1; i < right; i++ ) mx = max( mx , BLOCK[i] );
    for( int i = right*block; i <= r; i++ ) mx = max( mx , cnt[ ara[i] ]-l+First[ ara[i] ]);
    return mx;
}
int main( int argc, char const *argv[] ) {
    while( scanf("%d",&n) ) {
        if( n == 0 ) break;
        scanf("%d",&q);
        block = sqrt( n );
        for( int i = 0; i < n; i++ ) {
            scanf("%d",&ara[i]);
            ara[i] += 100000;
            cnt[ ara[i] ]++;
            if( cnt[ ara[i] ] == 1 ) {
                First[ ara[i] ] = i;
            }
            SetBlock( i , ara[i] );
        }
        for( int i = 0; i <= block; i++ ) cout << BLOCK[i] << " ";
        while( q-- ) {
            int l , r;
            scanf("%d %d",&l,&r);
            l-- , r--;
            if( l > r ) swap( l , r );
            if( ara[l] == ara[r] ) {
                printf("%d\n",(r-l+1) );
                continue;
            }
            int mx = 0;
            int left_ase = cnt[ ara[l] ]-l+First[ ara[l] ];
            int right_ase = r-First[ ara[r] ]+1;
            mx = max( left_ase , right_ase );
            int from = First[ ara[l] ]+cnt[ ara[l] ];
            int to = First[ ara[r] ]-1;
            if( from <= to ) {
                mx = max( mx , GetAns( from , to ) );
            }
            printf("%d\n",mx);
        }
        memset( cnt , 0 , sizeof(cnt) );
    }
    return 0;
}

