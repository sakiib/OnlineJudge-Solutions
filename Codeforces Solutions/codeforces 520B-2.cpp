#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int cost[N];
int n, m, ans, mx = 20000;

void bfs() {
    queue <int> Q;
    Q.push(n);
    memset(cost , -1 , sizeof(cost));
    cost[n] = 0;
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        if (t == m) return;
        int op1 = t*2;
        int op2 = t-1;
        if (op1 <= mx) {
            if (cost[op1] == -1 || (cost[op1] > cost[t]+1))
                cost[op1] = cost[t]+1 , Q.push(op1);
        }
        if (op2 >= 0) {
            if (cost[op2] == -1 || (cost[op2] > cost[t]+1))
                cost[op2] = cost[t]+1 , Q.push(op2);
        }
    }
}
int main(int argc, char const *argv[]) {
    scanf("%d%d",&n,&m);
    bfs();
    printf("%d\n",cost[m]);
    return 0;
}
