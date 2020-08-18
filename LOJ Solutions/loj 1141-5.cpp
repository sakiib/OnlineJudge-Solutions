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

int x , y;
vector <int> primefact[ N ];
vector <int> prime;
int cost[ N ];

bool isprime( int x ) {
    for( int i = 2; i*i <= x; i++ ) {
        if( x%i == 0 ) return false;
    }
    return true;
}
void sieve( ) {
    prime.push_back( 2 );
    for( int i = 3; i <= 1000; i +=2 ) {
        if( isprime( i ) ) prime.push_back( i );
    }
}
void process( int x ) {
    int sq = sqrt( x );
    int temp = x;
    for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
        if( x%prime[i] == 0 ) {
            if( prime[i] != temp ) primefact[ temp ].push_back( prime[i] );
            x /= prime[i];
            while( x%prime[i] == 0 ) {
                x /= prime[i];
            }
            sq = sqrt( x );
        }
    }
    if( x > 1 && x != temp ) primefact[ temp ].push_back( x );
}
void calc( ) {
    for( int i = 2; i <= 1000; i++ ) {
        process( i );
    }
}
void bfs( ) {
    memset( cost , -1 , sizeof(cost) );
    cost[ x ] = 0;
    queue <int> Q;
    Q.push( x );
    while( !Q.empty() ) {
        int t = Q.front();
        Q.pop();
        for( int i = 0; i < primefact[t].size(); i++ ) {
            int res = t+primefact[t][i];
            if(( cost[ res ] == -1 || cost[ res ] > cost[t]+1 ) && res <= y ) {
                cost[res] = cost[t]+1;
                Q.push( res );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    sieve( );
    calc( );
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d%d",&x,&y);
        bfs( );
        printf("Case %d: %d\n",tc,cost[y]);
    }
    return 0;
}

