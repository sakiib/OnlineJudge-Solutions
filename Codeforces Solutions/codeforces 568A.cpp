#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 2e6 + 5;
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
}

int pr[ N ] , pal[ N ];

void calc( ) {
        for( int i = 1; i < N; i++ ) {
                if( isprime[i] ) pr[i]++;
                 pr[i] += pr[i-1];
        }
        for( int i = 1; i < N; i++ ) {
                int temp = i;
                int cur = 0;
                while( temp ) {
                       cur = cur * 10 + temp%10;
                       temp /= 10;
                }
                if( cur == i ) pal[i]++;
                pal[i] += pal[i-1];
        }
}
int main( int argc , char const *argv[] ) {
        sieve( );
        calc( );

        //cout << 3420 * pr[1] << " " << 1307 * pal[1] << endl;

        int x , y;
        scanf("%d %d",&x,&y);
        int g = __gcd( x , y );
        x /= g , y /= g;

        int ans = -1;
        for( int i = 1; i < N; i++ ) {
                if( y * pr[i] <= x * pal[i] ) ans = i;
        }
        if( ans != -1 ) printf("%d\n",ans);
        else printf("Palindromic tree is better than splay tree\n");
        return 0;
}






