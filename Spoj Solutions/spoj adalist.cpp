#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100005;

int ara[ N ];
vector <int> V;

int main( int argc, char const *argv[] ) {
    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        V.push_back( ara[i] );
    }
    while( q-- ) {
        int op;
        scanf("%d",&op);
        if( op == 1 ) {
            int pos , val;
            scanf("%d %d",&pos,&val);
            V.insert( V.begin()+pos-1 , val );
        }
        else if( op == 2 ) {
            int pos;
            scanf("%d",&pos);
            pos--;
            V.erase( V.begin()+pos , V.begin()+pos+1 );
        }
        else {
            int pos;
            scanf("%d",&pos);
            printf("%d\n",V[pos-1]);
        }
    }
    return 0;
}

