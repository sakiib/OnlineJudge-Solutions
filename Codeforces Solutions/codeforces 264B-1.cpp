#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

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

int n , a[ N ];
vector <int> V[ N ];
int mx[ N ] , cnt[ N ];
int ans = 1;

int main( int argc , char const *argv[] ) {
        sieve( );
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= n; i++ ) {
                int num = a[i];
                int sq = sqrt( num );
                for(int j = 0; j < prime.size() && prime[j] <= sq; j++ ) {
                        if( num%prime[j] == 0 ) {
                              V[i].push_back( prime[j] );
                              num /= prime[j];
                              while( num%prime[j] == 0 ) num /= prime[j];
                              sq = sqrt(num);
                        }
                }
                if( num > 1 ) V[i].push_back( num );
        }
        for( auto x : V[n] ) cnt[x]++;
        for( int i = n-1; i >= 1; i-- ) {
                for( auto x : V[i] ) {
                        mx[i] = max( mx[i] , cnt[x] + 1 );
                }
                for( auto x : V[i] ) {
                        cnt[x] = mx[i];
                }
                ans = max( ans , mx[i] ) ;
        }
        printf("%d\n",ans);
        return 0;
}






