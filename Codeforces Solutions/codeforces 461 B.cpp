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

int n;
vector <int> graph[ N ];
int col[ N ];

int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 2; i <= n; i++ ) {
                int x;
                scanf("%d",&x);
                ++x;
                graph[x].push_back( i );
                graph[i].push_back( x );
        }
        for( int i = 1; i <= n; i++ ) scanf("%d",&col[i]);
        return 0;
}






