#include <bits/stdc++.h>
using namespace std;

int r , c;
string s[ 30 ];
int sx , sy , ex , ey;

const int dx[] = { 1 , -1 , 0 , 0 };
const int dy[] = { 0 , 0 , 1 , -1 };
bool vis[ 30 ][ 30 ][ 6 ][ 6 ];

struct cell {
        int x , y , dir , col , cost;
        cell( ){}
        cell( int _x , int _y , int _dir , int _col , int _cost ) {
                x = _x , y = _y , dir = _dir , col = _col , cost = _cost;
        }
};

bool valid( int nx , int ny ) {
        return nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] != '#';
}
int bfs( ) {
        memset( vis , false , sizeof( vis ) );
        cell s = {sx,sy,1,1,0};
        queue <cell> Q;
        Q.push( s );
        while( !Q.empty() ) {
                cell f = Q.front(); Q.pop();
                int px = f.x , py = f.y , pdir = f.dir , pcol = f.col , pcost = f.cost;
                if( px == ex && py == ey && pcol == 1 ) return pcost;
                if( vis[px][py][pdir][pcol] ) continue;
                vis[px][py][pdir][pcol] = 1;
                if( pdir == 1 ) {
                        Q.push( cell( px , py , 2 , pcol , pcost + 1 ) );
                        Q.push( cell( px , py , 4 , pcol , pcost + 1 ) );
                }
                if( pdir == 2 ) {
                        Q.push( cell( px , py , 3 , pcol , pcost + 1 ) );
                        Q.push( cell( px , py , 1 , pcol , pcost + 1 ) );
                }
                if( pdir == 3 ) {
                        Q.push( cell( px , py , 2 , pcol , pcost + 1 ) );
                        Q.push( cell( px , py , 4 , pcol , pcost + 1 ) );
                }
                if( pdir == 4 ) {
                        Q.push( cell( px , py , 1 , pcol , pcost + 1 ) );
                        Q.push( cell( px , py , 3 , pcol , pcost + 1 ) );
                }
                if( pdir == 1 ) {
                        int ccol = pcol + 1;
                        if( ccol > 5 ) ccol = 1;
                        if( valid( px - 1 , py ) ) Q.push( cell( px - 1 , py , pdir , ccol , pcost + 1 ) );
                }
                if( pdir == 2 ) {
                        int ccol = pcol + 1;
                        if( ccol > 5 ) ccol = 1;
                        if( valid( px , py + 1 ) ) Q.push( cell( px , py + 1 , pdir , ccol , pcost + 1 ) );
                }
                if( pdir == 3 ) {
                        int ccol = pcol + 1;
                        if( ccol > 5 ) ccol = 1;
                        if( valid( px + 1 , py ) ) Q.push( cell( px + 1 , py , pdir , ccol , pcost + 1 ) );
                }
                if( pdir == 4 ) {
                        int ccol = pcol + 1;
                        if( ccol > 5 ) ccol = 1;
                        if( valid( px , py - 1 ) ) Q.push( cell( px , py - 1 , pdir , ccol , pcost + 1 ) );
                }
        }
        return -1;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        //freopen( "input.txt" , "r" ,stdin );
        //freopen( "output.txt" , "w" ,stdout );
        int tc = 0;
        while( cin >> r >> c ) {
                if( r == 0 && c == 0 ) break;
                if( tc ) cout << endl;
                for( int i = 0; i < r; i++ ) cin >> s[i];
                for( int i = 0; i < r; i++ ) {
                        for( int j = 0; j < c; j++ ) {
                                if( s[i][j] == 'S' ) sx = i , sy = j;
                                if( s[i][j] == 'T' ) ex = i , ey = j;
                        }
                }
                int mn = bfs( );
                cout << "Case " << "#" << ++tc << endl;
                if( mn == -1 ) cout << "destination not reachable" << endl;
                else cout << "minimum time = " << mn << " sec" << endl;
        }
        return 0;
}










