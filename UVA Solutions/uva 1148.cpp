#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

char s[99999];
vector<int> con[100000];
int dis[100000];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      con[i].clear();
    }

    while (N--) {
      int n, a, b;
      scanf("%d%d", &a, &n);
      while (n--) {
        scanf("%d", &b);
        con[a].push_back(b);
        con[b].push_back(a);
      }
    }

    int c1, c2;
    scanf("%d%d", &c1, &c2);
    queue<int> q;
    q.push(c1);
    memset(dis, 0, sizeof(dis));

    while (!q.empty()) {
      int now = q.front();
     // cout<<q.front()<<endl;
      int d = dis[now];
      q.pop();
      if (now == c2) {
        printf("%d %d %d\n", c1, c2, d - 1);
        break;
      }

     for (int i = 0; i < con[now].size(); i++) {
        if (con[now][i] != c1 && !dis[con[now][i]]) {
          dis[con[now][i]] = d + 1;
          q.push(con[now][i]);
        }
      }
    }

    if (T) {
      puts("");
    }
  }

  return 0;
}
