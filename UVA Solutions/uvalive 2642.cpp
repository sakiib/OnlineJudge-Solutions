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

char str[ N ];
vector <string> ans;

struct Node {
    bool Endmark;
    Node* Next[ 30 ];
    Node( ) {
        Endmark = false;
        for( int i = 1; i < 30; i++ ) Next[i] = NULL;
    }
} *Root;

int GetID( char ch ) {
    if( ch >= 'a' && ch <= 'z' ) return ( ch-'a'+1 );
    else if( ch == '-' ) return 27;
    else return 28;
}
void Insert( char *s ) {
    int len = strlen( s );
    Node* cur = Root;
    for( int i = 0; i < len; i++ ) {
        int id = GetID( s[i] );
        if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node();
        cur = cur -> Next[id];
    }
    cur -> Endmark = true;
}
bool Found( char *s ) {
    int len = strlen( s );
    Node* cur = Root;
    for( int i = 0; i < len; i++ ) {
        int id = GetID( s[i] );
        if( cur -> Next[id] == NULL ) return false;
        cur = cur -> Next[id];
    }
    return ( cur -> Endmark );
}
int main( int argc, char const *argv[] ) {

    Root = new Node( );

    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%s",str);
        Insert( str );
    }
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        ans.clear();
        while( true ) {
            scanf("%s",str);
            if( strcmp( str , "-1" ) == 0 ) break;
            if( !Found( str ) ) ans.push_back( str );
        }
        if( ans.size() ) {
            printf("Email %d is not spelled correctly.\n",tc);
            for( int i = 0; i < ans.size(); i++ ) cout << ans[i] << endl;
        }
        else printf("Email %d is spelled correctly.\n",tc);
    }
    cout << "End of Output" << endl;
    return 0;
}
