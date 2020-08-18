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
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define mp          pake_pair
#define CLR(V)      V.clear()
#define SORT(V)     sort( V.begin(), V.end() )
#define REV(V)      sort( V.rbegin(), V.rend() )
#define MEM(a,x)    memset( a, x, sizeof(a) )
#define FOR(i,a,b)  for( int i = a; i <= b; i++ )
#define ROF(i,a,b)  for( int i = b; i >= a; i-- )
#define REP(i,a)    for( int i = 0; i < a; i++ )
#define debug(x)    cerr << "The value is "<< x << endl
#define Unique(a)   sort( all(a)), a.erase( unique( all(a) ), a.end() )
#define UB(a,key)   upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)   lower_bound( a.begin(), a.end(), key )-a.begin()

int n , m;
int val [ 3*N ];
vector <int> graph[ 3*N ];
int visited[ 3*N ];
int dp[ 3*N ][ 30 ];

void FindCycle( int s ) {
    if( visited[s] == 2 ) return;
    if( visited[s] == 1 ) {
        printf("-1\n");
        exit(0);
    }
    visited[s] = 1;
    for( auto x : graph[ s ] ) {
        FindCycle( x );
    }
    visited[ s ] = 2;
}
void DP( int s ) {
    dp[s][val[s]] = 1;
    visited[s] = 1;
    for( auto x : graph[ s ] ) {
        if( !visited[x] ) DP( x );
        FOR( i , 1 , 26 ) {
            dp[s][i] = max( dp[s][i] , dp[x][i]+(i == val[s]) );
        }
    }
}
int main( int argc, char const *argv[] ) {
    scanf("%d %d",&n,&m);
    string str;
    cin >> str;
    FOR( i , 0 , str.size()-1 ) val[i+1] = ( str[i]-'a'+1 );
    FOR( i , 1 , m ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].pb( v );
    }
    FOR( i , 1 , n ) if( !visited[i] ) FindCycle( i );
    MEM( visited , 0 );
    FOR( i , 1 , n ) if( !visited[i] ) DP( i );
    int mx = 0;
    FOR( i , 1 , n ) {
        FOR( j , 1 , 26 ) {
            mx = max( mx , dp[i][j] );
        }
    }
    printf("%d\n",mx);
    return 0;
}


