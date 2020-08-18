#include <bits/stdc++.h>
using namespace std;

struct Node {
        bool endMark;
        Node *Next[ 10 ];
        Node( ) {
                endMark = false;
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
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                root = new Node( );
                int n;
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) {
                        scanf("%s",s);

                }
        }
        return 0;
}















