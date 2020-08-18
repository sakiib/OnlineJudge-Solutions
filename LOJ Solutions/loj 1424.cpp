#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 2e3 + 5;

int nextInt() {
  int x;
  scanf("%d",&x);
  return x;
}
void nextString(char *a) {
  scanf("%s",a);
}

int r, c;
char s[ N ][ N ];
int cnt[ N ][ N ];
int MN[ N ][ 20 ];
int lg[ N ];
vector <int> a;


static const int buf_len = (1 << 14);
static const int buf_max = (1 << 04);
static char buf_out[buf_len];
static char buf_num[buf_max];
static int buf_pos = 0;

inline void writeChar(int x) {
  if (buf_pos == buf_len) fwrite(buf_out, 1, buf_len, stdout), buf_pos = 0;
  buf_out[buf_pos++] = x;
}

inline void writeInt(int x, char end = 0) {
  if (x < 0) writeChar('-'), x = -x;
  int n = 0;
  do buf_num[n++] = x % 10 + '0'; while(x /= 10);
  while (n--) writeChar(buf_num[n]);
  if (end) writeChar(end);
}

struct Flusher{~Flusher(){
  if(buf_pos)fwrite(buf_out, 1, buf_pos, stdout),buf_pos=0;
}}flusher;

void ST( ) {
  for(int i = 1; i <= r; i++) MN[i][0] = a[i];
  for(int i = 2; i <= r; i++) lg[i] = lg[i/2] + 1;
  for (int j = 1; (1 << j) <= r; j++) {
    for (int i = 1; i + (1 << j) - 1 <= r; i++) {
      MN[i][j] = min(MN[i][j - 1], MN[i + (1 << (j-1))][j - 1]);
    }
  }
}
int Query(int l, int r) {
  if (l > r) swap(l, r);
  int k = lg[r - l + 1];
  int mn = min(MN[l][k], MN[r - (1 << k) + 1][k]);
  return mn;
}
int solve() {
  int ret = 1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 0) continue;
    int lo = 0, hi = i, ll = i;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int mn = Query(mid, i);
      if (Query(mid, i) >= a[i]) ll = mid, hi = mid - 1;
      else lo = mid + 1;
    }
    lo = i, hi = a.size() - 1;
    int rr = i;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (Query(i, mid) >= a[i]) rr = mid, lo = mid + 1;
      else hi = mid - 1;
    }
    ret = max(ret, a[i] * (rr - ll + 1));
  }
  return ret;
}
int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    r = nextInt(), c = nextInt();
    for (int i = 0; i < r; i++) nextString(s[i]);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (s[i][j] == '0') {
          cnt[i + 1][j + 1] = cnt[i + 1][j] + 1;
        }
        else cnt[i + 1][j + 1] = 0;
      }
    }
    int mx = 0;
    for (int i = 1; i <= c; i++) {
      a.clear();
      a.push_back(0);
      for (int j = 1; j <= r; j++) {
        a.push_back(cnt[j][i]);
      }
      ST();
      mx = max(mx, solve());
    }
    writeChar('C'); writeChar('a'); writeChar('s'); writeChar('e');
    writeChar(' ');
    writeInt(tc);
    writeChar(':'); writeChar(' ');
    writeInt(mx);
    writeChar('\n');
    //printf("Case %d: %d\n", tc, mx);
  }
  return 0;
}

