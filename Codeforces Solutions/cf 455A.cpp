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
char str[ 30 ][ 30 ];
int sx , sy;
int ans;
bool visited[ 30 ][ 30 ];
int dx [] = { 1 , -1 , 0 , 0 };
int dy [] = { 0 , 0 , 1 , -1 };

bool valid( int nx , int ny ) {
    return ( nx >= 0 && ny >= 0 && nx < r && ny < c && !visited[nx][ny] );
}
void dfs( int x , int y ) {
    visited[ x ][ y ] = true;
    ans++;
    for( int i = 0; i < 4; i++ ) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( valid( nx , ny ) && str[nx][ny] != '#' ) {
            dfs( nx , ny );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d%d",&c,&r);
        for( int i = 0; i < r; i++ ) {
            scanf("%s",str[i]);
        }
        bool f = false;
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
                if( str[i][j] == '@' ) {
                   sx = i , sy = j;
                   f = true;
                   break;
                }
            }
            if( f ) break;
        }
        ans = 0;
        dfs( sx , sy );
        printf("Case %d: %d\n",tc,ans);
        memset( visited , false , sizeof( visited ) );
    }
    return 0;
}

