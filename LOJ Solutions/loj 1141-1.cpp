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
        int sq = sqrt(N );
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
struct BreadthFirstSearch {
        static const int MAXN = 1e5 + 5;
        typedef long long LL;
        typedef pair <int,int> ii;
        typedef pair <LL,LL> ll;

        vector <int> graph[ MAXN ];
        vector <int> primefact[ MAXN ];
        int st , en;
        int cost[ MAXN ];

        void initialize( int _st , int _en ) {
                st = _st , en = _en;
                for( int i = 0; i < MAXN; i++ ) {
                        graph[i].clear();
                        cost[i] = -1;
                }
        }
        void AddEdge( int u , int v ) {
                graph[u].push_back( v ) , graph[v].push_back( u );
        }
        void BFS( int s ) {
                queue <int> Q;
                cost[ s ] = 0;
                Q.push( s );
                while( !Q.empty() ) {
                        int f = Q.front();
                        Q.pop();
                        for( auto x : primefact[ f ] ) {
                                if( cost[x] == -1 || cost[x] > cost[f] + 1 ) {
                                        cost[f] = cost[x] + 1;
                                        Q.push( x );
                                }
                        }
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
                for( int i = 2; i < MAXN; i++ ) process( i );
        }
        void solve( ) {
                BFS( st );
        }
} bfs;

int main( int argc , char const *argv[] ) {
        sieve( );
        bfs.calc( );

        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int st , en;
                scanf("%d %d",&st,&en);
                bfs.initialize( st , en );

                //for( auto x : bfs.primefact[10] ) cout << x << " "; cout << endl;
                bfs.solve( );
                printf("Case %d: %d\n",tc,bfs.cost[t]);
        }
        return 0;
}






