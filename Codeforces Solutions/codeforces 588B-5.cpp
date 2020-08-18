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

map <LL,LL> M;
vector<bool> isprime( 1000100 , true);
vector<LL> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(LL i=4;i<=1000100;i+=2) {
        isprime[i]=false;
    }
    LL sq=sqrt(1000100);
    for(LL i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(LL j=i*i;j<=1000100;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(LL i=3;i<=1000100;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
void primafact( LL n ) {
    LL sq = sqrt( n );
    for( int i = 0 ; i < prime.size() && prime[i] <= sq; i++ ) {
        if( n%prime[i] == 0 ) {
            M[ prime[i] ]++;
            n /= prime[i];
            while( n%prime[i] == 0 ) {
                M[ prime[i] ]++;
                n /=prime[i];
            }
            sq = sqrt( n );
        }
    }
    if( n > 1 ) M[ n ]++;
}
int main( int argc, char const *argv[] ) {
    sieve();
    LL n;
    scanf("%lld",&n);
    primafact( n );
    LL ans = 1;
    for( auto x : M ) {
        ans *= x.first;
    }
    printf("%lld\n",ans);
    return 0;
}

