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

bool ok( int n ) {
        for( int i = 2; i*i <= n; i++ ) {
                if( n%i == 0 ) return false;
        }
        return true;
}
vector <bool> isprime( N , true );
vector <int> prime;
void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        int sq = sqrt( N );
        for( int i = 4; i <= N; i += 2 ) isprime[i] = false;
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j+= 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
        for( int i = 3; i <= N; i+= 2 ) if( isprime[i] ) prime.push_back( i );
}
void brute( int n ) {
        bool f = false;
        for( int i = 0; i < prime.size() && prime[i] <= n; i++ ) {
                for( int j = 0; j < prime.size() && prime[j] <= n; j++ ) {
                        for( int k = 0; k < prime.size() && prime[k] <= n; k++ ) {
                                if( prime[i]%2 == 0 || prime[j]%2 == 0 || prime[k]%2 == 0 ) continue;
                                if( prime[i]+prime[j]+prime[k] == n ) {
                                        f = true;
                                        cout <<n <<": "<< prime[i] << " " << prime[j] << " " << prime[k] << endl;
                                }
                        }
                }
        }
        getchar();
        if( !f ) cout << "Not Found " << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        sieve();
        for( int i = 99999; i <= 99999; i+= 2 ) brute( i );
        int n;
        cin >> n;
        if( ok(n) ) return cout << 1 << "\n" << n << endl,0;
        return 0;
}






