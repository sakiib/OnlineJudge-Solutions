#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct NUMBER_THEORY {
        static const int N = 1e6 + 5;
        vector <int> prime;
        //vector <bool> isprime( N , true );
        bool isprime[ N ];
        void Sieve_Prime( ) {
                memset( isprime , true , sizeof( isprime ) );
                isprime[0] = isprime[1] = false;
                prime.push_back( 2 );
                for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
                int sq = sqrt( N );
                for( int i = 3; i <= sq; i += 2 ) {
                        if( isprime[i] ) {
                                for( int j = i*i; j <= N; j += 2*i ) {
                                        isprime[j] = false;
                                }
                        }
                }
                for( int i = 3; i <= N; i += 2 ) if( isprime[i] ) prime.push_back( i );
        }
        LL mulmod( LL a , LL b , LL c ) {
                LL x = 0 , y = a%c;
                while( b > 0 ) {
                        if( b&1 ) x = ( x + y ) % c; y = ( y << 1 ) % c;
                        b = b >> 1;
                }
                return x;
        }
        LL modulo( LL a , LL b , LL c ) {
                LL x = 1 , y = a % c;
                while( b > 0 ) {
                        if( b&1 ) x = mulmod( x , y , c ); y = mulmod( y , y , c );
                        b = b >> 1;
                }
                return x;
        }
        bool Miller_Rabin( LL p , int iter ) {
                if( p == 2 ) return true;
                if( ( p < 2 ) || ( !( p&1 ) ) ) return false;
                LL s = p - 1 , a , temp , mod;
                while( !( s&1 ) ) s = s >> 1;
                for( int i = 0; i < iter; i++ ) {
                        a = rand( ) % ( p - 1 ) + 1;
                        temp = s;
                        mod = modulo( a , temp , p );
                        while( temp != ( p - 1 ) && mod != 1 && mod != ( p - 1 ) ) {
                                mod = mulmod( mod , mod , p );
                                temp = temp << 1;
                        }
                        if( mod != ( p - 1 ) && !( temp&1 ) ) return false;
                }
                return true;
        }
        void PrimalityTest( ) {
                Sieve_Prime( );
        }
        bool IsPrime( LL n ) {
                if( n <= N ) return isprime[ n ];
                return Miller_Rabin( n , 5 );
        }
} nt;

int main( int argc , char const *argv[] ) {
        nt.PrimalityTest();
        for( int i = 2; i <= 11; i++ ) {
                cout << i << " " << nt.isprime[i] << endl;
        }
        cout << endl;
        for( int i = 0; i < 10; i++ ) cout << nt.prime[i] << endl;
        return 0;
}






