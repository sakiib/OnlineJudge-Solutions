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

char a[20] , b[20];
vector <int> graph[ N ];
int indegree[ N ];
map <string,int> M;

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n;
        scanf("%d",&n);
        int id = 0;
        for( int i = 1; i <= n; i++ ) {
            scanf("%s%s",a,b);
            if( M[a] == 0 ) M[a] = ++id;
            if( M[b] == 0 ) M[b] = ++id;
            graph[ M[a] ].push_back( M[b] );
            indegree[ M[b] ]++;
        }
        priority_queue<int,vector<int>,greater<int> > Q;
        for( int i = 1; i <= id; i++ ) {
            if( indegree[i] == 0 ) Q.push( i );
        }

        int ans = 0;

        while( !Q.empty() ) {
            int f = Q.top();
            if( indegree[f] == 0 ) ans++;
            Q.pop();
            for( int i = 0; i < graph[ f ].size(); i++ ) {
                int next = graph[ f ][ i ];
                indegree[ next ]--;
                if( indegree[ next ] == 0 ) Q.push( next );
            }
        }
        if( ans == id ) printf("Case %d: Yes\n",tc);
        else printf("Case %d: No\n",tc);

        memset( indegree , 0 , sizeof( indegree ) );
        for( int i = 1; i < N; i++ ) graph[i].clear();
        M.clear();
    }
    return 0;
}

