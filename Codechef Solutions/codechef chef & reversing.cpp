#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> ii;
const int inf = 100000000;
const int N = 100005;
int cost[ N ], n, e;
vector <ii> graph[ N ];

priority_queue< ii, vector< ii >, greater< ii > > Q;

void dijkstra() {
    cost[ 1 ] = 0;
    Q.push( {cost[ 1 ], 1});

    while(!Q.empty()) {
        ii t = Q.top();
        Q.pop();
        int c = t.first;
        int s = t.second;
        for(int i = 0; i < graph[ s ].size(); i++) {
            ii next = graph[ s ][ i ];
            int cos = next.second;
            int sou = next.first;
            if(cost[ sou ] == inf || (cost[ sou ] > cost[ s ]+cos)) {
                cost[ sou ] = cost[ s ]+cos;
                Q.push( {cost[sou], sou});
            }
        }
    }
}
void reset() {
    for(int i = 1; i <= n; i++) cost[i] = inf;
}
int main(int argc, char const *argv[]) {
    scanf("%d%d",&n,&e);
    for(int i = 1; i <= e; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        graph[ u ].push_back( {v,0} );
        graph[ v ].push_back( {u,1} );
    }
    reset();
    dijkstra();
    cout<<(cost[ n ] == inf ? -1 : cost[ n ])<<endl;
    return 0;
}
