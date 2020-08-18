#include <bits/stdc++.h>
using namespace std;

struct Node {
        bool endMark;
        int cnt;
        Node *Next[ 10 ];
        Node( ) {
                endMark = false;
                cnt = 0;
                for( int i = 0; i < 10; i++ ) Next[i]= NULL;
        }
} *root;

char s[ 15 ];

void Delete( Node* cur ) {
        for( int i = 0; i < 10; i++ ) {
                if( cur -> Next[i] ) Delete( cur -> Next[i] );
        }
        delete( cur );
}
bool Found( char *s ) {
        int len = strlen( s );
        Node *cur = root;
        for( int i = 0; i < len; i++ ) {
                int id = s[i] - '0';
                if( cur -> Next[id] == NULL ) return false;
                cur = cur -> Next[id];
                if( cur -> cnt > 0 && cur -> endMark ) return true;
        }
        if( cur -> cnt > 0 ) return true;
        return false;
}
void Insert( char *s ) {
        int len = strlen( s );
        Node *cur = root;
        for( int i = 0; i < len; i++ ) {
                int id = s[i] - '0';
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
                cur = cur -> Next[id];
                cur -> cnt++;
        }
        cur -> endMark = true;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                root = new Node( );
                int n;
                scanf("%d",&n);
                bool f = true;
                for( int i = 1; i <= n; i++ ) {
                        scanf("%s",s);
                        if( Found( s ) ) f = false;
                        //if( !f ) cout << i << " " << s << endl;
                        Insert( s );
                }
                if( f ) printf("Case %d: YES\n",tc);
                else printf("Case %d: NO\n",tc);
                Delete( root );
        }
        return 0;
}







