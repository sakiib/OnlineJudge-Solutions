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
bool visited[ 1005 ][ 1005 ];

int dx[ ] = { 1 , -1 , 0 , 0 };
int dy[ ] = { 0 , 0 , 1 , -1 };

string s = "DIMA";
bool found;

bool valid( int nx , int ny ) {
    return (nx >= 0 && ny >= 0 && nx < r && ny < c );
}
void dfs( int x , int y , int pos ) {
    if( pos == 4 ) {
        found = true;
        return;
    }
    visited[x][y] = true;
    for( int i = 0; i < 4; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( !visited[nx][ny] && valid( nx , ny ) && str[nx][ny] == s[pos] ) {
            dfs( nx , ny , pos+1 );
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> r >> c;
    for( int i = 0; i < r; i++ ) {
        cin >> str[i];
    }
    int ans = 0;
    for( int i = 0; i < r; i++ ) {
        for( int j = 0;j < c; j++ ) {
            if( !visited[i][j] && str[i][j] == 'D' ) {
                found = false;
                dfs( i , j , 1 );
                if( found ) ans ++;
            }
        }
    }
    if( ans > 0 ) cout << ans <<endl;
    else cout << "Poor Inna!" << endl;
    return 0;
}

