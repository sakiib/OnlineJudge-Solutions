#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

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
vector < pair<int,int> > PrimeFactor( int n ) {
        vector < pair<int,int> > ret;
        int sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                int cnt = 0;
                if( n%prime[i] == 0 ) {
                        while( n%prime[i] == 0 ) {
                                cnt++;
                                n /= prime[i];
                        }
                        if( cnt > 0 ) ret.push_back( {prime[i],cnt} );
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( {n,1} );
        return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <pair <int,int> > pf = PrimeFactor(n);
        int even = 0, odd = 0;
        for (auto x: pf) {
            if (x.second % 2 == 0) even++;
            else odd++;
        }
        if (even > odd) cout << "Psycho Number" << "\n";
        else cout << "Ordinary Number" << "\n";
    }
    return 0;
}
