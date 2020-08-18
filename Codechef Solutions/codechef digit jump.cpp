#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
string str;
int cost[ N ];
int len;
vector <int> pos[ N ];

void bfs() {
    queue <int> Q;
    Q.push( 0 );
    memset(cost, -1, sizeof(cost));
    cost[ 0 ] = 0;

    while(!Q.empty()) {
        int f = Q.front();
        Q.pop();

        if(f == len) return;

        if(f-1 >= 0 ) {
            if(cost[ f-1 ] == -1 || (cost[ f-1 ] > cost[ f ]+1)) {
                Q.push( f -1 );
                cost[ f-1 ] = cost[ f ]+1;
            }
        }
        if(f+1 <= len) {
            if(cost[ f+1 ] == -1 || (cost[ f+1 ] > cost[ f ]+1)) {
                Q.push( f +1 );
                cost[ f+1 ] = cost[ f ]+1;
            }
        }
        int val = str[ f ]-'0';
        for(int i = 0; i < pos[ val ].size(); i++) {
            int next = pos[ val ][ i ];
            if(cost[ next ] == -1 ||(cost[ next ] > cost[ f ]+1)) {
                cost[ next ] = cost[ f ]+1;
                Q.push( next );
            }
        }
        pos[ val ].clear();
    }
}
int main(int argc, char const *argv[]) {
    cin >> str;
    len = str.size()-1;

    for(int i = 0; i < str.size(); i++) {
        pos[ str[i]-'0' ].push_back( i );
    }
    bfs();
    printf("%d\n",cost[ len ]);
    return 0;
}
