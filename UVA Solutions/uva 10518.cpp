#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Node {
        bool Endmark;
        Node* Next[3];
        Node( ) {
                Endmark = false;
                Next[0] = Next[1] = Next[2] = NULL;
    }
} *Root;

char str[ 6*N ];
bool ok;

void Insert( char* s) {
        Node* cur = Root;
        int len = strlen( s );
        for( int i = 0; i < len; i++ ) {
                int id = s[i]-'a';
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
                cur = cur -> Next[id];
        }
        cur -> Endmark = true;
}
bool Search( char *s , Node* cur , int bad , int pos , int len ) {
        int id = s[pos]-'a';
        bool ok = false;
        if( pos >= len ) {
                if( bad == 1 && cur -> Endmark ) return true;
                return false;
        }
        if( bad > 1 ) return false;;
        for( int i = 0; i <= 2; i++ ) {
            if( cur -> Next[i] != NULL && cur -> Next[i] == cur -> Next[id] ) {
                    ok |= Search( s , cur -> Next[i] , bad , pos+1 , len );
            }
            else if( cur -> Next[i] != NULL ) {
                    ok |= Search( s , cur -> Next[i] , bad+1 , pos+1 , len );
            }
        }
        return ok;
}
int main( int argc, char const *argv[] ) {

        Root = new Node( );

        int n , m;
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= n; i++ ) {
                scanf("%s",str);
                Insert( str );
        }
        while( m-- ) {
                scanf("%s",str);
                ok = false;
                if( Search( str , Root ,  0 , 0 , strlen(str) ) ) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}






