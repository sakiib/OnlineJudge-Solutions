#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);


const int sz = 1000*N;

vector < LL > prime;
vector < bool > isprime( sz , true );
LL cnt[ sz ];

inline void sieve(  ) {
        isprime[0] = isprime[1] = false;
        LL sq = sqrt( sz );
        for( LL i = 4; i <= sz; i += 2 ) isprime[i] = false;
        for( LL i = 3; i <= sq; i += 2 ) {
            if( isprime[i] ) {
                for( LL j = i*i; j <= sz; j += 2*j ) {
                    isprime[j] = false;
                }
            }
        }
        LL a = 1;
        cnt[2] = 1;
        for( LL i = 3; i <= sz; i += 2 ) {
            if( isprime[i] ) a++;
            cnt[i] = a;
        }
}

LL BS( LL x ) {
    LL lo = 0 , hi = prime.size()-1 , ret = 0;
    while( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        if( prime[mid] <= x ) {
            ret = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ( ret+1 );
}
int main( int argc, char const *argv[] ) {
    sieve( );
    LL n;
    while( scanf("%lld",&n) ) {
        if( n == 0 ) break;
        //cout << u << endl;
        double p = cnt[n];
        double d = n/log(n);
        double ans = 100.0*fabs(p-d)/p;
        cout << setprecision(1) << fixed << ans << endl;
    }
    return 0;
}

