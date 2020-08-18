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

int dx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int dy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int fx[] = {+1 , -1 , 0 , 0};
int fy[] = {0 , 0 , +1 , -1};

int sx , sy , ex , ey;
int distk[ 10 ][ 10 ] , distr[ 10 ][ 10 ] , distb[ 10 ][ 10 ];

bool valid( int nx , int ny ) {
    return ( nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8 );
}
void bfs_king( ) {
    memset( distk , -1 , sizeof(distk) );
    queue <ii> Q;
    Q.push( {sx,sy} );
    distk[sx][sy] = 0;
    while( !Q.empty() ) {
        ii f = Q.front();
        int x = f.first;
        int y = f.second;
        Q.pop();
        for( int i = 0; i < 8; i++ ) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if( !valid( nx , ny ) ) continue;
            if( distk[nx][ny] == -1 || ( distk[nx][ny] > distk[x][y]+1) ) {
                distk[nx][ny] = distk[x][y]+1;
                Q.push( {nx,ny} );
            }
        }
    }

}
void bfs_rook( ) {
    memset( distr , -1 , sizeof(distr) );
    queue <ii> Q;
    Q.push( {sx,sy} );
    distr[sx][sy] = 0;
    while( !Q.empty() ) {
        ii f = Q.front();
        int x = f.first;
        int y = f.second;
        Q.pop();
        int a = x , b = y;
        while( valid( a , b ) ) {
            a++ , b++;
            if( distr[a][b] == -1 || ( distr[a][b] > distr[x][y]+1) ) {
                distr[a][b] = distr[x][y]+1;
                Q.push( {a,b} );
            }
        }
        int c = x , d = y;
        while( valid( c , d ) ) {
            c-- , d--;
            if( distr[c][d] == -1 || ( distr[c][d] > distr[x][y]+1) ) {
                distr[c][d] = distr[x][y]+1;
                Q.push( {c,d} );
            }
        }
        int u = x , v = y;
        while( valid( u , v ) ) {
            u++ , v--;
            if( distr[u][v] == -1 || ( distr[u][v] > distr[x][y]+1) ) {
                distr[u][v] = distr[x][y]+1;
                Q.push( {u,v} );
            }
        }
        int w = x , z = y;
        while( valid( w , z ) ) {
           w-- , z++;
           if( distr[w][z] == -1 || ( distr[w][z] > distr[x][y]+1) ) {
                distr[w][z] = distr[x][y]+1;
                Q.push( {w,z} );
           }
        }
    }
}
void bfs_bishop( ) {
    memset( distb , -1 , sizeof(distb) );
    queue <ii> Q;
    Q.push( {sx,sy} );
    distb[sx][sy] = 0;
    while( !Q.empty() ) {
        ii f = Q.front();
        int x = f.first;
        int y = f.second;
        Q.pop();
        int a = x , b = y;
        while( valid( a , b ) ) {
            a++;
            if( distb[a][b] == -1 || ( distb[a][b] > distb[x][y]+1) ) {
                distb[a][b] = distb[x][y]+1;
                Q.push( {a,b} );
            }
        }
        int c = x , d = y;
        while( valid( c , d ) ) {
            d++;
            if( distb[c][d] == -1 || ( distb[c][d] > distb[x][y]+1) ) {
                distb[c][d] = distb[x][y]+1;
                Q.push( {c,d} );
            }
        }
        int u = x , v = y;
        while( valid( u , v ) ) {
            u--;
            if( distb[u][v] == -1 || ( distb[u][v] > distb[x][y]+1) ) {
                distb[u][v] = distb[x][y]+1;
                Q.push( {u,v} );
            }
        }
        int w = x , z = y;
        while( valid( w , z ) ) {
            z--;
            if( distb[w][z] == -1 || ( distb[w][z] > distb[x][y]+1) ) {
                distb[w][z] = distb[x][y]+1;
                Q.push( {w,z} );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> sx >> sy >> ex >> ey;
    bfs_king( );
    bfs_rook( );
    bfs_bishop( );
    cout <<max( 0 , distb[ex][ey] ) <<" "<< max( 0 , distr[ex][ey] )<<" "<< max( 0 , distk[ex][ey]) <<endl;
    return 0;
}

