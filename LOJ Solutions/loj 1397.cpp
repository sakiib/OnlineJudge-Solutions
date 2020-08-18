#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}

const int r = 9;
const int c = 9;
const int inf = 1e9;

char s[ r + 1 ][ c + 1 ];
int board[ r + 1][c + 1];
pair <int,int> start[r + 1][c + 1];

void print_sudoku( ) {
        printf("** sudoku solver **\n\n");
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        printf("%d ",board[i][j]);
                }
                printf("\n");
        }
        printf("\n*****************\n\n");
}
void calc_start( ) {
        for( int i = 1; i <= r; i += 3 ) {
                for( int j = 1; j <= c; j += 3 ) {
                        vector <int> cnt( 10 , 0 );
                        for( int k = i; k <= i + 2; k++ ) {
                                for( int l = j; l <= j + 2; l++ ) {
                                        start[k][l] = make_pair( i , j );
                                }
                        }
                }
        }
}
vector <int> get_available( int cr , int cc ) {
        vector <int> have( 10 , 0 );
        vector <int> ret;
        for( int j = 1; j <= c; j++ ) have[ board[cr][j] ]++;
        for( int i = 1; i <= r; i++ ) have[ board[i][cc] ]++;
        pair <int,int> p = start[cr][cc];
        for( int k = p.first; k <= p.first + 2; k++ ) {
                for( int l = p.second; l <= p.second + 2; l++ ) {
                        have[ board[k][l] ]++;
                }
        }
        for( int i = 1; i <= 10; i++ ) if( have[i] == 0 ) ret.push_back( i );
        return ret;
}
bool conflict( ) {
        for( int i = 1; i <= r; i++ ) {
                vector <int> cnt( 10 , 0 );
                for( int j = 1; j <= c; j++ ) {
                        cnt[ board[i][j] ]++;
                        if( board[i][j] != 0 && cnt[ board[i][j] ] > 1 ) return true;
                }
        }
        for( int i = 1; i <= c; i++ ) {
                vector <int> cnt( 10 , 0 );
                for( int j = 1; j <= r; j++ ) {
                        cnt[ board[j][i] ]++;
                        if( board[j][i] != 0 && cnt[ board[j][i] ] > 1 ) return true;
                }
        }
        for( int i = 1; i <= r; i += 3 ) {
                for( int j = 1; j <= c; j += 3 ) {
                        vector <int> cnt( 10 , 0 );
                        for( int k = i; k <= i + 2; k++ ) {
                                for( int l = j; l <= j + 2; l++ ) {
                                        cnt[ board[k][l] ]++;
                                        if( board[k][l] != 0 && cnt[ board[k][l] ] > 1 ) return true;
                                }
                        }
                }
        }
        return false;
}
pair <int,int> get_da_best( ) {
        pair <int,int> ret = make_pair( -1 , -1 );
        int mn = inf;
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        if( board[i][j] != 0 ) continue;
                        vector <int> can = get_available( i , j );
                        if( can.size() < mn ) mn = can.size() , ret = make_pair( i , j );
                }
        }
        return ret;
}
bool sudoku_solver( int rem ) {
        if( rem == 0 ) return conflict( ) ? false : true;
        bool ret = false;
        pair <int,int> p = get_da_best( );
        int x = p.first , y = p.second;
        if( x == -1 && y == -1 ) return true;
        if( board[x][y] != 0 ) ret |= sudoku_solver( rem );
        else {
                vector <int> can = get_available( x , y );
                for( int i = 0; i < can.size(); i++ ) {
                        board[x][y] = can[i];
                        ret |= sudoku_solver( rem - 1 );
                        if( ret ) break;
                        else board[x][y] = 0;
                }
        }
        return ret;
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
            //freopen( "output.txt" , "w" , stdout );
        #endif // LOCAL
        calc_start( );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                for( int i = 0; i < r; i++ ) {
                        scanf("%s",s[i]);
                }
                int cnt = 0;
                for( int i = 0; i < r; i++ ) {
                        for( int j = 0; j < c; j++ ) {
                                if( s[i][j] == '.' ) board[i + 1][j + 1] = 0 , cnt++;
                                else board[i + 1][j + 1] = ( s[i][j] - '0' );
                        }
                }
                printf("Case %d:\n",tc);
                if( sudoku_solver( cnt ) ) {
                        for( int i = 1; i <= r; i++ ) {
                                for( int j = 1; j <= c; j++ ) {
                                        printf("%d",board[i][j]);
                                }
                                printf("\n");
                        }
                }
                else assert( false );
        }
        return 0;
}








