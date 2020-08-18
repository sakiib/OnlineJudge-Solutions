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

const int level = 20;
int n , a[ N ];
int st[ N ] , en[ N ];
int Time;
int parent[ N ][ level+5 ];
int depth[ N ];
vector <int> graph[ N ];
int val[ N ];

void dfs( int s , int p ) {
        st[s] = ++Time;
        val[Time] = s;
        parent[s][0] = p;
        depth[s] = depth[p] + 1;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int next = graph[s][i];
                if( next == p ) continue;
                dfs( next , s );
        }
        en[s] = Time;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        //++u , ++v;
                        graph[u].push_back( v ) , graph[v].push_back( u );
                }
                memset( parent , -1 , sizeof(parent) );
                depth[0] = 0;
                Time = 0;
                dfs( 1 , 0 );
                cout << "******" << endl;
                for( int i = 1; i <= Time; i++ ) cout << val[i] << " ";
                cout << endl;
                for( int i = 1; i <= n; i++ ) cout << st[i] << " " << en[i] << endl;
        }
        return 0;
}






