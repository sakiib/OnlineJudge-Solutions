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

int r , c;
string str[ 505 ];
int sx , sy , ex , ey;

int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };
int visited[ 505 ][ 505 ];
bool found;

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >= 0 && nx < r && ny < c );
}
void bfs( int x , int y ) {
    memset( visited , 0 , sizeof(visited) );
    visited[x][y] = 1;
    queue < ii > Q;
    Q.push( {x,y} );
    while( !Q.empty() ) {
        ii f = Q.front(); Q.pop();
        int sx = f.first , sy = f.second;
        for( int i = 0; i < 4; i++ ) {
            int nx = sx+dx[i];
            int ny = sy+dy[i];
            if( nx == ex && ny == ey ) {
                visited[ex][ey] = 1;
                found = true;
                return;
            }
            if( !valid( nx , ny ) ) continue;
            if( str[nx][ny] == 'X' ) continue;
            if( visited[nx][ny] >= 1 ) continue;
            visited[nx][ny] = 1;
            Q.push( {nx,ny} );
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> r >> c;
    for( int i = 0; i < r; i++ ) {
        cin >> str[i];
    }
    cin >> sx >> sy >> ex >> ey;
    sx-- , sy-- , ex-- , ey--;
    if( sx == ex && sy == ey ) {
        for( int i = 0; i < 4; i++ ) {
        int nx = ex+dx[i];
        int ny = ey+dy[i];
        if( !valid( nx , ny ) ) continue;
        if( visited[nx][ny] == 0 && str[nx][ny] != 'X' ) {
            cout << "YES" <<endl;
            return 0;
        }
      }
      cout << "NO" << endl;
      return 0;
    }
    bfs( sx , sy );
    //cout << visited[ex][ey] << endl;
    if( visited[ex][ey] && str[ex][ey] == 'X' ) {
        cout << "YES" << endl;
        return 0;
    }
    for( int i = 0; i < 4; i++ ) {
        int nx = ex+dx[i];
        int ny = ey+dy[i];
        if( !valid( nx , ny ) ) continue;
        if( visited[nx][ny] == 0 && str[nx][ny] != 'X' ) {
            cout << "YES" <<endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

