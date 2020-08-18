#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

int block_size;
int n , q , a[ N ] , BLOCK[ 500 ];

vector <int> prime;
vector <bool> isprime( 10*N , true );

void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= 10*N; i +=2 ) isprime[i] = false;
        int sq = sqrt( 10*N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= 10*N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
}
void Calc( ) {
        memset( BLOCK , 0 , sizeof(BLOCK) );
}
int Block_ID( int id ) {
        int pos = ( ( id + block_size - 1 ) / block_size );
        return pos;
}
void SetBlock( int id , int v ) {
        int pos = Block_ID( id );
        BLOCK[pos] += isprime[v];
}
pair <int,int> StartEndofBlock( int id ) {
        int st = ( id - 1 ) * block_size + 1;
        int en = min( n , ( st + block_size - 1 ) );
        return {st,en};
}
void Update( int l , int r , int v ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                for( int i = l; i <= r; i++ ) {
                        if( isprime[ a[i] ] ) BLOCK[ block_a ]--;
                        if( isprime[v] ) BLOCK[ block_a ]++;
                }
                return;
        }
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                if( isprime[ a[i] ] ) BLOCK[ block_a ]--;
                if( isprime[v] ) BLOCK[ block_a ]++;
        }
        for( int i = block_a + 1; i < block_b; i++ ) {
                if( isprime[v] ) BLOCK[i] = block_size;
                else BLOCK[i] = 0;
        }
        int f = block_size * ( block_b - 1 );
        for( int i = f + 1; i <= r; i++ ) {
                if( isprime[ a[i] ] ) BLOCK[ block_b ]--;
                if( isprime[v] ) BLOCK[ block_b ]++;
        }
}
int Query( int l , int r ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        int res = 0;
        if( block_a == block_b ) {
                for( int i = l; i <= r; i++ ) {
                        if( isprime[ a[i] ] ) res++;
                }
                return res;
        }
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                if( isprime[ a[i] ] ) res++;
        }
        for( int i = block_a + 1; i < block_b; i++ ) {
                res += BLOCK[i];
        }
        int f = block_size * ( block_b - 1 );
        for( int i = f + 1; i <= r; i++ ) {
                if( isprime[ a[i] ] ) res++;
        }
        return res;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        sieve( );
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                block_size = sqrt( n );
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                Calc( );
                for( int i = 1; i <= n; i++ ) SetBlock( i , a[i] );
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int op;
                        scanf("%d",&op);
                        if( op == 0 ) {
                               int l , r , v;
                               scanf("%d %d %d",&l,&r,&v);
                               Update( l , r , v );
                        }
                        else {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                printf("%d\n",Query( l , r ) );
                        }
                }
        }
        return 0;
}












