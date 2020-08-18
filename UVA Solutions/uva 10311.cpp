#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int sz  = 100000005;

vector <int> prime;
vector <bool> isprime( sz , true );

void sieve( ) {
    isprime[0] = isprime[1] = false;
    prime.push_back( 2 );
    for( int i = 4; i <= sz; i +=2 ) isprime[i] = false;
    int sq = sqrt( sz );
    for( int i = 3; i <= sq; i += 2 ) {
        if( isprime[i] ) {
            for( int j = i*i; j <= sz; j += 2*i ) {
                isprime[j] = false;
            }
        }
    }
    for( int i = 3; i <= sz; i += 2 ) {
        if( isprime[i] ) prime.push_back( i );
    }
}
int main( int argc, char const *argv[] ) {
    sieve( );
    int n;
    while( scanf("%d",&n) != EOF ) {
        if( n < 5 ) {
            printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        if( n&1 ) {
            if( isprime[n-2] ) printf("%d is the sum of %d and %d.\n",n,2,n-2);
            else printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        int half = n/2;
        int pos = lower_bound( prime.begin() , prime.end() , half ) - prime.begin();
        bool found = false;
        for( int i = pos; i >= 0; i--  ) {
            int x = prime[i];
            int y = n-prime[i];
            if( x == y ) continue;
            if( isprime[y] ) {
                if( x > y ) swap( x , y );
                printf("%d is the sum of %d and %d.\n",n,x,y);
                found = true;
                break;
            }
        }
        if( !found ) printf("%d is not the sum of two primes!\n",n);
    }
    return 0;
}





