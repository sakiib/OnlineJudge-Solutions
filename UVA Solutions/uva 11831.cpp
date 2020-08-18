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

int r , c , q;
char str[ 200 ][ 200 ];
char path[ 50005 ];
int ans;

void solve( int x , int y , int cur ) {
    int len = strlen( path );
    for( int i = 0; i < len; i++ ) {
        if( path[i] == 'D' ) {
            if( cur == 1 ) cur = 3;
            else if( cur == 2 ) cur = 4;
            else if( cur == 3 ) cur = 2;
            else cur = 1;
        }
        else if( path[i] == 'E' ) {
            if( cur == 1 ) cur = 4;
            else if( cur == 2 ) cur = 3;
            else if( cur == 3 ) cur = 1;
            else cur = 2;
        }
        else {
           if( cur == 1 && x-1 >= 0 && str[x-1][y] != '#' ) x --;
           if( cur == 2 && x+1 < r && str[x+1][y] != '#' ) x ++;
           if( cur == 3 && y+1 < c && str[x][y+1] != '#' ) y ++;
           if( cur == 4 && y-1 >= 0 && str[x][y-1] != '#' ) y --;
        }
        if( str[x][y] == '*' ) {
            ans ++;
            str[x][y] = '.';
        }
    }
}
int main( int argc, char const *argv[] ) {
    while( scanf("%d%d%d",&r,&c,&q) ) {
        if( r == 0 && c == 0 && q == 0 ) break;
        for( int i = 0; i < r; i++ ) {
            scanf("%s",str[i]);
        }
        scanf("%s",path);
        bool done = false;
        ans = 0;
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
               if( str[i][j] == 'N' ) done = true , solve( i , j , 1 );
               if( str[i][j] == 'S' ) done = true , solve( i , j , 2 );
               if( str[i][j] == 'L' ) done = true , solve( i , j , 3 );
               if( str[i][j] == 'O' ) done = true , solve( i , j , 4 );
               if( done ) break;
            }
            if( done ) break;
        }
         printf("%d\n",ans);
    }
    return 0;
}

