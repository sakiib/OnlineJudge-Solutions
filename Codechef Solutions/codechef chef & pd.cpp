#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

struct PRIME_FACTORIZE_POLLARD_RHO {

        typedef unsigned long long uLL;
        typedef long long int LL;
        const long double range = 1e18;

        inline LL MulMod( LL a , LL b , LL c ) {
                LL x = 0 , y = a%c;
                while( b > 0 ) {
                        if( b&1 ) x = ( x + y ) % c; y = ( y << 1 ) % c;
                        b = b >> 1;
                }
                return x;
        }
        inline LL Modulo( LL a , LL b , LL c ) {
                LL x = 1 , y = a % c;
                while( b > 0 ) {
                        if( b&1 ) x = MulMod( x , y , c ); y = MulMod( y , y , c );
                         b = b >> 1;
                }
                return x;
        }
        inline bool Miller( LL p , int iter ) {
                if(p < 2) return false; if(p == 2) return true; if(!(p&1)) return false;
                LL s = p - 1 , a , temp , mod;
                while( !( s&1 ) ) s = s >> 1;
                for( int i = 0; i < iter; i++ ) {
                        a = rand( ) % ( p - 1 ) + 1; temp = s;
                        mod = Modulo( a , temp , p );
                        while( temp != ( p - 1) && mod != 1 && mod != ( p - 1 ) ) {
                                mod = MulMod( mod , mod , p );
                                temp = temp << 1;
                        }
                        if( mod != ( p - 1 ) && !( temp&1 ) ) return false;
                }
                return true;
        }
        inline LL Randerson( ) {
                long double pseudo = ( long double )rand()/( long double )RAND_MAX;
                return ( long long ) ( round (( long double )range * pseudo ) ) + 1;
        }
        inline LL Calc( LL x , LL n , LL c ) { return ( MulMod( x , x , n ) + c )%n; }
        inline LL GCD( LL a , LL b ) { return !b ? a : GCD( b , a%b ); }
        inline LL Pollard_Rho( LL n ) {
                LL d = 1 , i = 1 , k = 1 , x = 2 , y = x , c;
                do { c = Randerson()%n; } while( ( c == 0 ) || ( c + 2 )%n == 0 );
                while( d != n ) {
                        if( i == k ) k *= 2LL , y = x , i = 0;
                        x = Calc( x , n , c );
                        i++;
                        d = GCD( abs( y - x ) , n );
                        if( d != 1 ) return d;
                }
        }
        inline set <LL> GetPrimeFactors( LL n ) {
                set <LL> ret;
                if( n == 1 ) return ret;
                if( Miller( n , 5 ) ) { ret.insert( n ); return ret; }
                LL d = Pollard_Rho( n );
                ret = GetPrimeFactors( d );
                set <LL> temp = GetPrimeFactors( n/d );
                for( auto x : temp ) ret.insert( x );
                return ret;
        }
} rho;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                LL a , b;
                scanf("%lld %lld",&a,&b);
                set <LL> V = rho.GetPrimeFactors( b );
                bool f = true;
                for( auto x : V ) {
                        if( a%x != 0 ) {
                                f = false;
                                break;
                        }
                }
                cout << ( f ? "Yes" : "No" ) << endl;
        }
        return 0;
}







