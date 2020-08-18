#include <bits/stdc++.h>
using namespace std;

const int block = 350;
const int N = 1e5 + 5;

int l = 1 , r = 0;
int n , q;
int a[ 5*N ];
int cnt[ 5*N ] , BLOCK[ 1005 ] , res[ 5*N ];
int ans[ 5*N ];

int have;

struct data {
        int l , r , idx;
        data(){}
        data( int l , int r , int idx ):l(l), r(r), idx(idx){}
        bool operator <( const data &q ) const {
                int block_a = l / block;
                int block_b = q.l / block;
                if( block_a == block_b ) return ( r < q.r );
                return ( block_a < block_b );
        }
} Q[ 5*N ];


int Block_ID( int id ) {
        int pos = ( (id+block-1)/block );
        return pos;
}
void SetBlock( int id , int val ) {
        int pos = Block_ID( id );
        BLOCK[pos] += val;
}
void Add( int id ) {
        int val = a[id];
        cnt[val]++;
        if( cnt[val] == 1 ) {
                have++; // go a new answer ( occur once only )
                SetBlock( val , +1 ); // this block contains answer.
                res[val]++; // answer is the val.
        }
        if( cnt[val] == 2 ) {
                // this one needs to be removed
                // was included before but not anymore.
                have--;
                SetBlock( val , -1 );
                res[val]--;
        }
}
void Remove( int id ) {
        int val = a[id];
        cnt[val]--;
        if( cnt[val] == 1 ) {
                // need to add this
                // was not included before.
                res[val]++;
                SetBlock( val , +1 );
                have++;
        }
        if( cnt[val] == 0 ) {
                // was included in ans before , not anymore.
                res[val]--;
                SetBlock( val , -1 );
                have--;
        }
}
int solve( ) {
        if( have == 0 ) return 0;
        for( int i = 1; i <= block; i++ ) {
                if( BLOCK[i] ) { // any answer will do , so we'll get it here.
                        int st = (i-1)*block+1;
                        int en = st+block-1;
                        for( int j = st; j <= en; j++ ) {
                                if( res[j] ) return j;
                        }
                        //cout << "block "<< i << " " << (i-1)*(block)+1 << endl;
                }
        }
        return 0;
}
void MO( ) {
        sort( Q+1 , Q+q+1 );
        for( int i = 1; i <= q; i++ ) {
                while( l < Q[i].l ) Remove( l++ );
                while( l > Q[i].l ) Add( --l );
                while( r < Q[i].r ) Add( ++r );
                while( r > Q[i].r ) Remove( r-- );
                ans[ Q[i].idx ] = solve( );
        }
}
int main( int argc , char const *argv[] ) {

        //for( int i = 1; i <= 8; i++ ) cout  << i << " "<< Block_ID( i ) << endl;

        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                scanf("%d %d",&Q[i].l,&Q[i].r);
                Q[i].idx = i;
        }
        MO( );
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}






