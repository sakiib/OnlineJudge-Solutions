#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[] = { -1 , +0 , +1 , +0 , +1 , +1 , -1 , -1 };
const int dy[] = { +0 , -1 , +0 , +1 , +1 , -1 , +1 , -1 };

string str[ 105 ];
int n , m;

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >= 0 && nx < n && ny < m );
}
bool checkEmpty( int x , int y ) {
    int b = 0;
    for( int i = 0; i < 8; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( !valid( nx , ny ) ) continue;
        if( str[nx][ny] == '*' ) return false;
    }
    return true;
}
bool checkBomb( int x , int y ) {
    int need = str[x][y]-'0';
    int cnt = 0;
    for( int i = 0; i < 8; i++ ) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( !valid( nx , ny ) ) continue;
        if( str[nx][ny] == '*' ) cnt++;
    }
    return ( need == cnt );
}
void solve( ) {
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            if( str[i][j] == '.' ) {
                if( !checkEmpty( i , j ) ) {
                    cout << "NO" << endl;
                    exit(0);
                }
                continue;
            }
            if( str[i][j] == '*' ) continue;
            else {
                if( !checkBomb( i , j ) ) {
                    cout << "NO" << endl;
                    exit(0);
                }
            }
        }
    }
    cout << "YES" << endl;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m;
    for( int i = 0; i < n; i++ ) cin >> str[i];
    solve( );
    return 0;
}






