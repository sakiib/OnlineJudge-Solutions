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
string str[ 105 ];
bool visited[ 105 ][ 105 ];
int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >=0 && nx < r && ny < c );
}
void dfs( int x , int y , char col ) {
    visited[ x ][ y ] = true;
    str[x][y] = col;
    if( col == 'B' ) col = 'W';
    else col = 'B';
    for( int i = 0; i < 4; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( valid( nx , ny ) && !visited[nx][ny] && str[nx][ny] == '.') {
            dfs( nx , ny , col );
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
            if( !visited[i][j] && str[i][j] == '.' ) {
                dfs( i , j , 'B' );
            }
        }
    }
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            cout << str[i][j];
        }
        cout << endl;
    }
    return 0;
}

