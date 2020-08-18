#include <bits/stdc++.h>
using namespace std;

const int N = 100;

char s[ N ];
int len;
int dp[51][5][5];
int pp[51][5][5];

bool vow(char ch) {
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
int bad(int idx, int v, int c) {
    if (v >= 3 || c >= 5) return 1;
    if (idx >= len) return 0;
    if (dp[idx][v][c] != -1) return dp[idx][v][c];
    int ret = 0;
    if (s[idx] == '?') ret |= bad(idx + 1, 0, 0);
    else ret |= bad(idx + 1, vow(s[idx]) ? v + 1 : 0, !vow(s[idx]) ? c + 1 : 0);
    return dp[idx][v][c] = ret;
}
bool can(int idx, int v, int c) {
    if (v >= 3 || c >= 5) return 1;
    if (idx >= len) return 0;
    if (pp[idx][v][c] != -1) return pp[idx][v][c];
    int ret = 0;
    if (s[idx] == '?') {
        ret |= can(idx + 1, v + 1, 0);
        ret |= can(idx + 1, 0, c + 1);
    }
    else ret |= can(idx + 1, vow(s[idx]) ? v + 1 : 0, !vow(s[idx]) ? c + 1 : 0);
    return pp[idx][v][c] = ret;
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    scanf("%d",&t);
    for (int tc = 1; tc <= t; tc++) {
        scanf("%s",s);
        len = strlen(s);
        memset(dp, -1, sizeof(dp));
        memset(pp, -1, sizeof(pp));
        printf("Case %d: ",tc);
        if(can(0, 0, 0)) printf("BAD\n");
        else if(bad(0, 0, 0)) printf("BAD\n");
        else printf("GOOD\n");
    }
    return 0;
}







