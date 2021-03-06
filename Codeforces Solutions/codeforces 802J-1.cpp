#include <bits/stdc++.h>
using namespace std;

const int N = 105;
typedef pair <int,int> ii;
vector <ii> graph[N];
bool visited[N];

int dfs(int st) {
    visited[ st ] = true;
    int mx = 0;

    for (int i = 0; i < graph[st].size(); i++) {
        ii n = graph[ st ][ i ];
        int node = n.first;
        int cost = n.second;
        if (!visited[ node ]) {
            mx = max(mx , cost + dfs(node));
        }
    }
    return mx;
}
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= (n-1); i++) {
        int u, v, c;
        scanf("%d%d%d",&u,&v,&c);
        graph[ u ].push_back( {v,c} );
        graph[ v ].push_back( {u,c} );
    }
    printf("%d\n",dfs(0));
    return 0;
}
