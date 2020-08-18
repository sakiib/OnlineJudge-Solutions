#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int dx[] = { 1 , -1 , 0 , 0 };
const int dy[] = { 0 , 0 , 1 , -1 };

vector < pair<int,int> > V;
map < pair<int,int> , int > M;
vector <int> graph[ 5005 ];

string s[ N ];
int r , c , id;

vector < pair<int,int> > bridge;
set <int> point;
int Time;
int st[ 5005 ] , low[ 5005 ] , par[ 5005 ];
bool visited[ 5005 ] , br[ 5005 ];

void Tarjan( int s , int p = -1 ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        int child = 0;
        par[s] = p;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                if( visited[x] ) low[s] = min( low[s] , st[x] );
                else {
                        Tarjan( x , s );
                        low[s] = min( low[s] , low[x] );
                        if( low[x] >= st[s] && p != -1 ) point.insert( s );
                        if( low[x] > st[s] ) {
                                bridge.push_back( {s,x} );
                                br[x] = true , br[s] = true;
                        }
                        child++;
                }
        }
        if( p == -1 && child > 1 ) point.insert( s );
}
bool valid( int nx , int ny ) {
        return ( nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] == '#' );
}
void build_graph( int x , int y ) {
        for( int i = 0; i < 4; i++ ) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if( valid( nx , ny) ) graph[ M[ {x,y} ] ].push_back( M[ {nx,ny} ] );
        }
}
int main( int argc , char const *argv[] ) {
        cin >> r >> c;
        for( int i = 0; i < r; i++ ) cin >> s[i];
        for( int i = 0; i < r; i++ ) {
                for( int j = 0; j < c; j++ ) {
                        if( s[i][j] == '#' ) M[ {i,j} ] = ++id;
                }
        }
        if( id <= 2 ) return printf("-1\n"),0;
        for( int i = 0; i < r; i++ ) {
                for( int j = 0; j < c; j++ ) {
                        if( s[i][j] == '#' ) build_graph( i , j );
                }
        }
        Tarjan( 1 );
        if( point.size() >= 1 ) printf("1\n");
        else printf("2\n");
        return 0;
}






