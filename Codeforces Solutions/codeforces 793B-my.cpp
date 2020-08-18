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
string str[ 1005 ];
int sx , sy , ex , ey;
int visited[ 1005 ][ 1005 ];

int dx[] = {+1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , +1};

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >= 0 && nx < r && ny < c );
}
void dfs( int x , int  y , int last ) {

    for( int i = 0; i < 4; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( i == last ) {
            if( valid( nx , ny ) && ( visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y]) ) {
                visited[ nx ][ ny] = visited[ x ][ y ];
                dfs( nx , ny , i );
            }
            else {
                if( valid( nx , ny ) && visited[nx][ny] < 2 && ( visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y]+1)) {
                    visited[ nx ][ ny ] = visited[ x ][ y ]+1;
                    dfs( nx , ny , i);
                }
            }
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
            if( str[i][j] == 'S' ) sx = i , sy = j;
            if( str[i][j] == 'T' ) ex = i , ey = j;
        }
    }
    for( int i = 0; i < 4; i++ ) {
        memset( visited , -1, sizeof( visited ) );
        visited[ sx ][ sy ] = 0;
        dfs( sx , sy , i );
        if( visited[ ex ][ ey ] <= 2 && visited[ ex ][ ey ] != -1 ) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" <<endl;
    return 0;
}


