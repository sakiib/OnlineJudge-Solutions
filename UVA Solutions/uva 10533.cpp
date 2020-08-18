#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector <int> prime;
vector <bool> isprime( N , true );

int sumDig( int x ) {
        int ret = 0;
        while( x ) ret += x%10 , x /= 10;
        return ret;
}
void sieve( ) {
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
        for( int i = 3; i <= N; i += 2 ) {
                if( isprime[i] && isprime[ sumDig(i) ] ) prime.push_back( i );
        }
}
int main( int argc , char const *argv[] ) {
        sieve( );
        int t;
        scanf("%d",&t);
        while( t-- ) {
                int l , r;
                scanf("%d %d",&l,&r);
                int y = upper_bound( prime.begin() , prime.end() , r ) - prime.begin();
                int x = lower_bound( prime.begin() , prime.end() , l ) - prime.begin();
                printf("%d\n",( y - x ));
        }
        return 0;
}







