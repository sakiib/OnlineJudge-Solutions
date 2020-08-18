#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int r , c;
string str[ 100 ];
bool cycle = false;
bool visited[ 100 ][ 100 ];

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >= 0 && nx < r && ny < c );
}
void dfs( int x , int y , int px , int py , char c ) {
    if( visited[ x ][ y ] ) {
        cycle = true;
        return;
    }
    visited[ x ][ y ] = true;

    for( int i = 0; i < 4 ; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( nx == px && ny == py ) continue;
        if( valid( nx, ny) && str[nx][ny] == c ) {
            dfs(nx , ny , x , y , c);
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> r >> c;
    for( int i = 0; i < r; i++ ) {
        cin >> str[i];
    }
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            if( !visited[i][j] ) {
               dfs( i, j, -1, -1, str[i][j] );
               if( cycle ) break;
            }
        }
    }
    cout << ( cycle ? "Yes" : "No" ) << endl;
    return 0;
}
