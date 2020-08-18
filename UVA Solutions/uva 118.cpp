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

bool scent[ 60 ][ 60 ];
int r , c , x , y;
char ch;
char path[ 500 ];

int main( int argc, char const *argv[] ) {
    scanf("%d%d",&r,&c);
    while( scanf("%d%d %c",&x,&y,&ch)!=EOF ) {
        scanf("%s",path);
        int dir = 0;
        if( ch == 'N' ) dir = 0;
        else if( ch == 'E' ) dir = 1;
        else if( ch == 'S' ) dir = 2;
        else dir = 3;
        bool f = false;
        int len = strlen( path );
        for( int i = 0; i < len && !f ; i++ ) {
            if( path[i] == 'L' ) dir = (dir+3)%4;
            else if( path[i] == 'R' ) dir = (dir+1)%4;
            else {
                if( dir == 0 ) y ++;
                else if( dir == 1 ) x ++;
                else if( dir == 2 ) y --;
                else if( dir == 3 ) x --;
                if( x > r ) {
                    if( !scent[x-1][y] ) {
                        scent[x-1][y] = true;
                        f = true;
                    }
                    x --;
                }
                else if( x < 0 ) {
                    if( !scent[x+1][y] ) {
                        scent[x+1][y] = true;
                        f = true;
                    }
                    x ++;
                }
                else if( y > c ) {
                    if( !scent[x][y-1] ) {
                        scent[x][y-1] = true;
                        f = true;
                    }
                    y --;
                }
                else if( y < 0 ) {
                    if( !scent[x][y+1] ) {
                        scent[x][y+1] = true;
                        f = true;
                    }
                    y++;
                }
            }
        }
        printf("%d %d ",x,y);
        if( dir == 0 ) printf("N");
        else if( dir == 1 ) printf("E");
        else if( dir == 2 ) printf("S");
        else printf("W");
        if( f ) printf(" LOST");
        printf("\n");
    }
    return 0;
}

