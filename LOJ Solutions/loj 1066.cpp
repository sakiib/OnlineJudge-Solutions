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

int n;
char str[ 100 ][ 100 ];
int tot;
int sx , sy , ex , ey;
int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };
int cost[ 100 ][ 100 ];
bool visited[ 100 ][ 100 ];

bool valid( int nx , int ny , char c ) {
    return ( nx >= 0 && ny >= 0 && nx < n && ny < n && (str[nx][ny]=='.'||str[nx][ny]!='#'&&str[nx][ny]<=c) );
}
void process( ) {
    for( int i = 0; i <= 20; i++ ) {
        for( int j = 0; j <= 20; j++ ) {
            cost[i][j] = inf;
        }
    }
}

int cnt;
int ta , tb;

int bfs( int x , int y , char ch ) {
    process();
    cost[x][y] = 0;
    queue <ii> Q;
    Q.push( {x,y} );
    bool flag = false;
    while( !Q.empty( ) ) {
        ii f = Q.front(); Q.pop();
        int a = f.first;
        int b = f.second;
        if( str[a][b] == ch ) {
            flag = true;
            ta = a , tb = b;
            //cout << "------ in -------" << endl;
            cnt++;
        }
        for( int i = 0; i < 4; i++ ) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if( valid( nx , ny , ch ) && (cost[nx][ny] == inf || cost[nx][ny] > cost[a][b]+1) ) {
                cost[nx][ny] = cost[a][b]+1;
                Q.push({nx,ny});
            }
        }
    }
    if( flag ) return cost[sx][sy];
    else return -1;
}
int main( int argc, char const *argv[] ) {
    freopen( "input.txt" , "r" , stdin );
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d",&n);
        for( int i = 0; i < n; i++ ) {
            scanf("%s",str[i]);
        }
        int mx = 0;
        tot = 0;
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( str[i][j] == 'A' ) sx = i , sy = j;
                if( str[i][j] >= 'A' && str[i][j] <= 'Z' ) tot++;
            }
        }
        bool f = true;
        int ans = 0;
        int ways = 1;
        for( int i = 1; i < tot; i++ ) {
            cnt = 0;
            cout << sx << " " << sy << endl;
            int got = bfs( sx , sy , 'A'+i );
            if( got == -1 ) {
                f = false; break;
            }
            else sx = ta , sy = tb , ways *= cnt , ans += got;
        }
        if( f ) {
                printf("Case %d: %d %d\n",tc,ans,ways );
        }
        else printf("Case %d: Impossible\n",tc);
    }
    return 0;
}
