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

int r , c , k;
string str[ 505 ];
bool visited[ 505 ][ 505 ];
int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , -1 , 1 };
int tot , cnt = 0 ;

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >= 0 && nx < r && ny < c && str[nx][ny] == '.');
}
void dfs( int x , int y ) {
    visited[x][y] = true;
    cnt++;
    str[x][y] = 'X';
    //cout <<"Cnt :   x , y"<< cnt <<" "<<x<<" "<<y<<endl;
    if( cnt == tot ) return;
    for( int i = 0; i < 4; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( valid( nx , ny ) && !visited[nx][ny] ) {
            if( cnt == tot ) return;
            dfs( nx , ny );
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> r >> c >> k;
    for( int i = 0; i < r; i++ ) {
        cin >> str[i];
    }
    bool f = false;
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            if( str[i][j] == '.' ) tot++;
        }
    }
    tot -= k;
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            if( !visited[i][j] && str[i][j] == '.' ) {
                dfs( i , j );
                f = true;
                break;
            }
        }
        if( f ) break;
    }
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            if( str[i][j] == '#' ) cout << '#';
            else if( str[i][j] == '.' ) cout <<'X';
            else cout <<'.';
        }
        cout << endl;
    }
    return 0;
}

