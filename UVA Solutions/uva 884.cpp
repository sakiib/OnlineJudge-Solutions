#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N  = 1000005;
LL ans[ N ];
vector <int> prime;
vector <bool> isprime( N , true );

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
        if( isprime[i] ) prime.push_back( i );
    }
}
LL solve( int n ) {
    int sq = sqrt(n);
    LL ret = 0;
    for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
        if( n%prime[i] == 0 ) {
            while( n%prime[i] == 0 ) {
                ret++;
                n /= prime[i];
            }
            sq = sqrt(n);
        }
    }
    if( n!= 1 ) ret++;
    return ret;
}
void calc( ) {
    for( int i = 2; i <= 1000000; i++ ) {
        ans[i] = solve( i ) + ans[i-1];
    }
}
int main( int argc, char const *argv[] ) {
    sieve( );
    calc();
    int n;
    while( cin >> n ) {
            cout << ans[n] << endl;
    }
    return 0;
}






