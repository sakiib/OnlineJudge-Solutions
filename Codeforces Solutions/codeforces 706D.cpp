#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;

/**
i. insert a number
ii. delete a number
iii. find max_xor for a given number from the current set
*/

struct node {
  int cnt;
  node* nxt[2];
  node() {
    cnt = 0;
    nxt[0] = NULL, nxt[1] = NULL;
  }
}*root;

template <typename T> class trie_numeric {
public:
  int mx_bit = -1;
  trie_numeric(int sz) {
    mx_bit = sz;
    root = new node();
  }
  inline bool check(T n, int pos) {
    return (bool)(n&(1LL << pos));
  }
  inline T on(T n, int pos) {
    return n |= (1LL << pos);
  }
  inline void del(node* cur) {
    for (int i = 0; i < 2; i++) {
      if (cur -> nxt[i]) del(cur -> nxt[i]);
    }
    delete(cur);
  }
  inline void insert(T num) {
    node *cur = root;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id] == NULL) {
        cur -> nxt[id] = new node();
      }
      cur = cur -> nxt[id];
      cur -> cnt++;
    }
  }
  inline void remove(T num) {
    node *cur = root;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      assert(cur -> nxt[id] != NULL);
      cur = cur -> nxt[id];
      cur -> cnt--;
    }
  }
  inline T maxxor(T num) {
    node *cur = root;
    T ans = 0;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id^1] != NULL && cur -> nxt[id^1] -> cnt) {
        ans = on(ans, i);
        cur = cur -> nxt[id^1];
      }
      else if (cur -> nxt[id] != NULL && cur -> nxt[id] -> cnt) {
        cur = cur -> nxt[id];
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  root = new node();
  trie_numeric <long long> tr(31);
  tr.insert(0);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int val;
    cin >> val;
    if (s == "+") tr.insert(val);
    if (s == "-") tr.remove(val);
    if (s == "?") cout << tr.maxxor(val) << endl;
  }
  return 0;
}

